/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:39:26 by myko              #+#    #+#             */
/*   Updated: 2023/03/06 21:42:41 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_act(void *arg)
{
	int 		flag;
	t_philo		*c_philo;
	t_dining	*dining;

	c_philo = (t_philo *)arg;
	dining = c_philo->dining;
	if (c_philo->id % 2)
		usleep(ODD_OR_EVEN);
	pthread_mutex_lock(&dining->death);
	while (dining->die_flag == LIVE && dining->eat_flag == NOT_ENOUGH)
	{
		pthread_mutex_unlock(&dining->death);
		flag = philo_eat(dining, c_philo, c_philo->id);
		pthread_mutex_lock(&dining->death);
		if (flag == ENOUGH || dining->die_flag == DIE)
			break ;
		pthread_mutex_unlock(&dining->death);
		philo_sleep(dining, c_philo->id);
		pthread_mutex_lock(&dining->death);
		if (dining->die_flag == DIE)
			break;
		pthread_mutex_unlock(&dining->death);
		philo_think(dining, c_philo->id);
		pthread_mutex_lock(&dining->death);
	}
	pthread_mutex_unlock(&dining->death);
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
		pthread_mutex_lock(&dining->lock[i]);
		if (dining->philos[i].eat_cnt < cnt)
		{
			pthread_mutex_unlock(&dining->lock[i]);
			break ;
		}
		pthread_mutex_unlock(&dining->lock[i]);
	}
	if (i == dining->p_num)
	{
		pthread_mutex_lock(&dining->full);
		dining->eat_flag = ENOUGH;
		pthread_mutex_unlock(&dining->full);
	}
}

void	philo_check(t_dining *dining)
{
	int			i;
	long long	curr_time;

	pthread_mutex_lock(&dining->full);
	while (dining->eat_flag == NOT_ENOUGH)
	{
		pthread_mutex_unlock(&dining->full);
		i = -1;
		while (++i < dining->p_num && dining->die_flag == LIVE)
		{
			pthread_mutex_lock(&dining->print);
			curr_time = get_time();
			if (curr_time - dining->philos[i].last_eat > dining->t_die)
			{
				philo_print(dining, "died", i, curr_time);
				pthread_mutex_lock(&dining->death);
				dining->die_flag = DIE;
				pthread_mutex_unlock(&dining->death);
			}
			pthread_mutex_unlock(&dining->print);
		}
		pthread_mutex_lock(&dining->death);
		if (dining->die_flag == DIE)
		{
			pthread_mutex_unlock(&dining->death);
			return ;
		}
		pthread_mutex_unlock(&dining->death);
		eat_check(dining);
		pthread_mutex_lock(&dining->full);
	}
	pthread_mutex_unlock(&dining->full);
}

int	dining_end(t_dining *dining)
{
	int	i;

	i = -1;
	while (++i < dining->p_num)
		pthread_join(dining->philos[i].tid, NULL);
	i = -1;
	while (++i < dining->p_num)
	{
		while (pthread_mutex_destroy(&dining->pick_up[i]))
			pthread_mutex_unlock(&dining->pick_up[i]);
	}
	while (--i >= 0)
	{
		while (pthread_mutex_destroy(&dining->lock[i]))
			pthread_mutex_unlock(&dining->lock[i]);
	}
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
			return (ft_join(dining, i));
	}
	philo_check(dining);
	dining_end(dining);
	return (SUCCESS_FLAG);
}
