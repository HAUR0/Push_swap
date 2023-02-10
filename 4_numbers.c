/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_numbers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:21:36 by rloos             #+#    #+#             */
/*   Updated: 2023/02/10 16:21:44 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_minimal(int *stack_a, int *size_a)
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

int	push_index(int *stack_a, int *size_a)
{
	int	index;

	index = find_minimal(stack_a, size_a);
	while (index > 0)
	{
		rotate_a(stack_a, size_a, 0);
		index--;
	}
	return (0);
}

int	four_numbers(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	push_index(stack_a, size_a);
	push_b(stack_a, stack_b, size_a, size_b);
	three_numbers(stack_a, size_a);
	push_a(stack_a, stack_b, size_a, size_b);
	return (0);
}
