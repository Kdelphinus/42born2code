#include "minishell.h"

void	envp_init(t_envp *tenvp, char **envp)
{
	tenvp->envp = envp;
	tenvp->argc = 0;
	tenvp->argv = NULL;
	tenvp->exit_status = 0;
	tenvp->main_pid = getpid();
	tenvp->paths = ft_split(getenv("PATH"), ':');
	if (!tenvp->paths)
		tenvp->paths = path_init(tenvp);
}
