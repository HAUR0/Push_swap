/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_numbers_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:22:30 by rloos             #+#    #+#             */
/*   Updated: 2023/02/10 16:22:35 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	radix_hub(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	*sorted_stack;

	sorted_stack = (int *)malloc(sizeof(int) * (*size_a + 1));
	if (!sorted_stack)
		safe_exit(2, sorted_stack);
	array_cpy(stack_a, sorted_stack, size_a);
	pre_sorter(sorted_stack, size_a);
	re_indexing(stack_a, sorted_stack, size_a);
	retiks(stack_a, stack_b, size_a, size_b);
	free(sorted_stack);
	return (0);
}
