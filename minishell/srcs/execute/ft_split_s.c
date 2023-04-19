#include "minishell.h"

static void	ft_insert_words(const char *str, char **s_spt, char set, \
							size_t w_count)
{
	size_t	i;
	size_t	j;
	int		flag_in_string;

	flag_in_string = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != set && flag_in_string == 0)
		{
			flag_in_string = 1;
			w_count++;
			j = 0;
			while (str[i + j] != set && str[i + j])
			{
				*(s_spt[w_count - 1] + j) = str[i + j];
				j++;
			}
			*(s_spt[w_count - 1] + j) = '\0';
			i += j - 1;
		}
		if (str[i] == set)
			flag_in_string = 0;
		i++;
	}
}

static int	ft_free_all_allocation(char **s_spt, size_t w_count)
{
	while (w_count > 0)
	{
		w_count--;
		free_s(s_spt[w_count]);
	}
	free_s(s_spt);
	return (0);
}

static int	ft_malloc_strings(const char *str, char **s_spt, char set, \
								size_t w_count)
{
	size_t	i;
	size_t	j;
	int		flag_in_string;

	flag_in_string = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != set && flag_in_string == 0)
		{
			flag_in_string = 1;
			w_count++;
			j = 0;
			while (str[i + j] != set && str[i + j])
				j++;
			s_spt[w_count - 1] = (char *)malloc_s(sizeof(char) * (j + 1));
			if (s_spt[w_count - 1] == 0)
				return (ft_free_all_allocation(s_spt, w_count - 1));
			i += j - 1;
		}
		if (str[i] == set)
			flag_in_string = 0;
		i++;
	}
	return (1);
}

static size_t	ft_count_words(const char *str, char set)
{
	size_t	word_count;
	size_t	i;
	int		flag_in_string;

	word_count = 0;
	flag_in_string = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != set && flag_in_string == 0)
		{
			flag_in_string = 1;
			word_count++;
		}
		if (str[i] == set)
			flag_in_string = 0;
		i++;
	}
	return (word_count);
}

char	**ft_split_s(char const *s, char c)
{
	char	**s_spt;
	size_t	w_count;

	w_count = ft_count_words((const char *)s, c);
	s_spt = (char **)malloc_s(sizeof(char *) * (w_count + 1));
	if (ft_malloc_strings((const char *)s, s_spt, c, 0) == 0)
		return (0);
	ft_insert_words((const char *)s, s_spt, c, 0);
	s_spt[w_count] = 0;
	return (s_spt);
}
