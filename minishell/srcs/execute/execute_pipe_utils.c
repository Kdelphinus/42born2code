#include "minishell.h"

void	do_child(t_env_node *head, t_p_data *p_data, int **fd, int i)
{
	ft_signal_child();
	close(fd[i][READ_END]);
	dup2(fd[i - 1][READ_END], STDIN_FILENO);
	close(fd[i - 1][READ_END]);
	dup2(fd[i][WRITE_END], STDOUT_FILENO);
	close(fd[i][WRITE_END]);
	execute_token(head, p_data->front, TRUE);
	exit(g_exit_status);
}

int	do_parent(t_p_data *p_data, pid_t pid, int **fd, int i)
{
	int	tmp;
	int	status;

	close(fd[i][READ_END]);
	i = 0;
	while (i < p_data->pipe_cnt + 1)
	{
		if (pid == wait(&tmp))
			status = tmp;
		++i;
	}
	return (status);
}
