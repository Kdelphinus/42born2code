/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:13:23 by myko              #+#    #+#             */
/*   Updated: 2023/03/02 19:40:07 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_think(t_dining *dining, int id)
{
	long long	think_start;
	long long	curr_time;

	philo_print(dining, "is thinking", id);
	if (dining->t_think <= 1000)
	{
		usleep(dining->t_think * 1000);
		return ;
	}
	think_start = get_time();
	while (dining->die_flag == LIVE)
	{
		curr_time = get_time();
		if (curr_time - think_start >= dining->t_think)
			break ;
		usleep(500);
	}
}
