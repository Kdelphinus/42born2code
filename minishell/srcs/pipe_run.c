#include "minishell.h"

static void	working_pid(t_envp tenvp)
{
	int		fds[2];
	pid_t	pid;
	int		i;
	int		status;

	i = -1;
	while (++i < tenvp.argc - 1)
	{
		if (pipe(fds) == -1)
			error(PIPE_ERROR, "pipe");
		pid = fork();
		if (pid == -1)
			error(FORK_ERROR, "fork");
		if (pid == 0)
		{
			dup2(fds[1], STDOUT_FILENO);
			close(fds[0]);
			work_pid(i, tenvp);
		}
		else
		{
			if (waitpid(pid, &status, WNOHANG) == -1)
				error(RUN_ERROR, "pid");
			dup2(fds[0], STDIN_FILENO);
			close(fds[1]);
		}
	}
	work_pid(i, tenvp);
}

static int	argv_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	pipex(char *str, char **envp)
{
	int		i;
	t_envp	tenvp;

	tenvp.paths = ft_split(getenv("PATH"), ':');
	if (!tenvp.paths)
		tenvp.paths = path_init();
	tenvp.argv = ft_split(str, '|');
	tenvp.argc = argv_len(tenvp.argv);
	i = -1;
	while (++i < tenvp.argc)
		tenvp.argv[i] = ft_strtrim(tenvp.argv[i], " 	");
	tenvp.envp = envp;
	working_pid(tenvp);
	return (EXIT_SUCCESS);
}

