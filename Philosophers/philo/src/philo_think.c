/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:13:23 by myko              #+#    #+#             */
/*   Updated: 2023/03/04 15:41:09 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_think(t_dining *dining, int id)
{
	long long	think_start;
	long long	curr_time;

	pthread_mutex_lock(&dining->print);
	think_start = get_time();
	philo_print(dining, "is thinking", id, think_start);
	pthread_mutex_unlock(&dining->print);
	while (dining->die_flag == LIVE)
	{
		curr_time = get_time();
		if (curr_time - think_start >= dining->t_think)
			break ;
		usleep(CHECK_TIME);
	}
}
