/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:17:18 by myko              #+#    #+#             */
/*   Updated: 2022/07/13 16:07:50 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflow_up_check(long long result, char num)
{	
	if (result == 922337203685477580 && num > '7')
		return (0);
	if (result > 922337203685477580)
		return (0);
	return (1);
}

static int	overflow_down_check(long long result, char num)
{
	if (result == -922337203685477580 && num > '8')
		return (0);
	if (result < -922337203685477580)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (!overflow_up_check(result, str[i]))
			return (-1);
		if (!overflow_down_check(result, str[i]))
			return (0);
		result = result * 10 + (str[i] - '0') * sign;
		i++;
	}
	return (result);
}
