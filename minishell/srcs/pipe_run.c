#include "minishell.h"

static void	working_pid(t_envp tenvp)
{
	int		fds[2];
	pid_t	pid;
	int		i;
	int		status;

	i = -1;
	while (++i < tenvp.argc)
	{
		if (pipe(fds) == -1)
			error(PIPE_ERROR, "pipe");
		if (i == tenvp.argc - 1)
		{
			close(fds[0]);
			close(fds[1]);
		}
		pid = fork();
		if (pid == -1)
			error(FORK_ERROR, "fork");
		if (pid == 0)
		{
			if (i < tenvp.argc - 1)
			{
				dup2(fds[1], STDOUT_FILENO);
				close(fds[0]);
			}
			work_pid(i, tenvp);
		}
		else
		{
			if (i == tenvp.argc - 1)
			{
				if (waitpid(pid, NULL, 0) == -1)
					error(RUN_ERROR, "pid");
			}
			else
			{
				if (waitpid(pid, &status, WNOHANG) == -1)
					error(RUN_ERROR, "pid");
				dup2(fds[0], STDIN_FILENO);
				close(fds[1]);
			}
		}
	}
}

static int	argv_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	pipex(char *str, t_envp tenvp)
{
	int i;

	tenvp.argv = ft_split(str, '|');
	tenvp.argc = argv_len(tenvp.argv);
	i = -1;
	while (++i < tenvp.argc)
		tenvp.argv[i] = ft_strtrim(tenvp.argv[i], " 	");
	working_pid(tenvp);
	return (EXIT_SUCCESS);
}
