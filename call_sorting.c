
#include "pushswap.h"

int call_sorting(int *stack_a, int *stack_b, int *size_b, int *size_a)
{
    
    if      (*size_a == 2)
    {
        two_numbers(stack_a, size_a);
    	printf("%d\n", *size_a);
	    printf("%d\n", *size_b);
    }
    else if (*size_a == 3)
    {
        three_numbers(stack_a, size_a);
        printf("%d\n", *size_a);
	    printf("%d\n", *size_b);
    }
    else if (*size_a == 4)
        four_numbers(stack_a, stack_b, size_a, size_b);
    else if (*size_a == 5)
        five_numbers(stack_a, stack_b, size_a, size_b);
    else if (*size_a > 5 && *size_a < 100)
        six_numbers(stack_a, stack_b, size_a, size_b);
        
    return (0);
}
