/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:49:55 by myko              #+#    #+#             */
/*   Updated: 2023/03/08 16:54:31 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	mutex_init(t_dining *dining)
{
	int	i;

	dining->pick_up = malloc(sizeof(pthread_mutex_t) * dining->p_num);
	if (!dining->pick_up)
		return (ft_free(dining, CASE_THREE));
	i = -1;
	while (++i < dining->p_num)
	{
		if (pthread_mutex_init(&dining->pick_up[i], NULL))
			return (ft_destroy(dining, CASE_ONE_MU, i));
	}
	if (pthread_mutex_init(&dining->die, NULL))
		return (ft_destroy(dining, CASE_ONE_MU, i));
	if (pthread_mutex_init(&dining->eat, NULL))
		return (ft_destroy(dining, CASE_TWO_MU, i));
	if (pthread_mutex_init(&dining->print, NULL))
		return (ft_destroy(dining, CASE_THREE_MU, i));
	return (SUCCESS_FLAG);
}

int	p_init(t_dining *dining)
{
	int	i;

	dining->philos = malloc(sizeof(t_philo) * dining->p_num);
	if (!dining->philos)
		return (ft_free(dining, CASE_TWO));
	i = -1;
	while (++i < dining->p_num)
	{
		dining->philos[i].id = i;
		dining->philos[i].eat_cnt = 0;
		dining->philos[i].last_eat = 0;
		if (i % 2)
		{
			dining->philos[i].left_fork = i;
			dining->philos[i].right_fork = (i + 1) % dining->p_num;
		}
		else
		{
			dining->philos[i].right_fork = i;
			dining->philos[i].left_fork = (i + 1) % dining->p_num;
		}
		dining->philos[i].dining = dining;
	}	
	return (SUCCESS_FLAG);
}

int	philo_init(t_dining *dining)
{
	int	i;

	dining->forks = malloc(sizeof(int) * dining->p_num);
	if (!dining->forks)
		return (ft_free(dining, CASE_ONE));
	i = -1;
	while (++i < dining->p_num)
		dining->forks[i] = NOT_USING;
	if (p_init(dining))
		return (FAIL_FLAG);
	if (mutex_init(dining))
		return (FAIL_FLAG);
	return (SUCCESS_FLAG);
}
