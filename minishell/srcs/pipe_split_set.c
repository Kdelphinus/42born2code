#include "minishell.h"

static int	word_size(char *str, int check[])
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (check[(int)str[i]] && str[i])
		i++;
	while (str[i])
	{
		if (check[(int)str[i]])
		{
			size++;
			while (check[(int)str[i]] && str[i])
				i++;
			i -= 1;
		}
		i++;
	}
	if (!check[(int)str[--i]])
		size++;
	return (size);
}

static int	next_start(char *str, int i, int check[])
{
	int	start;

	while (str[i])
	{
		if (!check[(int)str[i]])
		{
			start = i;
			return (start);
		}
		i++;
	}
	return (0);
}

static void	input_split(char *str, char **split_strs, int check[], int j)
{
	int	i;
	int	k;
	int	start;

	i = -1;
	start = 0;
	while (check[(int)str[++i]])
		start++;
	while (1)
	{
		if ((check[(int)str[i]] && start < i) || !str[i])
		{
			k = 0;
			split_strs[j] = (char *)malloc(sizeof(char) * (i - start + 1));
			while (start < i)
				split_strs[j][k++] = str[start++];
			split_strs[j++][k] = '\0';
			start = next_start(str, i, check);
			if (start == 0 || !str[i])
				return ;
		}
		i++;
	}
}

char	**ft_split_set(char *str, char *charset)
{
	int		i;
	int		size;
	int		check[256];
	char	**split_strs;

	i = 0;
	while (i < 256)
		check[i++] = 0;
	i = -1;
	check[0] = 1;
	while (charset[++i])
	{
		if (check[(int)charset[i]] == 0)
			check[(int)charset[i]] = 1;
	}
	i = 0;
	size = word_size(str, check);
	split_strs = (char **)malloc(sizeof(char *) * (size + 1));
	input_split(str, split_strs, check, 0);
	split_strs[size] = 0;
	return (split_strs);
}
