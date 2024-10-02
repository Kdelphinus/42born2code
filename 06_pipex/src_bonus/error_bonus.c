/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:08:04 by myko              #+#    #+#             */
/*   Updated: 2022/11/09 13:11:19 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	error(int errnum, char *problem)
{
	problem = ft_strjoin("pipex: ", problem);
	if (errnum == ARGC_ERROR)
		ft_putstr_fd("pipex: Invaild argument\n", STDERR_FILENO);
	else if (errnum == COMMAND_ERROR)
	{
		problem = ft_strjoin(problem, ": command not found\n");
		ft_putstr_fd(problem, STDERR_FILENO);
		exit(EXIT_COMMAND_ERROR);
	}
	else if (errnum == PERMISSION_ERROR)
	{
		problem = ft_strjoin(problem, ": permission denied\n");
		ft_putstr_fd(problem, STDERR_FILENO);
		exit(EXIT_PERMOSSION_ERROR);
	}
	else
		perror(problem);
	exit(EXIT_FAILURE);
}
