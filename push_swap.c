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

void array_printer(int *arr)
{
	int i;

	i = 0;
	while(arr[i])
	{
		ft_printf("Array[%i] = %d\n", i, arr[i]);
		i++;
	}
}


void safe_exit(int error)
{
	if(error == 1)
	{
		ft_printf("Error");
		exit (1);
	}
	if(error == 2)
	{
		//free(stuff)
		ft_printf("Error");
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
		safe_exit(1);
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
				safe_exit(1);
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
	//DONT FORGET to free tmp_arr
	return (counter);
}

int *meloc(int counter)
{
	int *arr;

	arr = malloc(sizeof(int) * counter + 1);
	if(!arr)
		safe_exit(2);
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
	while(i < ac-1)
	{
		x = 0;
		tmp_arr = ft_split(av[i+1], ' ');
		while(tmp_arr[x])
		{
			stack_a[k] = ft_atoi(tmp_arr[x]); //ft_printf("stack_a[%d]: %i\n", i, stack_a[k]);
			if(ft_strncmp(tmp_arr[x], ft_itoa(stack_a[k]), counter) != 0)
				safe_exit(1);
			k++;
			x++;
		}
		i++;
	}
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
				safe_exit (1);
			i++;
		}
		x++;
	}
	return (0);
}

int main(int ac, char **av)
{
	int *les_variables;
	int *stack_a;
	int *stack_b;

	stack_a = meloc(get_malloc_size(ac, av));
	stack_b = meloc(get_malloc_size(ac, av));

	les_variables = argument_reader(ac, av, stack_a, get_malloc_size(ac, av));
	sorted_input(les_variables);
	check_for_doubles(les_variables);

	//array_printer(stack_a);

	return (0);
}
