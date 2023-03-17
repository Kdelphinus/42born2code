#include "minishell.h"

int main(void)
{
	char	*str;
	char	*cwd;

	while (1)
	{
		str = readline("$>");
		if (!str)
			break ;
		printf("%s\n", str);
		cwd = getcwd(NULL, 1);
		if (cwd)
			printf("%s\n", cwd);
		add_history(str);
		free(str);
	}
	return (0);
}
