/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:43:37 by myko              #+#    #+#             */
/*   Updated: 2023/03/03 17:47:32 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_print(t_dining *dining, char *string, int id, long long ts)
{
//	pthread_mutex_lock(&(dining->print));
	if (dining->die_flag == LIVE && dining->eat_flag == NOT_ENOUGH)
		printf("%lld %d %s\n", ts - dining->start_time, id + 1, string);
//	pthread_mutex_unlock(&(dining->print));
}
