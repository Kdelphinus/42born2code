/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:06:53 by myko              #+#    #+#             */
/*   Updated: 2022/11/04 09:53:39 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	check_str(char **new_argv)
{
	int	i;

	i = -1;
	while (new_argv[++i])
	{
		if (new_argv[i][0] == '\'' || new_argv[i][0] == '"')
			new_argv[i]++;
		if (new_argv[i][ft_strlen(new_argv[i]) - 1] == '\'' || \
			new_argv[i][ft_strlen(new_argv[i]) - 1] == '"')
			new_argv[i][ft_strlen(new_argv[i]) - 1] = 0;
	}
}

static char	**exception(int i, t_envp tenvp, char *cmd)
{
	char	**new_argv;

	new_argv = (char **)malloc(sizeof(char *) * 3);
	new_argv[0] = ft_strdup(cmd);
	new_argv[1] = ft_strdup(tenvp.argv[i] + ft_strlen(cmd));
	new_argv[1] = ft_strtrim(new_argv[1], " 	");
	new_argv[2] = NULL;
	if (ft_strncmp(cmd, "sh", 2) == 0)
	{
		if (access(new_argv[1], X_OK) == -1 \
			&& access(new_argv[1], F_OK) == 0)
			error(PERMISSION_ERROR, new_argv[1]);
	}
	check_str(new_argv);
	return (new_argv);
}

static char	**argv_init(int i, t_envp tenvp)
{
	char	**new_argv;

	if (ft_strncmp(tenvp.argv[i], "awk", 3) == 0)
		new_argv = exception(i, tenvp, "awk");
	else if (ft_strncmp(tenvp.argv[i], "sed", 3) == 0)
		new_argv = exception(i, tenvp, "sed");
	else if (ft_strncmp(tenvp.argv[i], "./", 2) == 0)
		new_argv = exception(i, tenvp, "sh");
	else if (ft_strncmp(tenvp.argv[i], "grep", 4) == 0)
		new_argv = exception(i, tenvp, "grep");
	else
	{
		new_argv = ft_split_set(tenvp.argv[i], " 	");
		check_str(new_argv);
	}
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
	if (dup2(fd, STDIN_FILENO) == -1 || dup2(fds[1], STDOUT_FILENO) == -1)
		error(ERROR, "fd");
	close(fds[0]);
	new_argv = argv_init(2, tenvp);
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
	if (dup2(fds[0], STDIN_FILENO) == -1 || dup2(fd, STDOUT_FILENO) == -1)
		error(ERROR, "fd");
	close(fds[1]);
	new_argv = argv_init(3, tenvp);
	path = ft_path(new_argv[0], tenvp.paths);
	if (!path)
		error(COMMAND_ERROR, new_argv[0]);
	if (execve(path, new_argv, tenvp.envp) == -1)
		error(ERROR, new_argv[0]);
}
