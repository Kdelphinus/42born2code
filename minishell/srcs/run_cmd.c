#include "minishell.h"

void	run_cmd(char *cmd, t_envp *tenvp)
{
	pid_t	pid;
	char	*path;
	char	**new_argv;
	int		status;

	tenvp->argc = 1;
	tenvp->argv = malloc(sizeof(char *) * 2);
	if (!tenvp->argv)
		error(MALLOC_ERROR, "malloc", tenvp) ; // TODO 나중에 에러 처리 잘 해주세요
	tenvp->argv[0] = cmd;
	tenvp->argv[1] = NULL;
	new_argv = argv_init(0, tenvp);
	if (!new_argv)
	{
		error(MALLOC_ERROR, "malloc", tenvp);
		return ;
	}
	path = ft_path(new_argv[0], tenvp->paths);
	if (!path)
	{
		error(COMMAND_ERROR, new_argv[0], tenvp);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, new_argv, tenvp->envp) == -1)
			error(RUN_ERROR, new_argv[0], tenvp);
	}
	else if (pid > 0)
		waitpid(pid, &status, 0);
	else
		error(FORK_ERROR, "fork", tenvp);
	if (WIFEXITED(status))
		tenvp->exit_status = WEXITSTATUS(status);
	else
		exit(1); // TODO 시그널에 의해 종료되었거나 강제 종료되었을 때 처리가 필요함
}
