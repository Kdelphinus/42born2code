/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:57:28 by myko              #+#    #+#             */
/*   Updated: 2023/03/06 21:45:56 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum s_time
{
	ODD_OR_EVEN = 10,
	WAIT_TIME = 100,
	CHECK_TIME = 500,
}	t_time;

typedef enum s_error
{
	ARG_ERROR,
	MALLOC_ERROR,
	MUTEX_ERROR,
	CREATE_ERROR,
}	t_error;

typedef enum s_free
{
	CASE_ONE,
	CASE_TWO,
	CASE_THREE,
	CASE_FOUR,
	ALL_FREE,
	ALL_FREE_TWO,
}	t_free;

typedef enum s_destroy
{
	CASE_ONE_MU,
	CASE_TWO_MU,
	CASE_THREE_MU,
	CASE_FOUR_MU,
	ALL_DESTROY,
}	t_destroy;

typedef enum s_flags
{
	SUCCESS_FLAG,
	FAIL_FLAG,
	LIVE,
	DIE,
	ENOUGH,
	NOT_ENOUGH,
	USING,
	NOT_USING,
}	t_flags;

typedef struct s_philo
{
	pthread_t		tid;
	int				id;
	int				eat_cnt;
	int				left_fork;
	int				right_fork;
	long long		last_eat;
	struct s_dining	*dining;
}	t_philo;

typedef struct s_dining
{
	int				p_num;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				t_think;
	int				min_eat;
	int				die_flag;
	int				eat_flag;
	int				*forks;
	long long		start_time;
	t_philo			*philos;
	pthread_mutex_t	full;
	pthread_mutex_t death;
	pthread_mutex_t	print;
	pthread_mutex_t	*lock;
	pthread_mutex_t	*pick_up;
}	t_dining;

// check_arg.c
int			ft_atoi(const char *str);
int			check_arg(int argc, char **argv, t_dining *dining);

// philo_init.c
int			mutex_init(t_dining *dining);
int			p_init(t_dining *dining);
int			philo_init(t_dining *dining);

// philo_act.c
void		*philo_act(void *arg);
void		eat_check(t_dining *dining);
void		philo_check(t_dining *dining);
int			dining_end(t_dining *dining);
int			dining_start(t_dining *dining);

// philo_eat.c
void		eating(t_dining *dining, long long eat_start);
int			philo_eat(t_dining *dining, t_philo *philo, int id);

// philo_sleep.c
void		philo_sleep(t_dining *dining, int id);

// philo_think.c
void		philo_think(t_dining *dining, int id);

// get_time.c
long long	get_time(void);

// philo_print.c
void		philo_print(t_dining *dining, char *string, int id, long long ts);

// ft_error.c
int			ft_free(t_dining *dining, int flag);
int			ft_destroy(t_dining *dining, int flag, int i);
int			ft_join(t_dining *dining, int i);
int			ft_error(int flag);

#endif