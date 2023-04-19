#include "minishell.h"

void	ft_here_doc_acting(t_redir *new, char *tmp)
{
	char	*str;

	while (g_exit_status != HERE_DOC_SIGINT)
	{
		str = readline("> ");
		if (g_exit_status == HERE_DOC_SIGINT)
		{
			free_s(str);
			return ;
		}
		if (!str || ft_strcmp(tmp, str) == 0)
		{
			if (str)
				free_s(str);
			return ;
		}
		write(new->heredoc_fd, str, ft_strlen(str));
		write(new->heredoc_fd, "\n", 1);
		free_s(str);
	}
}
