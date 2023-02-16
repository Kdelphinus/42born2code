/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_example.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:49:22 by myko              #+#    #+#             */
/*   Updated: 2023/02/16 20:39:48 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

enum e_state {
	SLEEPING = 0,
	THINKING,
	EATING,
	USING,
	NOT_USING,
};

typedef struct s_con {
	pthread_mutex_t	*mutexes;
	int				*permits;
	pthread_t		*tids;
	int				*con;
	int				philo_num;
	int				me;
}	t_con;

void	con_init(t_con *philo_con)
{
	philo_con->mutexes = malloc(sizeof(pthread_mutex_t) * philo_con->philo_num);
	philo_con->permits = malloc(sizeof(int) * philo_con->philo_num);
	philo_con->tids = malloc(sizeof(pthread_t) * philo_con->philo_num);
	philo_con->con = malloc(sizeof(int) * philo_con->philo_num);
	if (!(philo_con->mutexes && philo_con->permits && philo_con->tids && philo_con->con))
		exit(0);
}

void	*even_philo(void *arg)
{
	t_con	*philo_con;

	philo_con = (t_con *)arg;
	printf("philosopher(%d) picks up the fork(%d).\n", philo_con->me, (philo_con->me + 1) % philo_con->philo_num);
	return (NULL);
}

void	*odd_philo(void *arg)
{
	t_con	*philo_con;

	philo_con = (t_con *)arg;
	printf("philosopher(%d) picks up the fork(%d).\n", philo_con->me, (philo_con->me + 1) % philo_con->philo_num);
	return (NULL);
}

int	main(int argc, char **argv)
{
	int		i;
	t_con	philo_con;

	if (5 > argc || 6 < argc)
		return (EXIT_FAILURE);
	philo_con.philo_num = atoi(argv[1]);
	con_init(&philo_con);
	i = -1;
	while (++i < philo_con.philo_num)
	{
		pthread_mutex_init(&philo_con.mutexes[i], NULL);
		philo_con.permits[i] = NOT_USING;
		philo_con.con[i] = THINKING;
	}
	i = -1;
	while (++i < philo_con.philo_num)
	{
		philo_con.me = i;
		if (i % 2)
			pthread_create(&philo_con.tids[i], NULL, odd_philo, (void*)(&philo_con));
		else
			pthread_create(&philo_con.tids[i], NULL, even_philo, (void*)(&philo_con));
		// sleep(1);
	}
	i = -1;
	while (++i < philo_con.philo_num)
		pthread_join(philo_con.tids[i], NULL);
	i = -1;
	while (++i < philo_con.philo_num)
		pthread_mutex_destroy(&philo_con.mutexes[i]);
	free(philo_con.mutexes);
	free(philo_con.permits);
	free(philo_con.tids);
	free(philo_con.con);
	return (EXIT_SUCCESS);
}