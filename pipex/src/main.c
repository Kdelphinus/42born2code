/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:45:17 by myko              #+#    #+#             */
/*   Updated: 2022/11/09 13:06:16 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	working_pid(t_envp tenvp)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) == -1)
		error(ERROR, "pipe");
	pid = fork();
	if (pid == -1)
		error(ERROR, "pipe");
	if (pid == 0)
		child_pid(fds, tenvp);
	else
		parent_pid(fds, tenvp);
}

int	main(int argc, char **argv, char **envp)
{
	t_envp	tenvp;

	if (argc != 5)
		error(ARGC_ERROR, "");
	tenvp.argc = argc;
	tenvp.argv = argv;
	tenvp.envp = envp;
	tenvp.paths = envp_path(envp);
	working_pid(tenvp);
	return (EXIT_SUCCESS);
}
