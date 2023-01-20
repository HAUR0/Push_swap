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

#include <stdio.h>
#include <stdlib.h>

int char_check(char **arr)
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
				exit (1);
			i++;
		}
		p++;
	}
	return (0);
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
				exit (1);
			i++;
		}
		x++;
	}
	return (0);
}

int main(int ac, char **av)
{
	int i = 0;
	int k = 0;
	int x = 0;
	char **tmp_arr;
	int *stack_a;

	stack_a = (int *)malloc(sizeof(int *) * (1));
	
	while(i < ac-1)
	{
		x = 0;
		tmp_arr = ft_split(av[i+1], ' ');
		char_check(tmp_arr);
		while(tmp_arr[x]) // != (void *)'\0'
		{
			stack_a[k] = ft_atoi(tmp_arr[x]);
			//printf("stack_a[%d]: %i\n", i, stack_a[k]);
			k++;
			x++;
		}
		i++;
	}
	stack_a[i+1] = '\0';
	check_for_doubles(stack_a);
	free(tmp_arr);
}
