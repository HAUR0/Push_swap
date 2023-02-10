/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:25:15 by rloos             #+#    #+#             */
/*   Updated: 2023/02/10 16:25:24 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	array_cpy(int *stack_a, int *sorted_stack, int *size_a)
{
	int	i;

	i = 0;
	while (i < *size_a)
	{
		sorted_stack[i] = stack_a[i];
		i++;
	}
	sorted_stack[i] = '\0';
}

void	pre_sorter(int *sorted_stack, int *size_a)
{
	int	i;
	int	x;
	int	tmp;

	x = 0;
	while (x < *size_a - 1)
	{
		i = 0;
		while (i < *size_a - 1 - x)
		{
			if (sorted_stack[i] > sorted_stack[i + 1])
			{
				tmp = sorted_stack[i];
				sorted_stack[i] = sorted_stack[i + 1];
				sorted_stack[i + 1] = tmp;
			}
			i++;
		}
		x++;
	}
}

void	re_indexing(int *stack_a, int *sorted_stack, int *size_a)
{
	int	i;
	int	x;

	i = 0;
	while (i < *size_a)
	{
		x = 0;
		while (i < *size_a)
		{
			if (stack_a[i] == sorted_stack[x])
			{
				stack_a[i] = x;
				break ;
			}
			x++;
		}
		i++;
	}
}

int	all_sorted(int *stack_a, int *size_a)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i < *size_a)
	{
		if (stack_a[i] < stack_a[i + 1])
			x++;
		i++;
	}
	if (x == *size_a - 1)
		return (1);
	return (0);
}

int	retiks(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	i;
	int	x;
	int	s;

	i = 0;
	s = *size_a;
	while (i < 31)
	{
		x = 0;
		while (x < s)
		{
			if ((stack_a[0] >> i) & 1)
				rotate_a(stack_a, size_a, 0);
			else
				push_b(stack_a, stack_b, size_a, size_b);
			x++;
		}
		while (*size_b != 0)
			push_a(stack_a, stack_b, size_a, size_b);
		if (all_sorted(stack_a, size_a) == 1)
			break ;
		i++;
	}
	return (0);
}
