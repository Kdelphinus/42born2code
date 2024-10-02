#include "minishell.h"

void	execute_no_pipe(t_env_node *head, t_p_data *p_data, int *status)
{
	pid_t	pid;

	pid = 0;
	if (p_data->front->cmd != NULL && p_data->front->cmd_type == EXTERN_FUNC)
		pid = fork_s();
	if (pid > 0)
	{
		signal(SIGINT, signal_handler_for_parent);
		wait(status);
		signal(SIGINT, signal_handler);
		handle_execute_exit_status(*status);
	}
	else if (pid == 0)
	{
		if (p_data->front->cmd_type == EXTERN_FUNC)
			ft_signal_child();
		execute_token(head, p_data->front, FALSE);
	}
}

void	execute_first_pipe(t_env_node *head, t_p_data *p_data, int **fd)
{
	pid_t	pid;

	pipe_s(fd[0]);
	pid = fork_s();
	if (pid == 0)
	{
		ft_signal_child();
		close(fd[0][READ_END]);
		dup2(fd[0][WRITE_END], STDOUT_FILENO);
		close(fd[0][WRITE_END]);
		execute_token(head, p_data->front, TRUE);
		exit(g_exit_status);
	}
	else if (pid > 0)
	{
		signal(SIGINT, signal_handler_for_parent);
		close(fd[0][WRITE_END]);
		p_data->front = p_data->front->next;
	}
}

int	execute_middle_pipe(t_env_node *head, t_p_data *p_data, int **fd)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < p_data->pipe_cnt - 1)
	{
		++i;
		pipe_s(fd[i]);
		pid = fork_s();
		if (pid == 0)
			do_child(head, p_data, fd, i);
		else if (pid > 0)
		{
			close(fd[i - 1][READ_END]);
			close(fd[i][WRITE_END]);
			p_data->front = p_data->front->next;
		}
	}
	return (i);
}

int	execute_end_pipe(t_env_node *head, t_p_data *p_data, int **fd, int i)
{
	int		status;
	pid_t	pid;

	pid = fork_s();
	status = 0;
	if (pid == 0)
	{
		ft_signal_child();
		dup2(fd[i][READ_END], STDIN_FILENO);
		close(fd[i][READ_END]);
		execute_token(head, p_data->front, TRUE);
		exit(g_exit_status);
	}
	else if (pid > 0)
	{
		status = do_parent(p_data, pid, fd, i);
		signal(SIGINT, signal_handler);
	}
	return (status);
}
