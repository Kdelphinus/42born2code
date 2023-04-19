#include "minishell.h"

int	print_error_for_invalid_name(char *cmd, int flag)
{
	if (flag == EXPORT_FUNC)
		ft_putstr_fd("minishell: export: `", STDERR_FILENO);
	else if (flag == UNSET_FUNC)
		ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
	return (0);
}

void	ft_simple_split_append(char *tmp, char *equal_address, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (tmp + i < equal_address)
	{
		str[0][i] = tmp[i];
		++i;
	}
	str[0][i] = '\0';
	if (str[0][i - 1] == '+')
		str[0][i - 1] = '\0';
	j = 0;
	++i;
	while (*(tmp + i) != '\0')
	{
		str[1][j] = tmp[i];
		++i;
		++j;
	}
	str[1][j] = '\0';
}

char	**ft_simple_split(char *tmp, char *equal_address)
{
	char	**str;

	str = malloc_s(sizeof(char *) * 3);
	str[0] = malloc_s(sizeof(char) * (equal_address - tmp + 1));
	str[1] = malloc_s(sizeof(char) * \
					(ft_strlen(tmp) - (equal_address - tmp) + 1));
	str[2] = NULL;
	ft_simple_split_append(tmp, equal_address, str);
	return (str);
}

void	print_export(t_env_node *head)
{
	int		i;
	char	**arr;

	i = 0;
	arr = convert_array_for_export(head);
	while (arr[i])
		i++;
	quick_sort(arr, 0, i - 1);
	i = 0;
	while (arr[i])
	{
		printf("declare -x %s\n", arr[i]);
		++i;
	}
	i = 0;
	while (arr[i] != NULL)
	{
		free_s(arr[i]);
		++i;
	}
	free_s(arr);
}

t_env_node	*get_old_key_address(t_env_node *head, char *key)
{
	head = head->next;
	while (head != NULL)
	{
		if (ft_strcmp(head->key, key) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}
