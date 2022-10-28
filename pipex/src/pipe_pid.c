/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:06:53 by myko              #+#    #+#             */
/*   Updated: 2022/10/28 20:19:44 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static	void	check_str(char **new_argv)
{
	int	i;

	i = -1;
	while (new_argv[++i])
	{
		if (new_argv[i][0] == 39 || new_argv[i][0] == 34)
			new_argv[i]++;
		if (new_argv[i][ft_strlen(new_argv[i]) - 1] == 39 || new_argv[i][ft_strlen(new_argv[i]) - 1] == 34)
			new_argv[i][ft_strlen(new_argv[i]) - 1] = 0;
		// if (new_argv[i][0] == 39 && new_argv[i][ft_strlen(new_argv[i]) - 1] == 39)
		// {
		// 	new_argv[i]++;
		// 	new_argv[i][ft_strlen(new_argv[i]) - 1] = 0;
		// }
		// else if (new_argv[i][0] == 34 && new_argv[i][ft_strlen(new_argv[i]) - 1] == 34)
		// {
		// 	new_argv[i]++;
		// 	new_argv[i][ft_strlen(new_argv[i]) - 1] = 0;
		// }
	}
}

void	child_pid(int fds2[], t_envp tenvp)
{
	char	*path;
	char	**new_argv;
	int		fd;

	fd = open(tenvp.argv[1], O_RDONLY);
	dup2(fd, STDIN_FILENO);
	dup2(fds2[1], STDOUT_FILENO);
	close(fds2[0]);
	if (ft_strncmp(tenvp.argv[2], "awk", 3) == 0)
	{
		new_argv = (char **)malloc(sizeof(char *) * 3);
		new_argv[0] = ft_strdup("awk");
		new_argv[1] = ft_strdup(tenvp.argv[2] + 5);
		new_argv[1][ft_strlen(new_argv[1]) - 1] = 0;
		new_argv[2] = NULL;
	}
	else
	{
		new_argv = ft_split(tenvp.argv[2], ' ');
		check_str(new_argv);
	}
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
		new_argv[0] = ft_strdup("awk");
		new_argv[1] = ft_strdup(tenvp.argv[3] + 5);
		new_argv[1][ft_strlen(new_argv[1]) - 1] = 0;
		new_argv[2] = NULL;
	}
	else
	{
		new_argv = ft_split(tenvp.argv[3], ' ');
		check_str(new_argv);
	}
	path = ft_path(new_argv[0], tenvp.paths);
	if (!path)
		error(PATH_ERROR);
	if (execve(path, new_argv, tenvp.envp) == -1)
		error(RUN_ERROR);
}
