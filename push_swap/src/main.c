/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:01:02 by myko              #+#    #+#             */
/*   Updated: 2022/11/16 17:48:28 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (1);
}

int	ft_charp_len(char **charpoint)
{
	int	i;

	i = 0;
	while (charpoint[i])
		i++;
	return (i);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	int			i;
	int			len;
	int			*numbers;
	char		**tmp;
	long long	tmpn;

	if (argc == 1)
		return (0);
	i = -1;
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		if (ft_strncmp(tmp[0], argv[1], ft_strlen(argv[1])) == 0)
			return (0);
		len = ft_charp_len(tmp);
		numbers = (int *)malloc(sizeof(int) * len);
		while (++i < len)
		{
			tmpn = ft_atoi_int(tmp[i]);
			if (tmpn == INT_ERROR)
				return (ft_error());
			numbers[i] = tmpn;
		}
	}
	else
	{
		numbers = (int *)malloc(sizeof(int) * (argc - 1));
		if (!numbers)
			return (ft_error());
		while (++i < argc - 1)
		{
			tmpn = ft_atoi_int(argv[i + 1]);
			if (tmpn == INT_ERROR)
				return (ft_error());
			numbers[i] = tmpn;
		}
	}
	return (0);
}
