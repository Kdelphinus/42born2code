/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:45:17 by myko              #+#    #+#             */
/*   Updated: 2022/11/30 20:58:33 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	working_pid(t_envp tenvp)
{
	int		fds[2];
	int		fds1[2];
	int		fds2[2];
	pid_t	pid;
	int		i;

	i = 2;
	while (++i < tenvp.argc - 1)
	{
		if (pipe(fds) == -1)
			error(PIPE_ERROR, "pipe");
		pid = fork();
		if (pid == -1)
			error(FORK_ERROR, "fork");
		if (i == 3)
			start_pid(fds, tenvp);
		else if (i == tenvp.argc - 2)
			end_pid(fds, tenvp);
		else
			working_pid(fds1, fds2, i, tenvp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_envp	tenvp;

	if (argc < 5)
		error(ARGC_ERROR, "");
	tenvp.argc = argc;
	tenvp.argv = argv;
	tenvp.envp = envp;
	tenvp.paths = envp_path(envp);
	working_pid(tenvp);
	return (EXIT_SUCCESS);
}
