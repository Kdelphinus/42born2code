/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:18:16 by myko              #+#    #+#             */
/*   Updated: 2023/03/06 14:37:00 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long long	get_time(void)
{
	long long		l_time;
	struct timeval	curr_time;

	gettimeofday(&curr_time, NULL);
	l_time = curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000;
	return (l_time);
}
