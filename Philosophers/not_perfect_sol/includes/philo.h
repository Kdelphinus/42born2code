/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:20:39 by gpaeng            #+#    #+#             */
/*   Updated: 2021/08/03 13:20:23 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	long long		check_d_time;
	int				eat_cnt;
	struct s_game	*game;
	pthread_t		thread_id;
}				t_philo;

typedef struct s_game
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_num;
	int				die;
	int				eat_check;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	eating;
	pthread_mutex_t	write;
	t_philo			*philo;
}				t_game;

/*
**ft_utils.c
*/
int			ft_isspace(char c);
int			ft_atoi(char *str);
int			ft_error(char *s);
void		ft_printf(t_game *game, char *str, int id);

/*
**ft_time.c
*/
long long	ft_time(void);
void		ft_sleeping_time(t_game *game);
void		ft_eating_time(t_game *game);

/*
**ft_check.c
*/
void		ft_eat_check(t_game *game, t_philo *philo);
void		ft_death_check(t_game *game, t_philo *philo);
int			ft_check_init(t_game *game);

/*
**ft_init.c
*/
int			ft_mutex_init(t_game *game);
int			ft_philo_input(t_game *game, char *argv[], int argc);
int			ft_philo_init(t_game *game);

/*
**ft_philo.c
*/
void		ft_philo_eat(t_game *game, t_philo *philo);
int			ft_philo_do(t_game *game, t_philo *philo);
void		*ft_pthread(void *philo);
void		ft_end_philo(t_game *game, t_philo *philo);
int			ft_philo_start(t_game *game, t_philo *philo);
void		ft_after_eating(t_game *game, t_philo *philo);

/*
**main.c
*/
int			main(int argc, char *argv[]);

#endif