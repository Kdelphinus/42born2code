/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:08:04 by myko              #+#    #+#             */
/*   Updated: 2022/11/02 16:30:06 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	error(int errnum, char *problem)
{
	problem = ft_strjoin("pipex: ", problem);
	if (errnum == ARGC_ERROR)
		write(STDERR_FILENO, "The number of arguments does not match.\n", 41);
	else if (errnum == COMMAND_ERROR)
	{
		problem = ft_strjoin(problem, ": command not found\n");
		write(STDERR_FILENO, problem, ft_strlen(problem));
		exit(127);
	}
	else if (errnum == PIPE_ERROR)
		perror(problem);
	else if (errnum == FORK_ERROR)
		perror(problem);
	else if (errnum == PATH_ERROR)
		perror(problem);
	else if (errnum == RUN_ERROR)
		perror(problem);
	else if (errnum == FILE_ERROR)
		perror(problem);
	else
		perror(problem);
	exit(EXIT_FAILURE);
}
