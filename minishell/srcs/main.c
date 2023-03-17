#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*str;

	(void)envp;
	if (ac != 1)
		return (0);
	if (!ft_strcmp(av[0], "minishell"))
		return (0);
	while (1)
	{
		str = readline("$>");
		if (!str)
			break ;
		if (ft_strchr(str, 124))
			pipex(str, envp);
		add_history(str);
		free(str);
	}
	return (0);
}
