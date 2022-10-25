/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:45:17 by myko              #+#    #+#             */
/*   Updated: 2022/10/25 20:12:27 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	all_free(char ***tmp)
{
	int	i;

	i = -1;
	while (*tmp[++i])
		free(*tmp[i]);
	free(*tmp);
}

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
	all_free(&path_option);
	return (NULL);
}

void	child_pid(int fds2[], char **argv, char **envp)
{
	int		i;
	char	*path;
	char	**new_argv;

	i = -1;
	dup2(fds2[1], STDOUT_FILENO);
	close(fds2[0]);
	new_argv = ft_split(ft_strjoin(ft_strjoin(argv[2], " "), argv[1]), ' ');
	path = ft_path(new_argv[0], envp);
	if (!path)
	{
		ft_printf("do not have order\n");
		all_free(&new_argv);
		exit(EXIT_FAILURE);
	}
	if (execve(path, new_argv, envp) == -1)
	{
		ft_printf("run error: %s\n", strerror(errno));
		all_free(&new_argv);
		exit(EXIT_FAILURE);
	}
}

void	parent_pid(int fds2[], char **argv, char **envp)
{
	int		i;
	int		*b;
	char	*path;
	char	**new_argv;

	i = -1;
	b = (int *)malloc(sizeof(int));
	waitpid(0, b, 0);
	dup2(fds2[0], STDIN_FILENO);
	close(fds2[1]);
	new_argv = ft_split(argv[3], ' ');
	path = ft_path(new_argv[0], envp);
	if (!path)
	{
		ft_printf("do not have order\n");
		all_free(&new_argv);
		exit(EXIT_FAILURE);
	}
	if (execve(path, new_argv, envp) == -1)
	{
		ft_printf("run error: %s\n", strerror(errno));
		all_free(&new_argv);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fds[2];
	int		fds2[2];
	int		*a;
	pid_t	pid;
	pid_t	pid2;

	if (argc != 5)
	{
		ft_printf("The number of arguments does not match.\n");
		exit(EXIT_FAILURE);
	}
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
		if (pipe(fds2) == -1)
		{
			ft_printf("pipe error: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
		pid2 = fork();
		if (pid2 == -1)
		{
			ft_printf("fork error: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
		if (pid2 == 0)
			child_pid(fds2, argv, envp);
		else
			parent_pid(fds2, argv, envp);
		int	rd;
		char *buff;
		buff = malloc(1000001);
		rd = read(fds2[0], buff, 1000000);
		buff[rd] = 0;
		printf("read: %s\n read end\n", buff);
	}
	else
	{
		a = (int *)malloc(sizeof(int));
		waitpid(0, a, 0);
		// printf("end\n");
		// int	rd;
		// char *buff;
		// buff = malloc(1000001);
		// rd = read(0, buff, 1000000);
		// buff[rd] = 0;
		// printf("read: %s\n read end\n", buff);
	}
	return (0);
}
