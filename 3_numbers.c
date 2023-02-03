
#include "pushswap.h"

int	three_numbers(int *stack_a, int *size_a)
{
	if ((stack_a[0] < stack_a[2]) && (stack_a[1] > stack_a[2]))
	{
		reverse_rotate_a(stack_a, size_a, 0);
		swap_a(stack_a, size_a, 0);
	}
	else if ((stack_a[0] > stack_a[1]) && (stack_a[0] < stack_a[2]))
		swap_a(stack_a, size_a, 0);
	else if ((stack_a[0] > stack_a[1]) && (stack_a[1] > stack_a[2]))
	{
		rotate_a(stack_a, size_a, 0);
		swap_a(stack_a, size_a, 0);
	}
	else if ((stack_a[0] < stack_a[1]) && (stack_a[1] > stack_a[2]))
		reverse_rotate_a(stack_a, size_a, 0);
	else if ((stack_a[0] > stack_a[1]) && (stack_a[1] < stack_a[2]))
		rotate_a(stack_a, size_a, 0);
	return (0);
}
