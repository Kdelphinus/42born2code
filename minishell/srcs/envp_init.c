#include "minishell.h"

void	envp_init(t_envp *tenvp, char **envp)
{
	tenvp->envp = envp;
	tenvp->paths = ft_split(getenv("PATH"), ':');
	if (!tenvp->paths)
		tenvp->paths = path_init();
	tenvp->argc = 0;
	tenvp->argv = NULL;
}
