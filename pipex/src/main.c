/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:45:17 by myko              #+#    #+#             */
/*   Updated: 2022/11/01 19:35:07 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	working_pid(int fds[], t_envp tenvp)
{
	int		fds2[2];
	pid_t	pid;

	if (pipe(fds2) == -1)
		error(PIPE_ERROR, "pipe");
	pid = fork();
	if (pid == -1)
		error(FORK_ERROR, "pipe");
	if (pid == 0)
		child_pid(fds2, tenvp);
	else
		parent_pid(fds, fds2, tenvp);
}

static void	result_pid(pid_t pid, int fds[], char *outfile)
{
	int		status;
	int		fd;
	int		rd;
	char	buff[10000];
	pid_t	tmp;

	dup2(fds[0], STDIN_FILENO);
	close(fds[1]);
	status = 0;
	tmp = waitpid(pid, &status, 0);
	fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 420);
	rd = read(fds[0], buff, sizeof(buff) - 1);
	buff[rd] = 0;
	write(fd, buff, rd);
	close(fd);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		exit(WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	int		fds[2];
	pid_t	pid;
	t_envp	tenvp;

	if (argc != 5)
		error(ARGC_ERROR, "");
	tenvp.argc = argc;
	tenvp.argv = argv;
	tenvp.envp = envp;
	tenvp.paths = envp_path(envp);
	if (pipe(fds) == -1)
		error(PIPE_ERROR, "pipe");
	pid = fork();
	if (pid == -1)
		error(FORK_ERROR, "fork");
	if (pid == 0)
		working_pid(fds, tenvp);
	else
		result_pid(pid, fds, argv[4]);
	return (EXIT_SUCCESS);
}
