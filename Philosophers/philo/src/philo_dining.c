/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dining.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:18:18 by myko              #+#    #+#             */
/*   Updated: 2023/03/08 17:59:33 by myko             ###   ########.fr       */
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
		usleep(ODD_OR_EVEN);
	while (flag_check(dining) == LIVE)
	{
		philo_eat(dining, c_philo, c_philo->id);
		if (flag_check(dining) == DIE)
			break ;
		philo_sleep(dining, c_philo->id);
		if (flag_check(dining) == DIE)
			break ;
		philo_think(dining, c_philo->id);
	}
	return (NULL);
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
