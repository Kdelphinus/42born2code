/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:25:32 by myko              #+#    #+#             */
/*   Updated: 2023/01/04 19:46:49 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	overflow_up_check(long long result, char num)
{
	if (result == 214748364 && num > '7')
		return (0);
	if (result > 214748364)
		return (0);
	return (1);
}

static int	overflow_down_check(long long result, char num)
{
	if (result == -214748364 && num > '8')
		return (0);
	if (result < -214748364)
		return (0);
	return (1);
}

static void	over_check(long long result, char c)
{
	if (!overflow_up_check(result, c))
		ft_error();
	if (!overflow_down_check(result, c))
		ft_error();
}

long long	ft_atoi_int(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		ft_error();
	while (ft_isdigit(str[i]))
	{
		over_check(result, str[i]);
		result = result * 10 + (str[i] - '0') * sign;
		i++;
	}
	if (str[i])
		ft_error();
	return (result);
}
