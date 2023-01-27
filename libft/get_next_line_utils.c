/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:23:14 by rloos             #+#    #+#             */
/*   Updated: 2022/12/08 11:23:19 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

int	get_checkline(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_substr(char *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (start >= get_strlen(s))
		len = 0;
	if (len > get_strlen(s) - start)
		dst = malloc(get_strlen(s) - start + 1);
	else
		dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*get_strjoin(char *s1, char *s2)
{
	int		i;
	int		x;
	char	*res;

	i = 0;
	x = 0;
	if (!s1 && s2)
		res = (char *)malloc(sizeof(char) * get_strlen(s2) + 1);
	if (s1 && s2)
		res = (char *)malloc(sizeof(char) * (get_strlen(s1) + get_strlen(s2))
				+ 1);
	if (!res || !s2)
		return (NULL);
	if (s1)
	{
		i = -1;
		while (s1[++i])
			res[i] = s1[i];
	}
	while (s2[x])
		res[i++] = s2[x++];
	res[i] = '\0';
	free(s1);
	return (res);
}
