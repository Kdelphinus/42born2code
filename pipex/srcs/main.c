/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:45:17 by myko              #+#    #+#             */
/*   Updated: 2022/10/25 18:56:23 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_path(char *filename, char **envp)
{
	int		i;
	char	*tmp;
	char	**path_option;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			break ;
	}
	path_option = ft_split(envp[i] + 5, ':');
	i = -1;
	while (path_option[++i])
	{
		if (path_option[i][ft_strlen(path_option[i]) - 1] != '/')
			tmp = ft_strjoin(path_option[i], "/");
		tmp = ft_strjoin(tmp, filename);
		if (access(tmp, F_OK) == 0)
			return (tmp);
		free(tmp);
	}
	i = -1;
	while (path_option[++i])
		free(path_option[i]);
	free(path_option);
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		fds[2];
	int		*a;
	pid_t	pid;
	char	*path;
	char	**new_argv;

	if (argc != 5)
	{
		ft_printf("The number of arguments does not match.\n");
		exit(EXIT_FAILURE);
	}
	i = -1;
	if (pipe(fds) == -1)
	{
		ft_printf("pipe error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_printf("fork error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		dup2(fds[1], STDOUT_FILENO);
		close(fds[0]);
		new_argv = ft_split(ft_strjoin(ft_strjoin(argv[2], " "), argv[1]), ' ');
		path = ft_path(new_argv[0], envp);
		if (!path)
		{
			ft_printf("do not have order\n");
			while (new_argv[++i])
				free(new_argv[i]);
			free(new_argv);
			exit(EXIT_FAILURE);
		}
		if (execve(path, new_argv, envp) == -1)
		{
			ft_printf("run error: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		a = (int *)malloc(sizeof(a));
		waitpid(0, a, 0);
		dup2(fds[0], STDIN_FILENO);
		close(fds[1]);
		new_argv = ft_split(argv[3], ' ');
		path = ft_path(new_argv[0], envp);
		if (!path)
		{
			ft_printf("do not have order\n");
			while (new_argv[++i])
				free(new_argv[i]);
			free(new_argv);
			exit(EXIT_FAILURE);
		}
		if (execve(path, new_argv, envp) == -1)
		{
			ft_printf("run error: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
