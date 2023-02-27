/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:17:50 by gpaeng            #+#    #+#             */
/*   Updated: 2021/08/03 15:13:33 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_mutex_init(t_game *game)
{
	int	idx;

	if (pthread_mutex_init(&(game->write), NULL))
		return (-1);
	if (pthread_mutex_init(&(game->eating), NULL))
		return (-1);
	game->forks = malloc(sizeof(pthread_mutex_t) * game->philo_num);
	if (!(game->forks))
		return (-1);
	idx = 0;
	while (idx < game->philo_num)
	{
		if (pthread_mutex_init(&(game->forks[idx]), NULL))
			return (-1);
		idx++;
	}
	return (0);
}

int	ft_philo_init(t_game *game)
{
	int	idx;

	idx = 0;
	game->philo = malloc(sizeof(t_game) * game->philo_num);
	if (!(game->philo))
		return (-1);
	while (idx < game->philo_num)
	{
		game->philo[idx].id = idx;
		game->philo[idx].left_fork = idx;
		game->philo[idx].right_fork = (idx + 1) % game->philo_num;
		game->philo[idx].check_d_time = 0;
		game->philo[idx].eat_cnt = 0;
		game->philo[idx].game = game;
		idx++;
	}
	return (0);
}

int	ft_philo_input(t_game *game, char *argv[], int argc)
{
	game->philo_num = ft_atoi(argv[1]);
	game->time_to_die = ft_atoi(argv[2]);
	game->time_to_eat = ft_atoi(argv[3]);
	game->time_to_sleep = ft_atoi(argv[4]);
	game->must_eat_num = 0;
	game->die = 0;
	game->eat_check = 0;
	game->start_time = 0;
	if (ft_check_init(game))
		return (-1);
	if (argc == 6)
	{
		game->must_eat_num = ft_atoi(argv[5]);
		if (game->must_eat_num <= 0)
			return (-1);
	}
	if (ft_mutex_init(game))
		return (-1);
	if (ft_philo_init(game))
		return (-1);
	return (0);
}
