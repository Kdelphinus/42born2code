/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:39:26 by myko              #+#    #+#             */
/*   Updated: 2023/03/01 18:07:34 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_act(void *arg)
{
	t_philo		*c_philo;
	t_dining	*dining;

	c_philo = (t_philo *)arg;
	dining = c_philo->dining;
	if (c_philo->id % 2)
		usleep(100);
	while (dining->die_flag == LIVE)
	{
		if (philo_eat(dining, c_philo, c_philo->id) == ENOUGH)
			break ;
		philo_sleep(dining, c_philo->id);
		philo_print(dining, "is thinking", c_philo->id);
	}
	return (NULL);
}

void	eat_check(t_dining *dining)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = dining->min_eat;
	if (cnt == 0)
		return ;
	while (++i < dining->p_num)
	{
		if (dining->philos[i].eat_cnt < cnt)
			break ;
	}
	if (i == dining->p_num)
		dining->eat_flag = ENOUGH;
}

void	philo_check(t_dining *dining)
{
	int			i;
	long long	curr_time;

	while (dining->eat_flag == NOT_ENOUGH)
	{
		i = -1;
		while (++i < dining->p_num && dining->die_flag == LIVE)
		{
			pthread_mutex_lock(&dining->lock);
			curr_time = get_time();
			if (curr_time - dining->philos[i].last_eat > dining->t_die)
			{
				philo_print(dining, "died", i);
				dining->die_flag = DIE;
			}
			pthread_mutex_unlock(&dining->lock);
		}
		if (dining->die_flag == DIE)
			break ;
		eat_check(dining);
	}
}

int	dining_end(t_dining *dining)
{
	int	i;

	i = -1;
	while (++i < dining->p_num)
	{
		pthread_join(dining->philos[i].tid, NULL);
		// if (!pthread_join(dining->philos[i].tid, NULL))
		// 	return (FAIL_FLAG);
	}
	i = -1;
	while (++i < dining->p_num)
	{
		while (pthread_mutex_destroy(&dining->pick_up[i]))
			pthread_mutex_unlock(&dining->pick_up[i]);
	}
	while (pthread_mutex_destroy(&dining->lock))
		pthread_mutex_unlock(&dining->lock);
	while (pthread_mutex_destroy(&dining->print))
		pthread_mutex_unlock(&dining->print);
	free(dining->philos);
	free(dining->forks);
	free(dining->pick_up);
	return (SUCCESS_FLAG);
}

int	dining_start(t_dining *dining)
{
	int		i;
	void	*arg;

	dining->start_time = get_time();
	i = -1;
	while (++i < dining->p_num)
	{
		dining->philos[i].last_eat = get_time();
		arg = (void *)&(dining->philos[i]);
		if (pthread_create(&(dining->philos[i].tid), NULL, philo_act, arg))
			return (FAIL_FLAG);
	}
	philo_check(dining);
	dining_end(dining);
	return (SUCCESS_FLAG);
}
