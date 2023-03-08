/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:13:23 by myko              #+#    #+#             */
/*   Updated: 2023/03/08 17:00:36 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_think(t_dining *dining, int id)
{
	int 		flag;
	long long	think_start;
	long long	curr_time;

	pthread_mutex_lock(&dining->print);
	think_start = get_time();
	philo_print(dining, "is thinking", id, think_start);
	pthread_mutex_unlock(&dining->print);
	while (1)
	{
		pthread_mutex_lock(&dining->die);
		flag = dining->die_flag;
		pthread_mutex_unlock(&dining->die);
		if (flag == DIE)
			break ;
		curr_time = get_time();
		if (curr_time - think_start >= dining->t_think)
			break ;
		usleep(CHECK_TIME);
	}
}
