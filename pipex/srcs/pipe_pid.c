/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:06:53 by myko              #+#    #+#             */
/*   Updated: 2022/10/26 14:07:14 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

void	parent_pid(int fds[], int fds2[], char **argv, char **envp)
{
	int		i;
	int		*b;
	char	*path;
	char	**new_argv;

	i = -1;
	b = (int *)malloc(sizeof(int));
	waitpid(0, b, 0);
	dup2(fds2[0], STDIN_FILENO);
	dup2(fds[1], STDOUT_FILENO);
	close(fds2[1]);
	close(fds[0]);
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