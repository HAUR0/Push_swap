/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_numbers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:19:05 by rloos             #+#    #+#             */
/*   Updated: 2023/02/10 16:19:14 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	two_numbers(int *stack_a, int *size_a)
{
	if (stack_a[0] > stack_a[1])
		swap_a(stack_a, size_a, 0);
	return (0);
}

void	array_printer(int *arr, int *size_a)
{
	int	i;

	i = 0;
	if (arr[0] == 0)
	{
		ft_printf("Array[0] = 0\n");
		i = 1;
	}
	while (i < *size_a)
	{
		ft_printf("Array[%i] = %d\n", i, arr[i]);
		i++;
	}
}
