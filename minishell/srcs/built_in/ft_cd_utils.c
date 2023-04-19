#include "minishell.h"

char	*ft_getenv(t_env_node *head, char *key)
{
	head = head->next;
	while (head)
	{
		if (ft_strcmp(key, head->key) == 0)
		{
			if (head->value)
				return (ft_strdup_s(head->value));
			else
				return (NULL);
		}
		head = head->next;
	}
	return (NULL);
}

void	ft_setenv(char *key, char *value, t_env_node *head)
{
	if (value == NULL)
		return ;
	head = head->next;
	while (head != NULL)
	{
		if (ft_strcmp(key, head->key) == 0)
		{
			free_s(head->value);
			head->value = ft_strdup_s(value);
			free_s(value);
			break ;
		}
		head = head->next;
	}
}
