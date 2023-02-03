
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
	{
		cnt++;
	}
	return (cnt);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
    {
		dst = malloc(ft_strlen(s) - start + 1);
        if (!dst)
		    return (NULL);
    }
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
static int	word_cnt(char const *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			cnt++;
			while (str[i] != c)
			{
				i++;
				if (str[i] == '\0')
					return (cnt);
			}
		}
		i++;
	}
	return (cnt);
}
static int	word_length(char const *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			cnt++;
			i++;
		}
		return (cnt);
		i++;
	}
	return (0);
}
char	**ft_split(char const *s, char c)
{
	int		i;
	int		x;
	char	**arr;

	i = 0;
	x = 0;
	arr = (char **)malloc(sizeof(char *) * (word_cnt(s, c) + 1));
	if (!arr)
		return (NULL);
	while (x < word_cnt(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		arr[x] = ft_substr(s, i, word_length(&s[i], c));
		i = i + word_length(&s[i], c);
		x++;
	}
	arr[word_cnt(s, c)] = NULL;
	return (arr);
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
		while(tmp_arr[x++])
			counter++;
		i++;
	}
    i = 0;
	while(tmp_arr[i])
    {
	    free(tmp_arr[i]);
        i++;
    }
	free(tmp_arr);
	return (counter);
}
int main(int ac, char **av)
{
    int cnt;
    //int i = 0;

    cnt = get_malloc_size(ac, av);
/* 
    while(tmp_arr[i])
    {
	    free(&tmp_arr[i]);
        i++;
    } */
    printf("%d", cnt);
}


valgrind --leak-check=full --show-leak-kinds=all -s ./a.out

int six_numbers(int *stack_a, int size_a)
{
    int stack_a[] = {88, 13008, 456, 122, 501};
    int size_a = sizeof(stack_a) / sizeof(stack_a[0]);
    printf("%d\n", size_a);

    int *sorted_stack;
    sorted_stack = (int *)malloc(sizeof(int) * (size_a + 1));
    if(!sorted_stack)
        safe_exit(2, sorted_stack);

    array_cpy(stack_a, sorted_stack, size_a);
    pre_sorter(sorted_stack, size_a);
    re_indexing(stack_a, sorted_stack, size_a);

    array_printer(sorted_stack, size_a);
    printf("\n");
    array_printer(stack_a, size_a);
    free(sorted_stack);

    exit (0);
}

