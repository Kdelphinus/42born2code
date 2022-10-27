/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:08:04 by myko              #+#    #+#             */
/*   Updated: 2022/10/26 18:13:31 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	error(int errnum)
{
	if (errnum == ARGC_ERROR)
		ft_printf("The number of arguments does not match.\n");
	else if (errnum == PIPE_ERROR)
		ft_printf("pipe error: %s\n", strerror(errno));
	else if (errnum == FORK_ERROR)
		ft_printf("fork error: %s\n", strerror(errno));
	else if (errnum == PATH_ERROR)
		ft_printf("do not have file\n");
	else if (errnum == RUN_ERROR)
		ft_printf("run error: %s\n", strerror(errno));
	exit(EXIT_FAILURE);
}
