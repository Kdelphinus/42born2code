/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:02:24 by myko              #+#    #+#             */
/*   Updated: 2023/01/06 19:33:07 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	ft_error_checker(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

int	print_ok(void)
{
	ft_putstr_fd("OK\n", STDOUT_FILENO);
	return (0);
}

int	print_ko(void)
{
	ft_putstr_fd("KO\n", STDOUT_FILENO);
	return (0);
}

long long	ft_charp_len(char **charpoint)
{
	long long	i;

	i = 0;
	while (charpoint[i])
		i++;
	if (i == 0)
		ft_error_checker();
	return (i);
}

int	is_duplication_checker(int *arr, int num)
{
	int	i;

	i = -1;
	while (++i < num - 1)
	{
		if (arr[i] == arr[i + 1])
			return (1);
	}
	return (0);
}
