#include "minishell.h"

void	ft_env(t_env_node *head)
{
	g_exit_status = 0;
	head = head->next;
	while (head)
	{
		if (head->value)
			printf("%s=%s\n", head->key, head->value);
		head = head->next;
	}
}
