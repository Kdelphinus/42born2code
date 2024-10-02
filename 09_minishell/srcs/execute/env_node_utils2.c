#include "minishell.h"

char	**ft_split_for_init(char *str)
{
	int		i;
	char	**s_spt;
	char	*equal_address;

	equal_address = ft_strchr(str, '=');
	if (equal_address == NULL)
	{
		s_spt = malloc_s(sizeof(char *) * 2);
		s_spt[0] = ft_strdup_s(str);
		s_spt[1] = NULL;
	}
	else
	{
		s_spt = malloc_s(sizeof(char *) * 3);
		s_spt[0] = malloc_s(sizeof(char) * \
			(ft_strlen(str) - ft_strlen(equal_address) + 1));
		i = -1;
		while (str[++i] != '=')
			s_spt[0][i] = str[i];
		s_spt[0][i] = '\0';
		s_spt[1] = ft_strdup_s(equal_address + 1);
		s_spt[2] = NULL;
	}
	return (s_spt);
}

t_env_node	*create_node(char *key, char *value)
{
	t_env_node	*new_node;

	new_node = malloc_s(sizeof(t_env_node));
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	delete_node(t_env_node *head, char *key)
{
	t_env_node	*prev;
	t_env_node	*curr;

	while (head->next != NULL)
	{
		if (ft_strcmp(head->next->key, key) == 0)
			break ;
		head = head->next;
	}
	if (head->next == NULL)
		return ;
	prev = head;
	curr = head->next;
	prev->next = curr->next;
	free_s(curr->key);
	free_s(curr->value);
	free_s(curr);
}

void	add_node(t_env_node *head, t_env_node *node)
{
	while (head->next != NULL)
	{
		head = head->next;
	}
	head->next = node;
}
