#include "minishell.h"

int	error(int errnum, char *problem, t_envp *tenvp)
{
	problem = ft_strjoin("minishell: ", problem);
	if (errnum == COMMAND_ERROR)
	{
		problem = ft_strjoin(problem, ": command not found\n");
		ft_putstr_fd(problem, STDERR_FILENO);
		if (tenvp->main_pid != getpid())
			exit(EXIT_COMMAND_ERROR); // TODO 나중에 종료변수 저장하도록 만들기
		tenvp->exit_status = EXIT_COMMAND_ERROR;
		return (tenvp->exit_status);
	}
	else if (errnum == PERMISSION_ERROR)
	{
		problem = ft_strjoin(problem, ": permission denied\n");
		ft_putstr_fd(problem, STDERR_FILENO);
		if (tenvp->main_pid != getpid())
			exit(EXIT_PERMOSSION_ERROR);
		tenvp->exit_status = EXIT_PERMOSSION_ERROR;
		return (tenvp->exit_status);
	}
	else
		perror(problem);
	if (tenvp->main_pid != getpid())
		exit(EXIT_FAILURE); // TODO 나중에 종료변수 저장하도록 만들기
	tenvp->exit_status = EXIT_FAILURE;
	return (tenvp->exit_status);
}
