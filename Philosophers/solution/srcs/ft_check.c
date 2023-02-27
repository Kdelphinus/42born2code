/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:46:24 by gpaeng            #+#    #+#             */
/*   Updated: 2021/08/03 15:49:21 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_eat_check(t_game *game, t_philo *philo)
{
	int	i;

	i = 0;
	while (game->must_eat_num != 0 && i < game->philo_num
		&& philo[i].eat_cnt > game->must_eat_num)
		i++;
	if (i == game->philo_num)
		game->eat_check = 1;
}

int	ft_check_init(t_game *game)
{
	if (game->philo_num < 2 || game->philo_num > 200
		|| game-> time_to_die < 60 || game->time_to_eat < 60
		|| game->time_to_sleep < 60)
		return (-1);
	return (0);
}

void	ft_death_check(t_game *game, t_philo *philo)
{
	int		i;

	while (!(game->eat_check))
	{
		i = 0;
		while ((i < game->philo_num) && (!(game->die)))
		{
			pthread_mutex_lock(&(game->eating));
			if ((ft_time() - philo[i].check_d_time) > game->time_to_die)
			{
				ft_printf(game, "died", i);
				game->die = 1;
			}
			pthread_mutex_unlock(&(game->eating));
			i++;
		}
		if (game->die)
			break ;
		ft_eat_check(game, game->philo);
	}
}
