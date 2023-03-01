/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:49:55 by myko              #+#    #+#             */
/*   Updated: 2023/03/01 13:21:41 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	mutex_init(t_dining *dining)
{
	if (pthread_mutex_init(&dining->lock, NULL))
		return (FAIL_FLAG);
	if (pthread_mutex_init(&dining->print, NULL))
		return (FAIL_FLAG);
	if (pthread_mutex_init(&dining->pick_up, NULL))
		return (FAIL_FLAG);
	return (SUCCESS_FLAG);
}

int	p_init(t_dining *dining)
{
	int	i;

	dining->philos = malloc(sizeof(t_philo) * dining->p_num);
	if (!dining->philos)
		return (FAIL_FLAG);
	i = -1;
	while (++i < dining->p_num)
	{
		dining->philos[i].id = i;
		dining->philos[i].eat_cnt = 0;
		dining->philos[i].last_eat = 0;
		dining->philos[i].left_fork = i;
		dining->philos[i].right_fork = (i + 1) % dining->p_num;
		dining->philos[i].dining = dining;
	}	
	return (SUCCESS_FLAG);
}

int	philo_init(t_dining *dining)
{
	int i;

	dining->forks = malloc(sizeof(int) * dining->p_num);
	if (!dining->forks)
		return (FAIL_FLAG);
	i = -1;
	while (++i < dining->p_num)
		dining->forks[i] = NOT_USING;
	if (mutex_init(dining))
		return (FAIL_FLAG);
	if (p_init(dining))
		return (FAIL_FLAG);
	return (SUCCESS_FLAG);
}
