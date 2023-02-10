/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <rloos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:25:43 by rloos             #+#    #+#             */
/*   Updated: 2023/02/10 16:28:17 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_for_doubles(int *stack_a, int *stack_b, int *size_a)
{
	int	i;
	int	x;

	x = 0;
	while (x < *size_a)
	{
		i = x + 1;
		while (i < *size_a)
		{
			if (stack_a[x] == stack_a[i])
			{
				safe_exit(3, stack_b);
				safe_exit(2, stack_a);
			}
			i++;
		}
		x++;
	}
	return (0);
}

int	get_malloc_size(int ac, char **av)
{
	int		i;
	int		x;
	int		counter;
	char	**tmp_arr;

	i = 0;
	counter = 0;
	while (i < ac - 1)
	{
		x = 0;
		tmp_arr = ft_split(av[i + 1], ' ');
		char_input_check(tmp_arr);
		while (tmp_arr[x])
		{
			counter++;
			x++;
		}
		i++;
		free_2d_array(tmp_arr);
	}
	return (counter);
}

int	*meloc(int counter)
{
	int	*arr;

	arr = (int *)ft_calloc((counter + 1), sizeof(int));
	if (!arr)
		safe_exit(2, arr);
	return (arr);
}

int	max_int_check(char **tmp_arr, int x, char *eituay, int counter)
{
	if (ft_strncmp(tmp_arr[x], eituay, counter + 1) != 0)
	{
		free(eituay);
		free_2d_array(tmp_arr);
		return (1);
	}
	return (0);
}

void	argument_reader(int ac, char **av, int *stack_a, int counter)
{
	int		x;
	int		i;
	int		k;
	char	*eituay;
	char	**tmp_arr;

	i = -1;
	k = 0;
	while (++i < ac - 1)
	{
		x = 0;
		tmp_arr = ft_split(av[i + 1], ' ');
		while (tmp_arr[x])
		{
			stack_a[k] = ft_atoi(tmp_arr[x]);
			eituay = ft_itoa(stack_a[k]);
			if (max_int_check(tmp_arr, x, eituay, counter) == 1)
				safe_exit(2, stack_a);
			free(eituay);
			k++;
			x++;
		}
		free_2d_array(tmp_arr);
	}
}
