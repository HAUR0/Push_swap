/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:25:29 by rloos             #+#    #+#             */
/*   Updated: 2023/02/10 16:30:48 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_2d_array(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	safe_exit(int error, int *array)
{
	if (error == 0)
		exit(0);
	else if (error == 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	else if (error == 2)
	{
		free(array);
		ft_printf("Error\n");
		exit(1);
	}
	else if (error == 3)
		free(array);
	else if (error == 4)
	{
		free(array);
		exit(1);
	}
}

void	sorted_input(int *les_variables, int *size_a, int *stack_b)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i < *size_a - 1)
	{
		if (les_variables[i] < les_variables[i + 1])
			x++;
		i++;
	}
	if (x == *size_a - 1)
	{
		safe_exit(3, stack_b);
		safe_exit(4, les_variables);
	}
}

void	char_and_minus_checker(char **arr, int i, int p)
{
	if ((arr[p][i] < '0' || arr[p][i] > '9') && arr[p][i] != '-')
	{
		free_2d_array(arr);
		ft_printf("Error\n");
		exit(1);
	}
	else if (((arr[p][i] >= '0' && arr[p][i] <= '9') && arr[p][i + 1] == '-'))
	{
		free_2d_array(arr);
		ft_printf("Error\n");
		exit(1);
	}
}

void	char_input_check(char **arr)
{
	int	i;
	int	p;

	p = 0;
	while (arr[p])
	{
		i = 0;
		while (arr[p][i])
		{
			char_and_minus_checker(arr, i, p);
			i++;
		}
		p++;
	}
}
