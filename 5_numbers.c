
#include "pushswap.h"

int five_numbers(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    push_index(stack_a, size_a);
    push_b(stack_a, stack_b, size_a, size_b);
    four_numbers(stack_a, stack_b, size_a, size_b);
    push_a(stack_a, stack_b, size_a, size_b);

    return (0);
}
