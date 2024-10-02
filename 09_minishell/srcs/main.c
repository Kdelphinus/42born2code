#include "minishell.h"

static t_env_node	*initialize(int ac, char **av, char **envp)
{
	if (ac != 1)
		exit(1);
	if (!ft_strcmp(av[0], "minishell"))
		exit(1);
	return (init_node(envp));
}

int	ft_print_exit_free_env_all(void)
{
	write(STDOUT_FILENO, "exit\n", 5);
	exit(0);
}

void	free_parsed_data(t_token *front)
{
	int		i;
	t_token	*tmp_front;
	t_redir	*tmp_redir;

	while (front)
	{
		i = 0;
		while (front->cmd && front->cmd[i])
		{
			free_s(front->cmd[i]);
			++i;
		}
		free_s(front->cmd);
		while (front->redir)
		{
			tmp_redir = front->redir;
			front->redir = front->redir->next;
			free_s(tmp_redir);
		}
		tmp_front = front;
		front = front->next;
		free_s(tmp_front);
	}
}

int	main(int ac, char **av, char **envp)
{
	char		*str;
	t_p_data	parsed_data;
	t_env_node	*head;
	t_p_data	start_data;

	head = initialize(ac, av, envp);
	rl_catch_signals = 0;
	while (1)
	{
		ft_signal_init();
		str = readline("minishell$ ");
		if (!str)
			return (ft_print_exit_free_env_all());
		if (str[0] != '\0')
			add_history(str);
		parsing(str, &parsed_data, head->next);
		start_data = parsed_data;
		if (parsed_data.front && (parsed_data.front->cmd
				|| parsed_data.front->redir))
			execute(head, &parsed_data);
		free_parsed_data(start_data.front);
		free_s(str);
	}
}
