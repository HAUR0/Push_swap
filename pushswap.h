
#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "./libft/libft.h"

void swap_a(int *stack_a, int *size_a, int print_condition);
void swap_b(int *stack_b, int *size_b, int print_condition);
void swap_a_and_b(int *stack_a, int *stack_b, int *size_a, int *size_b);
void push_a(int *stack_a, int* stack_b, int *size_a, int *size_b);
void push_b(int *stack_a, int* stack_b, int *size_a, int *size_b);
void rotate_a(int *stack_a, int *size_a, int print_condition);
void rotate_b(int *stack_b, int *size_b, int print_condition);
void rotate_a_and_b(int *stack_a, int* stack_b, int *size_a, int *size_b);
void reverse_rotate_a(int *stack_a, int *size_a, int print_condition);
void reverse_rotate_b(int *stack_b, int *size_b, int print_condition);
void reverse_rotate_a_and_b(int *stack_a, int *stack_b, int *size_a, int *size_b);

#endif
