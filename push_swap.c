/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:45:20 by rloos             #+#    #+#             */
/*   Updated: 2023/01/06 12:45:27 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void array_printer(int *arr, int *size_a)
{
	int i;

	i = 0;
	if(arr[0] == 0)
	{
		ft_printf("Array[0] = 0\n");
		i = 1;
	}
	while(i < *size_a)
	{
		ft_printf("Array[%i] = %d\n", i, arr[i]);
		i++;
	}
}

void safe_exit(int error, int *array)
{
    if(error == 0)
	{
        exit (0);
	}
	if(error == 1)
	{
		ft_printf("Fehler");
		exit (1);
	}
	if(error == 2)
	{
		free(array);
		ft_printf("Fehler");
		exit (1);
	}
}

void sorted_input(int *les_variables)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while(les_variables[i])
	{
		if(les_variables[i] < les_variables[i+1])
		{
			x++;
		}
		i++;
	}
	printf("i: %i\n", i);
	printf("x: %i\n", x);
	if(i == (x+1))  // !!! 1 Argument or Number still has to work???
		exit(1);
}

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
			if((arr[p][i] < '0' || arr[p][i] > '9') && arr[p][i] != '-')
				exit(1);//safe_exit(2, arr); <<== muss noch für ein 2D Array modifiziert werden
			i++;
		}
		p++;
	}
	return (0);
}

int get_malloc_size(int ac, char **av)
{
	int i;
	int x;
	int counter;
	char **tmp_arr;

	i = 0;
	counter = 0;
	while(i < ac-1)
	{
		x = 0;
		tmp_arr = ft_split(av[i+1], ' ');
		char_input_check(tmp_arr);
		while(tmp_arr[x])
		{
			counter++;
			x++;
		}
		i++;
	}
	if (tmp_arr)
		free_array(tmp_arr);
	return (counter);
}

int *meloc(int counter)
{
	int *arr;

	arr = ft_calloc((counter + 1), 4);
	if(!arr)
		safe_exit(2, arr);
	return (arr);
}

int *argument_reader(int ac, char **av, int *stack_a, int counter)
{
	int k;
	int x;
	int i;
	char **tmp_arr;
	
	i = 0;
	k = 0;
	tmp_arr = NULL;
	while(i < ac-1)
	{
		x = 0;
		tmp_arr = ft_split(av[i+1], ' ');
		while(tmp_arr[x])
		{
			stack_a[k] = ft_atoi(tmp_arr[x]);
			if(ft_strncmp(tmp_arr[x], ft_itoa(stack_a[k]), counter) != 0)
				safe_exit(2, stack_a);
			k++;
			x++;
		}
		i++;
	}
	if (tmp_arr)
		free_array(tmp_arr);
	stack_a[i+1] = '\0';
	return (stack_a);
}

int check_for_doubles(int *stack_a)
{
	int i;
	int x;

	x = 0;
	while(stack_a[x])
	{
		i = x + 1;
		while(stack_a[i])
		{
			if(stack_a[x] == stack_a[i])
				safe_exit (1, stack_a);
			i++;
		}
		x++;
	}
	return (0);
}

void free_array(char **s)
{
	int i;

	i = 0;
	while (s && s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int main(int ac, char **av)
{
	int *les_variables;
	int *stack_a;
	int *stack_b;

	int size_a;
	int size_b = 0;

	size_a = (get_malloc_size(ac, av));
	stack_a = meloc(size_a);
	stack_b = meloc(size_a);

	les_variables = argument_reader(ac, av, stack_a, size_a);
	check_for_doubles(les_variables);
	call_sorting(stack_a, stack_b, &size_b, &size_a);

	//array_printer(stack_a, &size_a);
	//array_printer(stack_b);
	return (0);
}

//int size = sizeof(data) / sizeof(data[0]);

diff <(./push_swap 8 7 6 5 4 3) <(./push_swap "8 7 6 5 4 3")