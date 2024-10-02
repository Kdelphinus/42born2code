#include "minishell.h"

void	signal_handler_for_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		g_exit_status = HERE_DOC_SIGINT;
		rl_replace_line("", 0);
		write(1, "\b\b", 2);
		rl_done = 1;
		rl_on_new_line();
		rl_redisplay();
	}
}
