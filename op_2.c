/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:24:40 by rloos             #+#    #+#             */
/*   Updated: 2023/02/10 16:24:46 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_a(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	tmp;

	if (*size_b > 0)
	{
		tmp = stack_b[0];
		rotate_b(stack_b, size_b, 1);
		*size_b -= 1;
		*size_a += 1;
		stack_a[*size_a - 1] = tmp;
		reverse_rotate_a(stack_a, size_a, 1);
		ft_printf("pa\n");
	}
}

void	push_b(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	tmp;

	if (*size_a > 0)
	{
		tmp = stack_a[0];
		rotate_a(stack_a, size_a, 1);
		*size_a -= 1;
		*size_b += 1;
		stack_b[*size_b - 1] = tmp;
		reverse_rotate_b(stack_b, size_b, 1);
		ft_printf("pb\n");
	}
}

void	rotate_a(int *stack_a, int *size_a, int print_condition)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack_a[0];
	while (i < *size_a - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = tmp;
	if (print_condition == 0)
		ft_printf("ra\n");
}

void	rotate_b(int *stack_b, int *size_b, int print_condition)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack_b[0];
	while (i < *size_b - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i] = tmp;
	if (print_condition == 0)
		ft_printf("rb\n");
}

void	rotate_a_and_b(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	rotate_a(stack_a, size_a, 1);
	rotate_b(stack_b, size_b, 1);
	ft_printf("rr\n");
}
