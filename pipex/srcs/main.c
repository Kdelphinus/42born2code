/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:45:17 by myko              #+#    #+#             */
/*   Updated: 2022/10/26 14:15:52 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fds[2];
	int		fds2[2];
	int		*a;
	pid_t	pid;
	pid_t	pid2;

	if (argc != 5)
		error(ARGC_ERROR);
	if (pipe(fds) == -1)
		error(PIPE_ERROR);
	pid = fork();
	if (pid == -1)
		error(FORK_ERROR);
	if (pid == 0)
	{
		if (pipe(fds2) == -1)
			error(FORK_ERROR);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[0]);
		pid2 = fork();
		if (pid2 == -1)
			error(PIPE_ERROR);
		if (pid2 == 0)
			child_pid(fds2, argv, envp);
		else
			parent_pid(fds, fds2, argv, envp);
	}
	else
	{
		a = (int *)malloc(sizeof(int));
		waitpid(0, a, WNOHANG);
		dup2(fds[0], STDIN_FILENO);
		close(fds[1]);
		int	fd;
		fd = open(argv[4], O_WRONLY);
		char buff[10000];
		int	rd;
		rd = read(fds[0], buff, sizeof(buff) - 1);
		buff[rd] = 0;
		write(fd, buff, rd);
		close(fd);
	}
	return (0);
}
