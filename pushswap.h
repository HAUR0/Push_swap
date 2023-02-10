/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:56:54 by rloos             #+#    #+#             */
/*   Updated: 2023/02/10 16:57:01 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "./libft/libft.h"

void	swap_a(int *stack_a, int *size_a, int print_condition);
void	swap_b(int *stack_b, int *size_b, int print_condition);
void	swap_a_and_b(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	push_a(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	push_b(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	rotate_a(int *stack_a, int *size_a, int print_condition);
void	rotate_b(int *stack_b, int *size_b, int print_condition);
void	rotate_a_and_b(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	reverse_rotate_a(int *stack_a, int *size_a, int print_condition);
void	reverse_rotate_b(int *stack_b, int *size_b, int print_condition);
void	reverse_rotate_a_and_b(int *stack_a, int *stack_b, int *size_a,
			int *size_b);

void	array_printer(int *arr, int *size_a);
void	safe_exit(int error, int *array);
void	sorted_input(int *les_variables, int *size_a, int *stack_b);
void	char_input_check(char **arr);
int		check_for_doubles(int *stack_a, int *stack_b, int *size_a);
int		get_malloc_size(int ac, char **av);
int		*meloc(int counter);
void	argument_reader(int ac, char **av, int *stack_a, int counter);
int		call_sorting(int *stack_a, int *stack_b, int *size_b, int *size_a);

int		two_numbers(int *stack_a, int *size_a);
int		three_numbers(int *stack_a, int *size_a);
int		four_numbers(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	five_numbers(int *stack_a, int *stack_b, int *size_a, int *size_b);
int		push_index(int *stack_a, int *size_a);
int		find_minimal(int *stack_a, int *size_a);
void	free_2d_array(char **str);

void	array_cpy(int *stack_a, int *sorted_stack, int *size_a);
void	pre_sorter(int *sorted_stack, int *size_a);
void	re_indexing(int *stack_a, int *sorted_stack, int *size_a);
int		all_sorted(int *stack_a, int *size_a);
int		retiks(int *stack_a, int *stack_b, int *size_a, int *size_b);

int		radix_hub(int *stack_a, int *stack_b, int *size_a, int *size_b);

#endif
