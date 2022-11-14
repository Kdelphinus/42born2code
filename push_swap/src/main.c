/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:01:02 by myko              #+#    #+#             */
/*   Updated: 2022/11/14 16:08:05 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (1);
}

//TODO 하나의 인자로 모든 수가 들어오는 것과 한 개의 수만 들어오는 것을 어떻게 구분할 것인가
int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	return (0);
}
