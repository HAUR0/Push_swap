
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

void safe_exit(int error, int *array);
int call_sorting(int *stack_a, int *stack_b, int *size_b, int *size_a);
int	two_numbers(int *stack_a, int *size_a);
int	three_numbers(int *stack_a, int *size_a);
int	four_numbers(int *stack_a, int *stack_b, int *size_a, int *size_b);
int five_numbers(int *stack_a, int *stack_b, int *size_a, int *size_b);
int push_index(int *stack_a, int *size_a);
int find_minimal(int *stack_a,int *size_a);

int six_numbers(int *stack_a, int *stack_b, int *size_a, int *size_b);
void free_array(char **s);


void array_printer(int *arr, int *size_a);

#endif
