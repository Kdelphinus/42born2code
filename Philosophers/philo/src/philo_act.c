/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:18:18 by myko              #+#    #+#             */
/*   Updated: 2023/03/10 14:08:06 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_sleep(t_dining *dining, int id)
{
	long long	sleep_start;
	long long	curr_time;

	pthread_mutex_lock(&dining->print);
	sleep_start = get_time();
	philo_print(dining, "is sleeping", id, sleep_start);
	pthread_mutex_unlock(&dining->print);
	while (flag_check(dining) == LIVE)
	{
		curr_time = get_time();
		if (curr_time - sleep_start >= dining->t_sleep)
			break ;
		usleep(CHECK_TIME);
	}
}

void	philo_think(t_dining *dining, int id)
{
	long long	think_start;
	long long	curr_time;

	pthread_mutex_lock(&dining->print);
	think_start = get_time();
	philo_print(dining, "is thinking", id, think_start);
	pthread_mutex_unlock(&dining->print);
	while (flag_check(dining) == LIVE)
	{
		curr_time = get_time();
		if (curr_time - think_start >= dining->t_think)
			break ;
		usleep(CHECK_TIME);
	}
}

void	eating(t_dining *dining, long long eat_start)
{
	long long	curr_time;

	while (flag_check(dining) == LIVE)
	{
		curr_time = get_time();
		if (curr_time - eat_start >= dining->t_eat)
			break ;
		usleep(CHECK_TIME);
	}
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
			pthread_mutex_lock(&dining->print);
			philo_print(dining, "has taken a fork", id, get_time());
			philo_print(dining, "has taken a fork", id, get_time());
			pthread_mutex_unlock(&dining->print);
		}
		pthread_mutex_unlock(&dining->pick_up[philo->left_fork]);
		pthread_mutex_unlock(&dining->pick_up[philo->right_fork]);
		if (flag)
			break ;
		usleep(WAIT_TIME);
	}
}

void	philo_eat(t_dining *dining, t_philo *philo, int id)
{
	pick_up_the_fork(dining, philo, id);
	pthread_mutex_lock(&dining->print);
	philo->last_eat = get_time();
	philo_print(dining, "is eating", id, philo->last_eat);
	pthread_mutex_unlock(&dining->print);
	eating(dining, philo->last_eat);
	pthread_mutex_lock(&dining->eat);
	philo->eat_cnt++;
	pthread_mutex_unlock(&dining->eat);
	pthread_mutex_lock(&dining->pick_up[philo->left_fork]);
	pthread_mutex_lock(&dining->pick_up[philo->right_fork]);
	dining->forks[philo->left_fork] = NOT_USING;
	dining->forks[philo->right_fork] = NOT_USING;
	pthread_mutex_unlock(&dining->pick_up[philo->left_fork]);
	pthread_mutex_unlock(&dining->pick_up[philo->right_fork]);
}
