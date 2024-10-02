#include "minishell.h"

static int	check_echo_option(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' && arg[1] == 'n')
	{
		i = 1;
		while (arg[i] == 'n')
			i++;
		if (arg[i] != '\0')
			return (0);
	}
	return (i);
}

static void	loop_echo(char **args, int *newline_flag)
{
	int	i;
	int	j;
	int	no_option;
	int	option_flag;

	i = 0;
	no_option = 0;
	while (args[++i])
	{
		if (no_option == 0)
			option_flag = check_echo_option(args[i]);
		if (option_flag == 0)
		{
			j = -1;
			while (args[i][++j])
				write(STDOUT_FILENO, &args[i][j], 1);
			if (args[i + 1])
				write(STDOUT_FILENO, " ", 1);
			no_option = 1;
		}
		else
			*newline_flag = 0;
	}
}

void	ft_echo(char **args)
{
	int	newline_flag;

	g_exit_status = 0;
	if (!args[1])
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		return ;
	}
	newline_flag = 1;
	loop_echo(args, &newline_flag);
	if (newline_flag == 1)
		write(STDOUT_FILENO, "\n", 1);
}
