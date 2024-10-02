#include "minishell.h"

void	signal_handler_for_parent(int sig)
{
	if (sig == SIGINT)
	{
		g_exit_status = 1;
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signal_handler(int sig)
{
	char	*tmp;

	if (sig == SIGINT)
	{
		g_exit_status = 1;
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		tmp = ft_itoa(g_exit_status);
		if (!tmp)
			ft_allocation_error();
		ft_putstr_fd("Quit: ", STDERR_FILENO);
		ft_putstr_fd(tmp, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		free_s(tmp);
		exit(1);
	}
}

void	ft_signal_init(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_signal_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, signal_handler);
}
