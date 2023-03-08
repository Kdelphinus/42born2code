/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:39:26 by myko              #+#    #+#             */
/*   Updated: 2023/03/08 17:11:15 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_act(void *arg)
{
	int 		flag_d;
	int 		flag_e;
	t_philo		*c_philo;
	t_dining	*dining;

	c_philo = (t_philo *)arg;
	dining = c_philo->dining;
	if (c_philo->id % 2)
		usleep(ODD_OR_EVEN);
	while (1)
	{
		pthread_mutex_lock(&dining->die);
		flag_d = dining->die_flag;
		pthread_mutex_unlock(&dining->die);
		pthread_mutex_lock(&dining->eat);
		flag_e = dining->eat_flag;
		pthread_mutex_unlock(&dining->eat);
		if (flag_d == DIE || flag_e == ENOUGH)
			break ;
		philo_eat(dining, c_philo, c_philo->id);
		pthread_mutex_lock(&dining->die);
		flag_d = dining->die_flag;
		pthread_mutex_unlock(&dining->die);
		pthread_mutex_lock(&dining->eat);
		flag_e = dining->eat_flag;
		pthread_mutex_unlock(&dining->eat);
		if (flag_d == DIE || flag_e == ENOUGH)
			break ;
		philo_sleep(dining, c_philo->id);
		pthread_mutex_lock(&dining->die);
		flag_d = dining->die_flag;
		pthread_mutex_unlock(&dining->die);
		pthread_mutex_lock(&dining->eat);
		flag_e = dining->eat_flag;
		pthread_mutex_unlock(&dining->eat);
		if (flag_d == DIE || flag_e == ENOUGH)
			break ;
		philo_think(dining, c_philo->id);
	}
	return (NULL);
}

void	eat_check(t_dining *dining)
{
	int i;
	int tmp;
	int cnt;

	i = -1;
	cnt = dining->min_eat;
	if (cnt == 0)
		return;
	while (++i < dining->p_num)
	{
		pthread_mutex_lock(&dining->eat);
		tmp = dining->philos[i].eat_cnt;
		pthread_mutex_unlock(&dining->eat);
		if (tmp < cnt)
			break;
	}
	if (i == dining->p_num)
	{
		pthread_mutex_lock(&dining->eat);
		dining->eat_flag = ENOUGH;
		pthread_mutex_unlock(&dining->eat);
	}
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
			pthread_mutex_lock(&dining->print);
			curr_time = get_time();
			if (curr_time - dining->philos[i].last_eat > dining->t_die)
			{
				philo_print(dining, "died", i, curr_time);
				pthread_mutex_lock(&dining->die);
				dining->die_flag = DIE;
				pthread_mutex_unlock(&dining->die);
			}
			pthread_mutex_unlock(&dining->print);
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
		pthread_join(dining->philos[i].tid, NULL);
	i = -1;
	while (++i < dining->p_num)
	{
		while (pthread_mutex_destroy(&dining->pick_up[i]))
			pthread_mutex_unlock(&dining->pick_up[i]);
	}
	while (pthread_mutex_destroy(&dining->die))
		pthread_mutex_unlock(&dining->die);
	while (pthread_mutex_destroy(&dining->eat))
		pthread_mutex_unlock(&dining->eat);
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
