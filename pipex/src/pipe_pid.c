/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:06:53 by myko              #+#    #+#             */
/*   Updated: 2022/11/04 01:51:35 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	check_str(char **new_argv)
{
	int	i;

	i = -1;
	while (new_argv[++i])
	{
		if (new_argv[i][0] == 39 || new_argv[i][0] == 34)
			new_argv[i]++;
		if (new_argv[i][ft_strlen(new_argv[i]) - 1] == 39 || \
			new_argv[i][ft_strlen(new_argv[i]) - 1] == 34)
			new_argv[i][ft_strlen(new_argv[i]) - 1] = 0;
	}
}

static char	**exception(int i, t_envp tenvp, char *cmd)
{
	char	**new_argv;

	new_argv = (char **)malloc(sizeof(char *) * 3);
	new_argv[0] = ft_strdup(cmd);
	new_argv[1] = ft_strdup(tenvp.argv[i] + ft_strlen(cmd));
	new_argv[1] = ft_strtrim(new_argv[1], " ");
	if (ft_strncmp(cmd, "sh", 2) == 0)
	{
		if (access(new_argv[1], X_OK) == -1 && access(new_argv[1], F_OK) == 0)
			error(PERMISSION_ERROR, new_argv[1]);
	}
	new_argv[2] = NULL;
	check_str(new_argv);
	return (new_argv);
}

void	child_pid(int fds[], t_envp tenvp)
{
	char	*path;
	char	**new_argv;
	int		fd;

	fd = open(tenvp.argv[1], O_RDONLY);
	if (fd == -1)
		error(ERROR, tenvp.argv[1]);
	if (dup2(fd, STDIN_FILENO) == -1)
		error(ERROR, "fd");
	if (dup2(fds[1], STDOUT_FILENO) == -1)
		error(ERROR, "fd");
	close(fds[0]);
	if (ft_strncmp(tenvp.argv[2], "awk", 3) == 0)
		new_argv = exception(2, tenvp, "awk");
	else if (ft_strncmp(tenvp.argv[2], "sed", 3) == 0)
		new_argv = exception(2, tenvp, "sed");
	else if (ft_strncmp(tenvp.argv[2], "./", 2) == 0)
		new_argv = exception(2, tenvp, "sh");
	else
	{
		new_argv = ft_split(tenvp.argv[2], ' ');
		check_str(new_argv);
	}
	path = ft_path(new_argv[0], tenvp.paths);
	if (!path)
		error(COMMAND_ERROR, new_argv[0]);
	if (execve(path, new_argv, tenvp.envp) == -1)
		error(ERROR, new_argv[0]);
}


void	parent_pid(int fds[], t_envp tenvp)
{
	int		fd;
	char	*path;
	char	**new_argv;

	fd = open(tenvp.argv[4], O_RDWR | O_CREAT | O_TRUNC, 420);
	if (fd == -1)
		error(ERROR, "fd");
	if (dup2(fds[0], STDIN_FILENO) == -1)
		error(ERROR, "fd");
	if (dup2(fd, STDOUT_FILENO) == -1)
		error(ERROR, "fd");
	close(fds[1]);
	if (ft_strncmp(tenvp.argv[3], "awk", 3) == 0)
		new_argv = exception(3, tenvp, "awk");
	else if (ft_strncmp(tenvp.argv[3], "sed", 3) == 0)
		new_argv = exception(3, tenvp, "sed");
	else if (ft_strncmp(tenvp.argv[3], "./", 2) == 0)
		new_argv = exception(3, tenvp, "sh");
	else
	{
		new_argv = ft_split(tenvp.argv[3], ' ');
		check_str(new_argv);
	}
	path = ft_path(new_argv[0], tenvp.paths);
	if (!path)
		error(COMMAND_ERROR, new_argv[0]);
	if (execve(path, new_argv, tenvp.envp) == -1)
	{
		write(2, "error\n", 6);
		error(ERROR, new_argv[0]);
	}
}
