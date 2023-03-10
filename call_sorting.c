/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:23:07 by rloos             #+#    #+#             */
/*   Updated: 2023/02/10 16:23:18 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	call_sorting(int *stack_a, int *stack_b, int *size_b, int *size_a)
{
	if (*size_a == 2)
		two_numbers(stack_a, size_a);
	else if (*size_a == 3)
		three_numbers(stack_a, size_a);
	else if (*size_a == 4)
		four_numbers(stack_a, stack_b, size_a, size_b);
	else if (*size_a == 5)
		five_numbers(stack_a, stack_b, size_a, size_b);
	else if (*size_a > 5)
		radix_hub(stack_a, stack_b, size_a, size_b);
	return (0);
}
