/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:42:02 by myko              #+#    #+#             */
/*   Updated: 2023/03/08 18:00:12 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	flag_check(t_dining *dining)
{
	int	flag_d;
	int	flag_e;

	pthread_mutex_lock(&dining->die);
	flag_d = dining->die_flag;
	pthread_mutex_unlock(&dining->die);
	if (flag_d == DIE)
		return (DIE);
	pthread_mutex_lock(&dining->eat);
	flag_e = dining->eat_flag;
	pthread_mutex_unlock(&dining->eat);
	if (flag_e == ENOUGH)
		return (DIE);
	return (LIVE);
}

void	eat_check(t_dining *dining)
{
	int	i;
	int	tmp;
	int	cnt;

	i = -1;
	cnt = dining->min_eat;
	if (cnt == 0)
		return ;
	while (++i < dining->p_num)
	{
		pthread_mutex_lock(&dining->eat);
		tmp = dining->philos[i].eat_cnt;
		pthread_mutex_unlock(&dining->eat);
		if (tmp < cnt)
			break ;
	}
	if (i == dining->p_num)
	{
		pthread_mutex_lock(&dining->eat);
		dining->eat_flag = ENOUGH;
		pthread_mutex_unlock(&dining->eat);
	}
}

void	philo_check(t_dining *dining)
{
	int			i;
	long long	curr_time;

	while (dining->eat_flag == NOT_ENOUGH)
	{
		i = -1;
		while (++i < dining->p_num && dining->die_flag == LIVE)
		{
			pthread_mutex_lock(&dining->print);
			curr_time = get_time();
			if (curr_time - dining->philos[i].last_eat > dining->t_die)
			{
				philo_print(dining, "died", i, curr_time);
				pthread_mutex_lock(&dining->die);
				dining->die_flag = DIE;
				pthread_mutex_unlock(&dining->die);
			}
			pthread_mutex_unlock(&dining->print);
		}
		if (dining->die_flag == DIE)
			break ;
		eat_check(dining);
	}
}
