/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_example.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 02:43:28 by myko              #+#    #+#             */
/*   Updated: 2023/02/17 03:33:56 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_philosophers {
	pthread_t		tid;
	struct timeval	last_dinning_start_time;
}	t_philosophers;

typedef struct s_info
{
	int				nop;
	int				time_to_die_ms;
	int				time_to_eat_ms;
	int				time_to_sleep_ms;
	int				number_of_times_each_philosopher_must_eat;
	int				id;
	int				idx;
	int				*ate;
	t_philosophers	*philosophers;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*lock;
}	t_info;

void	init_info(t_info *pinfo, int num)
{
	pinfo->philosophers = malloc(sizeof(t_philosophers) * num);
	pinfo->forks = malloc(sizeof(pthread_mutex_t) * num);
	pinfo->lock = malloc(sizeof(pthread_mutex_t) * 1);
	pinfo->ate = malloc(sizeof(int) * num);
	if (!(pinfo->philosophers && pinfo->forks && pinfo->ate && pinfo->lock))
		exit(1);
}

void	*even_routine(void *arg)
{
	t_info			*info;

	info = (t_info *)arg;
	usleep(100);
	info->id = info->idx;
	while (1) {
		info->ate[info->id] = 0;
		printf("even_id: %d\n", info->id);
		if (!pthread_mutex_lock(&info->forks[(info->id + 1) % info->nop])) {
			printf("philosopher(%d) picks up the fork(%d).\n", info->id, (info->id + 1) % info->nop);
			if (!pthread_mutex_lock(&info->forks[info->id])) {
				printf("philosopher(%d) picks up the fork(%d).\n", info->id, info->id);
				printf("philosopher(%d) eating.\n", info->id);
				info->ate[info->id] = 1;
				pthread_mutex_unlock(&info->forks[info->id]);
			}
			pthread_mutex_unlock(&info->forks[(info->id + 1) % info->nop]);
		}
		if (info->ate[info->id])
			usleep(1000);
	}
	return (NULL);
}

void	*odd_routine(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	usleep(100);
	info->id = info->idx;
	while (1) {
		info->ate[info->id] = 0;
		printf("odd_id: %d\n", info->id);
		if (!pthread_mutex_lock(&info->forks[info->id])) {
			printf("philosopher(%d) picks up the fork(%d).\n", info->id, info->id);
			if (!pthread_mutex_lock(&info->forks[((info->id + 1) % info->nop)])) {
				printf("philosopher(%d) picks up the fork(%d).\n", info->id, (info->id + 1) % info->nop);
				printf("philosopher(%d) eating.\n", info->id);
				info->ate[info->id] = 1;
				pthread_mutex_unlock(&info->forks[((info->id + 1) % info->nop)]);
			}
			pthread_mutex_unlock(&info->forks[info->id]);
		}
		if (info->ate[info->id])
			usleep(1000);
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (5 > argc || 6 < argc)
		return (EXIT_FAILURE);
	info.nop = atoi(argv[1]);
	info.time_to_die_ms = atoi(argv[2]);
	info.time_to_eat_ms = atoi(argv[3]);
	info.time_to_sleep_ms = atoi(argv[4]);
	if (argc == 6)
		info.number_of_times_each_philosopher_must_eat = atoi(argv[5]);
	init_info(&info, info.nop);
	info.idx = -1;
	while (++info.idx < info.nop)
		pthread_mutex_init(&info.forks[info.idx], NULL);
	info.idx = -1;
	while (++info.idx < info.nop)
	{
		usleep(100);
		if (info.idx % 2 == 0)
			pthread_create(&info.philosophers[info.idx].tid, NULL, even_routine, (void *)&info);
		else
			pthread_create(&info.philosophers[info.idx].tid, NULL, odd_routine, (void *)&info);
	}
	info.idx = -1;
	while (++info.idx < info.nop)
		pthread_join(info.philosophers[info.idx].tid, NULL);
	info.idx = -1;
	while (++info.idx < info.nop)
		pthread_mutex_destroy(&info.forks[info.idx]);
	free(info.philosophers);
	free(info.forks);
	return (0);
}
