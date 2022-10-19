/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:45:17 by myko              #+#    #+#             */
/*   Updated: 2022/10/19 20:26:29 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strlenp(char **strp)
{
	int	i;

	i = 0;
	while (strp[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int		i;
	int		fdr;
	int		fdw;
	int		fds[2];
	int		len;
	pid_t	pid;
	char	**new_argv;
	char	**split_str;

	i = -1;
	ft_printf("why!!!\n");
	(void)argc;
	fdr = open(argv[1], O_RDONLY);
	fdw = open(argv[3], O_WRONLY);
	if (pipe(fds) == -1)
	{
		fprintf(stderr, "pipe error: %s\n", strerror(errno));
		return (FAIL);
	}
	pid = fork();
	if (pid == -1)
	{
		fprintf(stderr, "fork error: %s\n", strerror(errno));
		return (FAIL);
	}
	if (pid == 0) // 자식 프로세스
	{
		printf("child\n");
		dup2(fds[1], STDOUT_FILENO);
		printf("child2\n");
		close(fds[0]);
		printf("child2\n");
		split_str = ft_split(argv[2], ' ');
		len = ft_strlenp(split_str);
		new_argv = (char **)malloc(sizeof(char *) * (len + 1));
		while (++i < len)
			new_argv[i] = split_str[i];
		new_argv[i] = NULL;
		if (execve("/bin/ls", new_argv, environ) == -1)
		{
			fprintf(stderr, "run error(ls): %s\n", strerror(errno));
			return (FAIL);
		}
	}
	else
	{
		// int	*a;
		// a = (int *)malloc(sizeof(a));
		// printf("%d\n", waitpid(0, a, 0));
		// printf("%d\n", *a);
		printf("parent\n");
		dup2(fds[0], STDIN_FILENO);
		close(fds[1]);
		split_str = ft_split(argv[3], ' ');
		len = ft_strlenp(split_str);
		new_argv = (char **)malloc(sizeof(char *) * (len + 1));
		while (++i < len)
			new_argv[i] = split_str[i];
		new_argv[i] = NULL;
		printf("parent2\n");
		if (execve("/usr/bin/wc", new_argv, environ) == -1)
		{
			fprintf(stderr, "run error(wc): %s\n", strerror(errno));
			return (FAIL);
		}
	}
	printf("the end\n");
	return (SUCCESS);
}
