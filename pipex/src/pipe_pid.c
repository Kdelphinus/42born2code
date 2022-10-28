/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:06:53 by myko              #+#    #+#             */
/*   Updated: 2022/10/28 16:15:58 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_pid(int fds2[], t_envp tenvp)
{
	char	*path;
	char	**new_argv;
	int		fd;

	fd = open(tenvp.argv[1], O_RDONLY);
	dup2(fd, STDIN_FILENO);
	dup2(fds2[1], STDOUT_FILENO);
	close(fds2[0]);
	if (ft_strncmp(tenvp.argv[3], "awk", 3) == 0)
	{
		new_argv = (char **)malloc(sizeof(char *) * 3);
		new_argv[0] = "awk";
		new_argv[1] = tenvp.argv[3] + 4;
		new_argv[2] = NULL;
	}
	else
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
	if (ft_strncmp(tenvp.argv[3], "awk", 3) == 0)
	{
		new_argv = (char **)malloc(sizeof(char *) * 3);
		new_argv[0] = "awk";
		new_argv[1] = tenvp.argv[3] + 4;
		new_argv[2] = NULL;
	}
	else
		new_argv = ft_split(tenvp.argv[3], ' ');
	path = ft_path(new_argv[0], tenvp.paths);
	if (!path)
		error(PATH_ERROR);
	if (execve(path, new_argv, tenvp.envp) == -1)
		error(RUN_ERROR);
}
