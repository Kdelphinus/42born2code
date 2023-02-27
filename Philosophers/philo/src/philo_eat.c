/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:47:08 by myko              #+#    #+#             */
/*   Updated: 2023/02/27 19:32:20 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	eating(t_dining *dining)
{
	long long	eat_start;
	long long	curr_time;

	eat_start = get_time();
	while (dining->die_flag == LIVE)
	{
		curr_time = get_time();
		if (curr_time - eat_start >= dining->t_eat)
			break ;
		usleep(10);
	}
}

void	philo_eat(t_dining *dining, t_philo *philo, int id)
{
	pthread_mutex_lock(&(dining->forks[philo->left_fork]));
	philo_print(dining, "has taken a fork", id);
	pthread_mutex_lock(&(dining->forks[philo->right_fork]));
	philo_print(dining, "has taken a fork", id);
	pthread_mutex_lock(&(dining->lock));
	philo_print(dining, "is eating", id);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&(dining->lock));
	philo->eat_cnt++;
	eating(dining);
	pthread_mutex_unlock(&(dining->forks[philo->left_fork]));
	pthread_mutex_unlock(&(dining->forks[philo->right_fork]));
}
