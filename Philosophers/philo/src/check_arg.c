/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:28:12 by myko              #+#    #+#             */
/*   Updated: 2023/03/10 14:10:49 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

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

int	ft_atoi(const char *str, int sign)
{
	int			i;
	long long	result;

	i = 0;
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
	if (str[i])
		return (-1);
	return ((int)(result));
}

int	check_arg(int argc, char **argv, t_dining *dining)
{
	if (argc < 5 || argc > 6)
		return (ft_error(ARG_ERROR));
	dining->p_num = ft_atoi(argv[1], 1);
	dining->t_die = ft_atoi(argv[2], 1);
	dining->t_eat = ft_atoi(argv[3], 1);
	dining->t_sleep = ft_atoi(argv[4], 1);
	dining->min_eat = 0;
	dining->die_flag = LIVE;
	dining->eat_flag = NOT_ENOUGH;
	// 4를 나누는 것보다 0.95를 곱하는 것이 유리!
	dining->t_think = (dining->t_die - dining->t_eat - dining->t_sleep) * 0.91;
	if (dining->t_think <= 0)
		dining->t_think = 5;
	if (argc == 6)
		dining->min_eat = ft_atoi(argv[5], 1);
	if (dining->p_num <= 0 || dining->t_die <= 0 || dining->t_eat <= 0 \
		|| dining->t_sleep <= 0 || (argc == 6 && dining->min_eat <= 0))
		return (ft_error(ARG_ERROR));
	if (dining->p_num == 1)
	{
		printf("0 1 has taken a fork\n");
		usleep(dining->t_die * 1000);
		printf("%d 1 died\n", dining->t_die);
	}
	return (SUCCESS_FLAG);
}
