/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:43:37 by myko              #+#    #+#             */
/*   Updated: 2023/03/08 17:10:24 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_print(t_dining *dining, char *string, int id, long long ts)
{
	int flag_d;
	int flag_e;

	pthread_mutex_lock(&dining->die);
	flag_d = dining->die_flag;
	pthread_mutex_unlock(&dining->die);
	if (flag_d == DIE)
		return ;
	pthread_mutex_lock(&dining->eat);
	flag_e = dining->eat_flag;
	pthread_mutex_unlock(&dining->eat);
	if (flag_e == ENOUGH)
		return ;
	printf("%lld %d %s\n", ts - dining->start_time, id + 1, string);
}
