/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:57:28 by myko              #+#    #+#             */
/*   Updated: 2023/02/08 19:20:08 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_fork {
	int				value;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_philos {
	int			num;
	int			name;
	int			*states;
	t_fork		*forks;
	pthread_t	*men;
} t_philos;

// main.c
void	*philo_act(void *arg);

// act.c
void	thinking(int philo_num);
void	eating(int philo_num);
void	sleeping(int philo_num);

// ft_atoi.c
int		ft_atoi(const char *str);

#endif