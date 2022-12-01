/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:45:17 by myko              #+#    #+#             */
/*   Updated: 2022/12/01 17:00:34 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	working_pid(t_envp tenvp)
{
	int		fds[2];
	int		fds2[2];
	pid_t	pid;
	int		i;
	int		status;

	i = 1;
	if (pipe(fds) == -1)
		error(PIPE_ERROR, "pipe");
	while (++i < tenvp.argc - 1)
	{
		if (pipe(fds2) == -1)
			error(PIPE_ERROR, "pipe");
		pid = fork();
		if (pid == -1)
			error(FORK_ERROR, "fork");
		if (pid == 0)
		{
			if (i == 2)
				start_pid(fds, tenvp);
			else if (i == tenvp.argc - 2)
				end_pid(fds, tenvp);
			else
				mid_pid(fds, fds2, i, tenvp);
		}
		else
		{
			if (waitpid(pid, &status, WNOHANG) == -1)
				error(RUN_ERROR, "pid");

		}
		dup2(fds[0], fds2[0]);
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
