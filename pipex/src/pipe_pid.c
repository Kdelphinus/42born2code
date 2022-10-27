/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:06:53 by myko              #+#    #+#             */
/*   Updated: 2022/10/27 19:33:15 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_pid(int fds2[], t_envp tenvp)
{
	char	*path;
	char	**new_argv;
	int		fd;

	fd = open(tenvp.argv[1], O_RDONLY);
	// dup2(STDIN_FILENO, fd);
	dup2(fd, STDIN_FILENO);
	dup2(fds2[1], STDOUT_FILENO);
	close(fds2[0]);
	new_argv = ft_split(tenvp.argv[2], ' ');
	path = ft_path(new_argv[0], tenvp.paths);
	if (!path)
		error(PATH_ERROR);
	if (execve(path, new_argv, tenvp.envp) == -1)
		error(RUN_ERROR);
}

void	parent_pid(int fds[], int fds2[], t_envp tenvp)
{
	int		b;
	char	*path;
	char	**new_argv;

	wait(&b);
	dup2(fds2[0], STDIN_FILENO);
	dup2(fds[1], STDOUT_FILENO);
	close(fds2[1]);
	close(fds[0]);
	new_argv = ft_split(tenvp.argv[3], ' ');
	path = ft_path(new_argv[0], tenvp.paths);
	if (!path)
		error(PATH_ERROR);
	if (execve(path, new_argv, tenvp.envp) == -1)
		error(RUN_ERROR);
}
