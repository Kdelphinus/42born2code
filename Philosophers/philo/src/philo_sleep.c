/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:56:11 by myko              #+#    #+#             */
/*   Updated: 2023/02/27 19:59:00 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_sleep(t_dining *dining, int id)
{
	long long	sleep_start;
	long long	curr_time;

	philo_print(dining, "is sleeping", id);
	sleep_start = get_time();
	while (dining->die_flag == LIVE)
	{
		curr_time = get_time();
		if (curr_time - sleep_start >= dining->t_sleep)
			break ;
		usleep(10);
	}
}
