/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:45:17 by myko              #+#    #+#             */
/*   Updated: 2022/10/18 15:06:10 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

extern char	**environ;

int	main(int argc, char **argv)
{
	int		i;
	int		*stat = 0;
	char	**new_argv = NULL;
	char	**new_argv2 = NULL;
	char	**tmp = NULL;
	pid_t	pid;

	if (argc != 5)
		return (FAIL);
	pid = fork();
	waitpid(pid, stat, WNOHANG);
	if (pid > 0)
	{
		char	*command = "/bin/";
		i = 0;
		tmp = ft_split(argv[3], ' ');
		new_argv = (char **)malloc(sizeof(char *) * 1000);
		while (tmp[i])
		{
			new_argv[i] = tmp[i];
			i++;
		}
		new_argv[i] = NULL;
		command = ft_strjoin(command, new_argv[0]);
		printf("%s\n", environ[0]);
		printf("parents: %s\n", command);
		if (execve(command, new_argv, environ) == -1)
		{
			fprintf(stderr, "error: %s\n", strerror(errno));
			return (FAIL);
		}
		printf("end\n");
	}
	else if (pid == 0)
	{
		char	*command = "/usr/bin/";
		i = 0;
		tmp = ft_split(argv[2], ' ');
		new_argv2 = (char **)malloc(sizeof(char *) * 1000);
		while (tmp[i])
		{
			new_argv2[i] = tmp[i];
			i++;
		}
		new_argv2[i] = NULL;
		command = ft_strjoin(command, new_argv2[0]);
		printf("child: %s\n", command);
		if (execve(command, new_argv2, environ) == -1)
		{
			fprintf(stderr, "error: %s\n", strerror(errno));
			return (FAIL);
		}
		printf("end\n");
	}
	else
	{
		printf("fork fail\n");
		return (1);
	}
	return (SUCCESS);
}
