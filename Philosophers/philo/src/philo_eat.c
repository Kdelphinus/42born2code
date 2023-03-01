/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:47:08 by myko              #+#    #+#             */
/*   Updated: 2023/03/01 16:46:10 by myko             ###   ########.fr       */
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

int	philo_eat(t_dining *dining, t_philo *philo, int id)
{
	while (dining->forks[philo->left_fork] == USING \
		|| dining->forks[philo->right_fork] == USING)
		;
	pthread_mutex_lock(&dining->pick_up);
	dining->forks[philo->left_fork] = USING;
	dining->forks[philo->right_fork] = USING;
	pthread_mutex_unlock(&dining->pick_up);
	philo_print(dining, "has taken a fork", id);
	philo_print(dining, "has taken a fork", id);
	philo_print(dining, "is eating", id);
	philo->last_eat = get_time();
	philo->eat_cnt++;
	eating(dining);
	pthread_mutex_lock(&dining->pick_up);
	dining->forks[philo->left_fork] = NOT_USING;
	dining->forks[philo->right_fork] = NOT_USING;
	pthread_mutex_unlock(&dining->pick_up);
	return (dining->eat_flag);
}
