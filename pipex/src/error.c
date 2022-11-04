/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:08:04 by myko              #+#    #+#             */
/*   Updated: 2022/11/04 15:50:53 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	error(int errnum, char *problem)
{
	problem = ft_strjoin("pipex: ", problem);
	if (errnum == ARGC_ERROR)
		write(STDERR_FILENO, "pipex: Invaild argument\n", 24);
	else if (errnum == COMMAND_ERROR)
	{
		problem = ft_strjoin(problem, ": command not found\n");
		write(STDERR_FILENO, problem, ft_strlen(problem));
		exit(EXIT_COMMAND_ERROR);
	}
	else if (errnum == PERMISSION_ERROR)
	{
		problem = ft_strjoin(problem, ": permission denied\n");
		write(STDERR_FILENO, problem, ft_strlen(problem));
		exit(126);
	}
	else
		perror(problem);
	exit(EXIT_FAILURE);
}
