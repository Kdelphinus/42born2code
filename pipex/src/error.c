/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:08:04 by myko              #+#    #+#             */
/*   Updated: 2022/11/01 18:25:47 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	error(int errnum, char *problem)
{
	problem = ft_strjoin("pipex: ", problem);
	if (errnum == ARGC_ERROR)
		write(2, "The number of arguments does not match.\n", 41);
	else if (errnum == COMMAND_ERROR)
	{
		problem = ft_strjoin(problem, ": command not found\n");
		write(2, problem, ft_strlen(problem));
	}
	else if (errnum == PIPE_ERROR)
		perror("PIPE");
	else if (errnum == FORK_ERROR)
		perror("FORK");
	else if (errnum == PATH_ERROR)
		perror("PATH");
	else if (errnum == RUN_ERROR)
		perror(problem);
	else if (errnum == FILE_ERROR)
		perror(problem);
	exit(EXIT_FAILURE);
}
