/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:14:44 by myko              #+#    #+#             */
/*   Updated: 2023/02/09 14:43:53 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	fork_init(t_fork *forks, int value)
{
	forks->value = value;
	pthread_mutex_init(&forks->lock, NULL);
}

void	fork_wait(t_fork *fork)
{
	pthread_mutex_lock(&fork->lock);
	fork->value--;
	pthread_mutex_unlock(&fork->lock);
}

void	get_fork(t_philos *philos, int philo)
{
	printf("philosopher %d waits for the left fork.\n", philo);
	fork_wait(&philos->forks[philo]);
	printf("philosopher %d waits for the right fork.\n", philo);
	fork_wait(&philos->forks[(philo + 1) % philos->num]);
	printf("philosopher %d gets the fork.\n", philo);
}

void	fork_post(t_fork *fork)
{
	pthread_mutex_lock(&fork->lock);
	fork->value++;
	pthread_mutex_unlock(&fork->lock);
}

void	put_fork(t_philos *philos, int philo)
{
	fork_post(&philos->forks[philo]);
	fork_post(&philos->forks[(philo + 1) % philos->num]);
}

void	*philo_act(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	// free(arg);
	while (1)
	{
		thinking(philos->name);
		get_fork(philos, philos->name);
		eating(philos->name);
		put_fork(philos, philos->name);
		sleeping(philos->name);
	}
	// free(arg);
	return (NULL);
}

int main(int argc, char **argv)
{
	int			i;
	t_philos	philos;

	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	if (argc == 5)
	{
		argv[5] = "INF";
		argv[6] = 0;
	}
	i = -1;
	philos.num = ft_atoi(argv[1]);
	philos.men = (pthread_t *)malloc(sizeof(pthread_t) * philos.num);
	philos.forks = (t_fork *)malloc(sizeof(t_fork) * philos.num);
	while (++i < philos.num)
		fork_init(&philos.forks[i], 1);
	i = -1;
	while (++i < philos.num)
	{
 		philos.name = i;
		pthread_create(&philos.men[i], NULL, philo_act, &philos);
	}
	i = -1;
	while (++i < philos.num)
		pthread_join(philos.men[i], NULL);
	return (EXIT_SUCCESS);
}
