/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:08:47 by rloos             #+#    #+#             */
/*   Updated: 2022/10/13 15:09:33 by rloos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

#  define BUFFER_SIZE 100

int		ft_isalpha(int argument);
int		ft_isdigit(int arg);
int		ft_isalnum(int argument);
int		ft_isascii(int c);
int		ft_isprint(int arg);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int ch);
int		ft_tolower(int ch);
char	*ft_strchr(const char *s, int searched_item);
char	*ft_strrchr(const char *s, int searched_item);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//ft_printf-functions
int	    pr_putchar(char a, int cnt);
int	    pr_putstr(char *b, int cnt);
int	    pr_putnbr(int e, int cnt);
int	    pr_putunsigned_nbr(unsigned int e, int cnt);
int	    pr_hexa_up(unsigned int n, int cnt);
int	    pr_hexa_lo(unsigned int n, int cnt);
int	    pr_pointer(unsigned long long n, int cnt);
int	    ptr_write(unsigned long long dingdong, int cnt);
int	    ft_printf(const char *str, ...);

//get_next_line-functions
int		get_checkline(char *str);
size_t	get_strlen(char *str);
char	*get_strjoin(char *s1, char *s2);
char	*get_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif
