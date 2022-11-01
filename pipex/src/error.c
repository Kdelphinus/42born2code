/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:08:04 by myko              #+#    #+#             */
/*   Updated: 2022/11/01 16:33:23 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	error(int errnum, char *problem)
{
	problem = ft_strjoin("pipex: ", problem);
	if (errnum == ARGC_ERROR)
		ft_printf("The number of arguments does not match.\n");
	else if (errnum == COMMAND_ERROR)
		perror(problem);
	else if (errnum == PIPE_ERROR)
		perror("PIPE");
	else if (errnum == FORK_ERROR)
		perror("FORK");
	else if (errnum == PATH_ERROR)
		perror("PATH");
	else if (errnum == RUN_ERROR)
		perror("RUN");
	else if (errnum == FILE_ERROR)
		perror(problem);
	exit(EXIT_FAILURE);
}
