/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:47:08 by myko              #+#    #+#             */
/*   Updated: 2023/03/02 11:38:42 by myko             ###   ########.fr       */
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
	if (id % 2)
	{
		while (1)
		{
			while (dining->forks[philo->left_fork] == USING)
				usleep(10);
			pthread_mutex_lock(&dining->pick_up[philo->left_fork]);
			// if (dining->forks[philo->left_fork] == USING)
			// {
			// 	pthread_mutex_unlock(&dining->pick_up[philo->left_fork]);
			// 	continue;
			// }
			dining->forks[philo->left_fork] = USING;
			if (dining->forks[philo->right_fork] == NOT_USING)
			{
				pthread_mutex_lock(&dining->pick_up[philo->right_fork]);
				dining->forks[philo->right_fork] = USING;
				philo_print(dining, "has taken a fork", id);
				philo_print(dining, "has taken a fork", id);
				pthread_mutex_unlock(&dining->pick_up[philo->right_fork]);
				pthread_mutex_unlock(&dining->pick_up[philo->left_fork]);
				break ;
			}
			dining->forks[philo->left_fork] = NOT_USING;
			pthread_mutex_unlock(&dining->pick_up[philo->left_fork]);
		}
	}
	else
	{
		while (1)
		{
			while (dining->forks[philo->right_fork] == USING)
				usleep(10);
			pthread_mutex_lock(&dining->pick_up[philo->right_fork]);
			if (dining->forks[philo->right_fork] == USING)
			{
				pthread_mutex_unlock(&dining->pick_up[philo->right_fork]);
				continue;
			}
			dining->forks[philo->right_fork] = USING;
			if (dining->forks[philo->left_fork] == NOT_USING)
			{
				pthread_mutex_lock(&dining->pick_up[philo->left_fork]);
				dining->forks[philo->left_fork] = USING;
				philo_print(dining, "has taken a fork", id);
				philo_print(dining, "has taken a fork", id);
				pthread_mutex_unlock(&dining->pick_up[philo->left_fork]);
				pthread_mutex_unlock(&dining->pick_up[philo->right_fork]);
				break ;
			}
			dining->forks[philo->right_fork] = NOT_USING;
			pthread_mutex_unlock(&dining->pick_up[philo->right_fork]);
		}
	}
	philo_print(dining, "is eating", id);
	philo->last_eat = get_time();
	philo->eat_cnt++;
	eating(dining);
	if (id % 2)
	{
		pthread_mutex_lock(&dining->pick_up[philo->right_fork]);
		dining->forks[philo->right_fork] = NOT_USING;
		pthread_mutex_unlock(&dining->pick_up[philo->right_fork]);
		pthread_mutex_lock(&dining->pick_up[philo->left_fork]);
		dining->forks[philo->left_fork] = NOT_USING;
		pthread_mutex_unlock(&dining->pick_up[philo->left_fork]);
	}
	else
	{
		pthread_mutex_lock(&dining->pick_up[philo->left_fork]);
		dining->forks[philo->left_fork] = NOT_USING;
		pthread_mutex_unlock(&dining->pick_up[philo->left_fork]);
		pthread_mutex_lock(&dining->pick_up[philo->right_fork]);
		dining->forks[philo->right_fork] = NOT_USING;
		pthread_mutex_unlock(&dining->pick_up[philo->right_fork]);
	}
	return (dining->eat_flag);
}
