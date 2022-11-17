/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:01:02 by myko              #+#    #+#             */
/*   Updated: 2022/11/17 16:10:27 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (1);
}

long long	ft_charp_len(char **charpoint)
{
	long long	i;

	i = 0;
	while (charpoint[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_stack		stack;
	char		**tmp;
	long long	tmpn;
	long long	i;
	long long	len;

	if (argc == 1)
		return (0);
	i = -1;
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		if (ft_atoi_int(argv[1]) != INT_ERROR)
			return (0);
		len = ft_charp_len(tmp);
		stack.a = (long long *)malloc(sizeof(long long) * len);
		if (!stack.a)
			return (ft_error());
		stack.a_len = len;
		while (++i < len)
		{
			tmpn = ft_atoi_int(tmp[i]);
			if (tmpn == INT_ERROR)
				return (ft_error());
			stack.a[len - i - 1] = tmpn;
		}
	}
	else
	{
		stack.a = (long long *)malloc(sizeof(long long) * (argc - 1));
		if (!stack.a)
			return (ft_error());
		stack.a_len = argc - 1;
		while (++i < argc - 1)
		{
			tmpn = ft_atoi_int(argv[i + 1]);
			if (tmpn == INT_ERROR)
				return (ft_error());
			stack.a[stack.a_len - i - 1] = tmpn;
		}
	}
	stack.b = (long long *)malloc(sizeof(long long) * i);
	if (!stack.b)
		return (1);
	stack.b_len = 0;
	return (0);
}
