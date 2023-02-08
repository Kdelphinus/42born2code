/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:23:15 by myko              #+#    #+#             */
/*   Updated: 2023/02/08 18:57:46 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	thinking(int philo_num)
{
	printf("timestamp_in_ms %i is thinking\n", philo_num);
	usleep(1000 * 1000);
}

void	eating(int philo_num)
{
	printf("timestamp_in_ms %i is eating\n", philo_num);
	usleep(1000 * 1000);
}

void	sleeping(int philo_num)
{
	printf("timestamp_in_ms %i is sleeping\n", philo_num);
	usleep(1000 * 1000);
}
