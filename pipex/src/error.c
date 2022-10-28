/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:08:04 by myko              #+#    #+#             */
/*   Updated: 2022/10/28 16:29:15 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	error(int errnum)
{
	if (errnum == ARGC_ERROR)
		ft_printf("The number of arguments does not match.\n");
	else if (errnum == PIPE_ERROR)
		perror("PIPE");
	else if (errnum == FORK_ERROR)
		perror("FORK");
	else if (errnum == PATH_ERROR)
		perror("PATH");
	else if (errnum == RUN_ERROR)
		perror("RUN");
	exit(EXIT_FAILURE);
}
