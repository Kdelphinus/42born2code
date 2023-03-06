/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:47:08 by myko              #+#    #+#             */
/*   Updated: 2023/03/06 21:30:39 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	eating(t_dining *dining, long long eat_start)
{
	long long	curr_time;

	pthread_mutex_lock(&dining->death);
	while (1)
	{
		pthread_mutex_unlock(&dining->death);
		curr_time = get_time();
		if (curr_time - eat_start >= dining->t_eat)
			break ;
		usleep(CHECK_TIME);
		pthread_mutex_lock(&dining->death);
	}
	pthread_mutex_unlock(&dining->death);
}

void	pick_up_the_fork(t_dining *dining, t_philo *philo, int id)
{
	int	flag;

	flag = 0;
	while (1)
	{
		pthread_mutex_lock(&dining->pick_up[philo->left_fork]);
		pthread_mutex_lock(&dining->pick_up[philo->right_fork]);
		if (dining->forks[philo->left_fork] == NOT_USING && \
			dining->forks[philo->right_fork] == NOT_USING)
		{
			dining->forks[philo->left_fork] = USING;
			dining->forks[philo->right_fork] = USING;
			flag = 1;
		}
		pthread_mutex_unlock(&dining->pick_up[philo->left_fork]);
		pthread_mutex_unlock(&dining->pick_up[philo->right_fork]);
		if (flag)
			break ;
		usleep(WAIT_TIME);
	}
	pthread_mutex_lock(&dining->print);
	philo_print(dining, "has taken a fork", id, get_time());
	philo_print(dining, "has taken a fork", id, get_time());
	pthread_mutex_unlock(&dining->print);
}

int	philo_eat(t_dining *dining, t_philo *philo, int id)
{
	pick_up_the_fork(dining, philo, id);
	pthread_mutex_lock(&dining->print);
	philo->last_eat = get_time();
	philo_print(dining, "is eating", id, philo->last_eat);
	pthread_mutex_unlock(&dining->print);
	eating(dining, philo->last_eat);
	pthread_mutex_lock(&dining->lock[id]);
	philo->eat_cnt++;
	pthread_mutex_unlock(&dining->lock[id]);
	pthread_mutex_lock(&dining->pick_up[philo->left_fork]);
	dining->forks[philo->left_fork] = NOT_USING;
	pthread_mutex_unlock(&dining->pick_up[philo->left_fork]);
	pthread_mutex_lock(&dining->pick_up[philo->right_fork]);
	dining->forks[philo->right_fork] = NOT_USING;
	pthread_mutex_unlock(&dining->pick_up[philo->right_fork]);
	return (dining->eat_flag);
}
