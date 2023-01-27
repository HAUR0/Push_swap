
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void array_printer(int *arr)
{
    int i = 0;
    
    while(i < 11)
    {
        printf("Array[%i] = %d\n", i, arr[i]);
        i++;
    }
}

int main()
{
    int i = 0;
    int x;

    int stack_a[] = {-5, 7, 33, -12, 80, 9, 6, 1000, 99, 345, -786789};
    int asorted[] = {-786789, -12, -5, 6, 7, 9, 33, 80, 99, 345, 1000};

    array_printer(asorted);
    while(stack_a[i])
    {
        x = 0;
        while(stack_a[i])
        {
            if(stack_a[i] == asorted[x])
            {
                stack_a[i] = x;
                break;
            }
            x++;
        }
        i++;
    }
    printf("\n");
    array_printer(stack_a);
}

/* 
int char_input_check(char **arr)
{
	int i;
	int p;
	
	p = 0;
	while(arr[p])
	{
		i = 0;
		while(arr[p][i])
		{
			if(stack_a[i] == sorted[x])

			i++;
		}
		p++;
	}
	return (0);
}

int	stringlength(int *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
	{
		cnt++;
	}
	return (cnt);
}

void array_printer(int *arr)
{
    int i = 0;
    
    while(arr[i])
    {
        printf("Array[%i] = %d\n", i, arr[i]);
        i++;
    }
}

int main()
{
    int i = 0;
    int *arr = malloc(sizeof(int) * 5 + 1);

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    arr[5] = '\0';
 
    int arr_size = stringlength(arr);

    printf("arr_size: %d\n\n", arr_size);
    array_printer(arr);
    printf("\n");

    while(arr[i])
    {
        arr[arr_size] = arr[arr_size - 1]; //rewriting it shifted
        //printf("Array[%i] = %d\n", arr_size, arr[arr_size]);
        arr_size--;
        i++;
    }
    arr[0] = 69; //simulating sa

    arr_size = stringlength(arr);
    printf("arr_size: %d\n\n", arr_size);
    array_printer(arr);
    return (0);
}
 */


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
