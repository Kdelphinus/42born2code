/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:45:17 by myko              #+#    #+#             */
/*   Updated: 2022/12/02 18:05:19 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	working_pid(t_envp tenvp)
{
	int		fds[2];
	pid_t	pid;
	int		i;
	int		status;

	i = 1;
	while (++i < tenvp.argc - 2)
	{
		if (pipe(fds) == -1)
			error(PIPE_ERROR, "pipe");
		pid = fork();
		if (pid == -1)
			error(FORK_ERROR, "fork");
		if (pid == 0)
		{
			dup2(fds[1], STDOUT_FILENO);
			close(fds[0]);
			work_pid(i, tenvp);
		}
		else
		{
			if (waitpid(pid, &status, WNOHANG) == -1)
				error(RUN_ERROR, "pid");
			dup2(fds[0], STDIN_FILENO);
			close(fds[1]);

		}
	}
	work_pid(i, tenvp);
}

int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;
	t_envp	tenvp;

	if (argc < 5)
		error(ARGC_ERROR, "");
	tenvp.argc = argc;
	tenvp.argv = argv;
	tenvp.envp = envp;
	tenvp.paths = envp_path(envp);
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 420);
	if (outfile == -1)
		error(FD_ERROR, "fd");
	if (infile != -1)
		dup2(infile, STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	working_pid(tenvp);
	return (EXIT_SUCCESS);
}
