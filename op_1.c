/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:24:22 by rloos             #+#    #+#             */
/*   Updated: 2023/02/10 16:24:33 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(int *stack_a, int *size_a, int print_condition)
{
	int	tmp;

	if (*size_a >= 2)
	{
		tmp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = tmp;
		if (print_condition == 0)
			ft_printf("sa\n");
	}
}

void	swap_b(int *stack_b, int *size_b, int print_condition)
{
	int	tmp;

	if (*size_b >= 2)
	{
		tmp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = tmp;
		if (print_condition == 0)
			ft_printf("sb\n");
	}
}

void	swap_a_and_b(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	swap_a(stack_a, size_a, 1);
	swap_b(stack_b, size_b, 1);
	ft_printf("ss\n");
}
