
#include "pushswap.h"

void reverse_rotate_a(int *stack_a, int *size_a, int print_condition)
{
    int i;
    int tmp;

    i = *size_a - 1;
    tmp = stack_a[i];
    while(i > 0)
    {
        stack_a[i] = stack_a[i-1];
        i--;
    }
    stack_a[0] = tmp;
    if(print_condition == 0)
        ft_printf("rra\n");
}

void reverse_rotate_b(int *stack_b, int *size_b, int print_condition)
{
    int i;
    int tmp;

    i = *size_b - 1;
    tmp = stack_b[i];
    while(i > 0)
    {
        stack_b[i] = stack_b[i-1];
        i--;
    }
    stack_b[0] = tmp;
    if(print_condition == 0)
        ft_printf("rrb\n");
}

void reverse_rotate_a_and_b(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    reverse_rotate_a(stack_a, size_a, 1);
    reverse_rotate_b(stack_b, size_b, 1);
    ft_printf("rrr\n");
}
