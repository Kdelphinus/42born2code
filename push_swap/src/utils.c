/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:20:33 by myko              #+#    #+#             */
/*   Updated: 2023/01/04 21:44:25 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

long long	ft_charp_len(char **charpoint)
{
	long long	i;

	i = 0;
	while (charpoint[i])
		i++;
	return (i);
}

int	is_duplication(int *arr, int num)
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

long long	min(long long a, long long b)
{
	if (a < b)
		return (a);
	return (b);
}
