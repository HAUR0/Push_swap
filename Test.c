
#include <stdio.h>
#include <stdlib.h>

void array_printer(int *arr)
{
	int i;
	
	i = 0;
	while(arr[i])
	{
		printf("%d\n", arr[i]);
		i++;
	}
}

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
		dst = malloc(ft_strlen(s) - start + 1);
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
	cnt = 0; //übergeordnete if or while still needs to be handled because of edgecases
	while (str[i] && str[i] == c)
		i++;
	while (str[i] && str[i] != c)
	{
/* 		if(str[i] < '0' || str[i] > '9')
			exit (1); */
		i++;
		cnt++;
	}
	return (cnt);
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
int	ft_atoi(const char *str)
{
	int	i;
	int	multi;
	int	res;

	i = 0;
	multi = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
		{
			multi *= -1;
		}
		i++;
	}
	res = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * multi);
}

int char_check(char **arr)
{
	int i;
	int p;

/* 	if(found max integer)
		exit */
	
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
			printf("stack_a[%d]: %i\n", i, stack_a[k]);
			k++;
			x++;
		}
		i++;
	}
	stack_a[i+1] = '\0';
	check_for_doubles(stack_a);
	free(tmp_arr);
}
