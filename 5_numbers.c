/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_numbers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:21:52 by rloos             #+#    #+#             */
/*   Updated: 2023/02/10 16:21:59 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_min(int *stack_a, int *size_a)
{
	int	i;
	int	index;
	int	minimal;

	i = 0;
	index = 0;
	minimal = stack_a[0];
	while (i < *size_a)
	{
		if (minimal > stack_a[i])
		{
			minimal = stack_a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	prep_min_a(int *stack_a, int *size_a, int size)
{
	int	min;

	min = find_min(stack_a, size_a);
	if (min <= size / 2)
	{
		while (min != 0)
		{
			rotate_a(stack_a, size_a, 0);
			min--;
		}
	}
	else if (min > size / 2)
	{
		while (min != size)
		{
			reverse_rotate_a(stack_a, size_a, 0);
			min++;
		}
	}
	return (0);
}

void	five_numbers(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	prep_min_a(stack_a, size_a, 5);
	push_b(stack_a, stack_b, size_a, size_b);
	prep_min_a(stack_a, size_a, 4);
	push_b(stack_a, stack_b, size_a, size_b);
	three_numbers(stack_a, size_a);
	push_a(stack_a, stack_b, size_a, size_b);
	push_a(stack_a, stack_b, size_a, size_b);
}
