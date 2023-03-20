#include "minishell.h"

static int	working_pid(t_envp *tenvp)
{
	int		fds[2];
	pid_t	pid;
	int		i;
	int		status;

	i = -1;
	while (++i < tenvp->argc)
	{
		if (pipe(fds) == -1)
			error(PIPE_ERROR, "pipe", tenvp);
		if (i == tenvp->argc - 1)
		{
			close(fds[0]);
			close(fds[1]);
		}
		if (tenvp->exit_status)
			break ;
		pid = fork();
		if (pid == -1)
			error(FORK_ERROR, "fork", tenvp);
		if (pid == 0)
		{
			if (i < tenvp->argc - 1)
			{
				dup2(fds[1], STDOUT_FILENO);
				close(fds[0]);
			}
			work_pid(i, tenvp);
		}
		else
		{
			if (i == tenvp->argc - 1)
			{
				if (waitpid(pid, &status, 0) == -1)
					error(RUN_ERROR, "pid", tenvp);
			}
			else
			{
				if (waitpid(pid, &status, WNOHANG) == -1)
					error(RUN_ERROR, "pid", tenvp);
				dup2(fds[0], STDIN_FILENO);
				close(fds[1]);
			}
		}
	}
	return (status);
}

static int	argv_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	pipex(char *str, t_envp *tenvp)
{
	int i;
	int	status;

	tenvp->argv = ft_split(str, '|');
	tenvp->argc = argv_len(tenvp->argv);
	i = -1;
	while (++i < tenvp->argc)
		tenvp->argv[i] = ft_strtrim(tenvp->argv[i], " 	");
	status = working_pid(tenvp);
	if (WIFEXITED(status))
		tenvp->exit_status = WEXITSTATUS(status);
	else
		exit(1); // TODO 시그널에 의해 종료되었거나 강제 종료되었을 때 처리가 필요함
}
