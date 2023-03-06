/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:56:11 by myko              #+#    #+#             */
/*   Updated: 2023/03/06 21:30:06 by myko             ###   ########.fr       */
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
	pthread_mutex_lock(&dining->death);
	while (dining->die_flag == LIVE)
	{
		pthread_mutex_unlock(&dining->death);
		curr_time = get_time();
		if (curr_time - sleep_start >= dining->t_sleep)
			break ;
		usleep(CHECK_TIME);
		pthread_mutex_lock(&dining->death);
	}
	pthread_mutex_unlock(&dining->death);
}
