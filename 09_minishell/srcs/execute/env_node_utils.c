#include "minishell.h"

static size_t	get_node_len(t_env_node *head)
{
	size_t	i;

	i = 0;
	head = head->next;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

char	**convert_array_for_execve(t_env_node *head)
{
	int		i;
	char	*tmp;
	char	**arr;

	i = 0;
	arr = malloc_s(sizeof(char *) * (get_node_len(head) + 1));
	head = head->next;
	while (head != NULL)
	{
		if (head->value)
		{
			tmp = ft_strjoin_s(head->key, "=");
			arr[i] = ft_strjoin_s(tmp, head->value);
			free_s(tmp);
		}
		else
			arr[i] = ft_strdup_s(head->key);
		head = head->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

void	add_quote(t_env_node *head, char **arr, int i)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_strjoin_s(head->key, "=");
	tmp2 = ft_strjoin_s(tmp, "\"");
	tmp3 = ft_strjoin_s(tmp2, head->value);
	arr[i] = ft_strjoin_s(tmp3, "\"");
	free_s(tmp);
	free_s(tmp2);
	free_s(tmp3);
}

char	**convert_array_for_export(t_env_node *head)
{
	int		i;
	char	**arr;

	i = 0;
	arr = malloc_s(sizeof(char *) * (get_node_len(head) + 1));
	head = head->next;
	while (head != NULL)
	{
		if (head->value)
			add_quote(head, arr, i);
		else
			arr[i] = ft_strdup_s(head->key);
		head = head->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

t_env_node	*init_node(char **envp)
{
	int			i;
	char		**tmp;
	t_env_node	*tmp_node;
	t_env_node	*head_node;

	i = -1;
	head_node = create_node(NULL, NULL);
	tmp_node = head_node;
	while (envp[++i])
	{
		tmp = ft_split_for_init(envp[i]);
		if (!ft_strcmp(tmp[0], "OLDPWD"))
		{
			free_s(tmp[1]);
			tmp[1] = NULL;
		}
		tmp_node->next = create_node(tmp[0], tmp[1]);
		free_s(tmp);
		tmp_node = tmp_node->next;
	}
	return (head_node);
}
