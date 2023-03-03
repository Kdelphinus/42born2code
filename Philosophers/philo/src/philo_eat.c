/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:47:08 by myko              #+#    #+#             */
/*   Updated: 2023/03/03 17:57:19 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	eating(t_dining *dining, long long eat_start)
{
//	long long	eat_start;
	long long	curr_time;

//	eat_start = get_time();
	while (dining->die_flag == LIVE)
	{
		curr_time = get_time();
		if (curr_time - eat_start >= dining->t_eat)
			break ;
		usleep(CHECK_TIME);
	}
}

void	pick_up_the_fork(t_dining *dining, t_philo *philo, int id)
{
	long long pick_time;

	while (1)
	{
		pick_time = -1;
		pthread_mutex_lock(&dining->pick_up[philo->left_fork]);
		pthread_mutex_lock(&dining->pick_up[philo->right_fork]);
		if (dining->forks[philo->left_fork] == NOT_USING && \
			dining->forks[philo->right_fork] == NOT_USING)
		{
			dining->forks[philo->left_fork] = USING;
			dining->forks[philo->right_fork] = USING;
			pick_time = get_time();
		}
		pthread_mutex_unlock(&dining->pick_up[philo->left_fork]);
		pthread_mutex_unlock(&dining->pick_up[philo->right_fork]);
		if (pick_time != -1)
			break ;
		usleep(100);
	}
	philo_print(dining, "has taken a fork", id, pick_time);
	philo_print(dining, "has taken a fork", id, pick_time);
//	while (1)
//	{
//		while (dining->forks[philo->left_fork] == USING)
//			usleep(10);
//		pthread_mutex_lock(&dining->pick_up[philo->left_fork]);
//		dining->forks[philo->left_fork] = USING;
//		if (dining->forks[philo->right_fork] == NOT_USING)
//		{
//			pthread_mutex_lock(&dining->pick_up[philo->right_fork]);
//			dining->forks[philo->right_fork] = USING;
//			pthread_mutex_unlock(&dining->pick_up[philo->right_fork]);
//			pthread_mutex_unlock(&dining->pick_up[philo->left_fork]);
//			pthread_mutex_lock(&dining->print); //
//			pick_time = get_time();
//			philo_print(dining, "has taken a fork", id, pick_time);
//			philo_print(dining, "has taken a fork", id, pick_time);
//			pthread_mutex_unlock(&dining->print); //
//			return ;
//		}
//		dining->forks[philo->left_fork] = NOT_USING;
//		pthread_mutex_unlock(&dining->pick_up[philo->left_fork]);
//	}
}

int	philo_eat(t_dining *dining, t_philo *philo, int id)
{
	pick_up_the_fork(dining, philo, id);
	pthread_mutex_lock(&dining->print); //
	philo->last_eat = get_time();
	philo_print(dining, "is eating", id, philo->last_eat);
	pthread_mutex_unlock(&dining->print); //
	eating(dining, philo->last_eat);
	philo->eat_cnt++;
	pthread_mutex_lock(&dining->pick_up[philo->left_fork]);
	dining->forks[philo->left_fork] = NOT_USING;
	pthread_mutex_unlock(&dining->pick_up[philo->left_fork]);
	pthread_mutex_lock(&dining->pick_up[philo->right_fork]);
	dining->forks[philo->right_fork] = NOT_USING;
	pthread_mutex_unlock(&dining->pick_up[philo->right_fork]);
	return (dining->eat_flag);
}
