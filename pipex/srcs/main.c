/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:45:17 by myko              #+#    #+#             */
/*   Updated: 2022/10/19 19:19:48 by myko             ###   ########.fr       */
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
	int		fd[2];
	int		len;
	pid_t	pid;
	char	**new_argv;
	char	**split_str;

	i = -1;
	(void)argc;
	if (pipe(fd) == -1)
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
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		split_str = ft_split(argv[1], ' ');
		len = ft_strlenp(split_str);
		new_argv = (char **)malloc(sizeof(char *) * (len + 1));
		while (++i < len)
			new_argv[i] = split_str[i];
		new_argv[i] = NULL;
		// 되는 경로 계속 붙이기
		if (execve("/bin/ls", new_argv, environ) == -1)
		{
			fprintf(stderr, "run error(ls): %s\n", strerror(errno));
			return (FAIL);
		}
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	split_str = ft_split(argv[2], ' ');
	len = ft_strlenp(split_str);
	new_argv = (char **)malloc(sizeof(char *) * (len + 1));
	while (++i < len)
		new_argv[i] = split_str[i];
	new_argv[i] = NULL;
	if (execve("/usr/bin/wc", new_argv, environ) == -1)
	{
		fprintf(stderr, "run error(wc): %s\n", strerror(errno));
		return (FAIL);
	}
	char	line[255];
	while (fgets(line, sizeof(line), stdin) != 0)
		printf("%s", line);
	return (SUCCESS);
}
