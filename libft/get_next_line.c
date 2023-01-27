/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:22:23 by rloos             #+#    #+#             */
/*   Updated: 2022/12/08 11:22:45 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*rd_join(int fd, char *str)
{
	ssize_t	rd;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (get_checkline(str) == 0 && rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[rd] = '\0';
		if (rd > 0)
			str = get_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*nline(char *str)
{
	int		i;
	char	*nline;

	if (!str || !str[0] || str == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	nline = get_substr(str, 0, i);
	nline[i] = '\0';
	return (nline);
}

char	*the_rest(char *str, int len)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!str || !str[0] || str == NULL)
	{
		free(str);
		return (NULL);
	}
	tmp = malloc((get_strlen(str) - len) + 1);
	if (!tmp)
		return (NULL);
	while (str[len])
	{
		tmp[i] = str[len];
		len++;
		i++;
	}
	tmp[i] = '\0';
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*newline;
	int			len;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = rd_join(fd, str);
	newline = nline(str);
	if (!str || !str[0] || str == NULL)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	len = get_strlen(newline);
	str = the_rest(str, len);
	return (newline);
}
/* 
int	main(void)
{
	int			count;
	static int	x;
	int			fd;
	char		*willy;
	int			i;

	count = 4;
	i = 0;
	fd = open("text.txt", O_RDONLY);
	while (i < count)
	{
		willy = get_next_line(fd);
		printf("\n%x - Newline: %s", x, willy);
		x++;
		i++;
		free(willy);
		willy = NULL;
	}
	close(fd);
	return (0);
}
 */