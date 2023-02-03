
#include "pushswap.h"

void array_cpy(int *stack_a, int *sorted_stack, int *size_a)
{
    int i;

    i = 0;
    while(i < *size_a)
    {
        sorted_stack[i] = stack_a[i];
        i++;
    }
    sorted_stack[i] = '\0';
}

void pre_sorter(int *sorted_stack, int *size_a)
{
    int i;
    int x;
    int tmp;

    x = 0;
    while (x < *size_a - 1)
    {
        i = 0;
        while (i < *size_a - 1-x)
        {
            if (sorted_stack[i] > sorted_stack[i+1])
            {
                tmp = sorted_stack[i];
                sorted_stack[i] = sorted_stack[i+1];
                sorted_stack[i+1] = tmp;
            }
            i++;
        }
        x++;
    }
}

void re_indexing(int *stack_a, int *sorted_stack, int *size_a)
{
    int i;
    int x;

    i = 0;
    while(i < *size_a)
    {
        x = 0;
        while(i < *size_a)
        {
            if(stack_a[i] == sorted_stack[x])
            {
                stack_a[i] = x;
                break;
            }
            x++;
        }
        i++;
    }
}

int retiks_sort(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    int i;
    int x;

    i = 0;
    while(i < 9) // <<-- dependent on argument number
    {
        x = 0;
        while(x < *size_a)
        {
            if((stack_a[0] >> i) & 1)               
                rotate_a(stack_a, size_a, 0);
            else
                push_b(stack_a, stack_b, size_a, size_b);
            x++;
        }
        /* printf("size a: %d\n", *size_a);
	    printf("size b: %d\n", *size_b); */
        while(*size_b != 0)
        {
            push_a(stack_a, stack_b, size_a, size_b);
            
        }
        i++;
        //array_printer(stack_a, size_a);

    }
    return (0);
}

int six_numbers(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    int *sorted_stack;
    sorted_stack = (int *)malloc(sizeof(int) * (*size_a + 1));
    if(!sorted_stack)
        safe_exit(2, sorted_stack);

    array_cpy(stack_a, sorted_stack, size_a);

    array_printer(sorted_stack, size_a);
    printf("\n");
    pre_sorter(sorted_stack, size_a);

    re_indexing(stack_a, sorted_stack, size_a);

    array_printer(stack_a, size_a);

    retiks_sort(stack_a, stack_b, size_a, size_b);

    free(sorted_stack);
    return(0);
}



















/*     int stack_a[] = {-5, 7, 33, -12, 80, 9, 6, 1000, 99, 345, -786789}; numbers input
    int asorted[] = {-786789, -12, -5, 6, 7, 9, 33, 80, 99, 345, 1000}; numbers sorted */


/*  
int radix()
{
    int size_a; //size of stack_a;
    int counter;
    int i = 0;

    while(i < 31)
    {
        c = 0;
        while(counter < size_a)
        {
            if(stack_a[0] >> i & 1)
            {
                rotate_a
            }
            else
            {
                push_b
            }
            counter++;
        }
        while(sizeof b != 0)
            push_a;
    }
}
 */
