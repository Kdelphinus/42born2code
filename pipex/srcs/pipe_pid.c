/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:06:53 by myko              #+#    #+#             */
/*   Updated: 2022/10/26 15:55:23 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_pid(int fds2[], t_envp tenvp)
{
	char	*path;
	char	**new_argv;

	dup2(fds2[1], STDOUT_FILENO);
	close(fds2[0]);
	new_argv = ft_split(ft_strjoin(ft_strjoin(tenvp.argv[2], " "), \
				tenvp.argv[1]), ' ');
	path = ft_path(new_argv[0], tenvp.paths);
	if (!path)
	{
		// all_free(&new_argv);
		error(PATH_ERROR);
	}
	if (execve(path, new_argv, tenvp.envp) == -1)
	{
		// all_free(&new_argv);
		error(RUN_ERROR);
	}
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
	{
		// all_free(&new_argv);
		error(PATH_ERROR);
	}
	if (execve(path, new_argv, tenvp.envp) == -1)
	{
		// all_free(&new_argv);
		error(RUN_ERROR);
	}
}
