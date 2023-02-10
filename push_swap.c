/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:45:20 by rloos             #+#    #+#             */
/*   Updated: 2023/02/10 16:41:47 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;

	size_b = 0;
	size_a = (get_malloc_size(ac, av));
	stack_a = meloc(size_a);
	argument_reader(ac, av, stack_a, size_a);
	stack_b = meloc(size_a);
	sorted_input(stack_a, &size_a, stack_b);
	check_for_doubles(stack_a, stack_b, &size_a);
	call_sorting(stack_a, stack_b, &size_b, &size_a);
	free(stack_b);
	free(stack_a);
	return (0);
}
