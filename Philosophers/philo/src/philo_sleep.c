/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:56:11 by myko              #+#    #+#             */
/*   Updated: 2023/03/04 15:41:01 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_sleep(t_dining *dining, int id)
{
	long long	sleep_start;
	long long	curr_time;

	pthread_mutex_lock(&dining->print);
	sleep_start = get_time();
	philo_print(dining, "is sleeping", id, sleep_start);
	pthread_mutex_unlock(&dining->print);
	while (dining->die_flag == LIVE)
	{
		curr_time = get_time();
		if (curr_time - sleep_start >= dining->t_sleep)
			break ;
		usleep(CHECK_TIME);
	}
}
