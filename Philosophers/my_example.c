#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_philosophers {
    pthread_t tid;
    struct timeval last_dinning_start_time;
    int left_fork;
    int right_fork;
    int eating_time;
} t_philosophers;

typedef struct s_info {
    struct timeval starting_time;
    struct timeval current_time;
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
    int id;
    int flag_die;

    pthread_t tid_of_death;
    pthread_mutex_t lock;
    pthread_mutex_t print;

    t_philosophers *philosophers;
    pthread_mutex_t *forks;
} t_info;

void init_info(t_info *pinfo, int num)
{
    pinfo->philosophers = malloc(sizeof(t_philosophers) * num);
    pinfo->forks = malloc(sizeof(pthread_mutex_t) * num);
    if (!(pinfo->philosophers && pinfo->forks))
		exit(1);
}

int timestamp_in_ms(struct timeval current_t, struct timeval starting_t)
{
    return (int)(current_t.tv_sec - starting_t.tv_sec) * 1000 + (int)(current_t.tv_usec - starting_t.tv_usec) / 1000;
}

void pickup_forks(t_info *pinfo, int philosophers_id, int forks_id)
{
    pthread_mutex_lock(&pinfo->forks[forks_id]);

    pthread_mutex_lock(&pinfo->print);
    gettimeofday(&pinfo->current_time, NULL);
	printf("%d %d has taken a fork\n", timestamp_in_ms(pinfo->current_time, pinfo->starting_time), philosophers_id);
    pthread_mutex_unlock(&pinfo->print);
    if(philosophers_id - forks_id)
        pinfo->philosophers[philosophers_id].right_fork = 1;
    else
        pinfo->philosophers[philosophers_id].left_fork = 1;
}

void return_forks(t_info *pinfo, int philosophers_id)
{
    pthread_mutex_unlock(&pinfo->forks[philosophers_id]);
    pthread_mutex_unlock(&pinfo->forks[(philosophers_id + 1) % pinfo->number_of_philosophers]);
    pinfo->philosophers[philosophers_id].left_fork = 0;
    pinfo->philosophers[philosophers_id].right_fork = 0;
}

void dinning(t_info *pinfo, int philosophers_id)
{
    pthread_mutex_lock(&pinfo->lock);
    gettimeofday(&pinfo->philosophers->last_dinning_start_time, NULL);
    pinfo->philosophers[philosophers_id].eating_time++;
    pthread_mutex_lock(&pinfo->print);
    gettimeofday(&pinfo->current_time, NULL);
    printf("%d %d is eating\n", timestamp_in_ms(pinfo->current_time, pinfo->starting_time), philosophers_id);
    pthread_mutex_unlock(&pinfo->print);
    pthread_mutex_unlock(&pinfo->lock);
    return_forks(pinfo, philosophers_id);
    usleep(pinfo->time_to_eat*1000);
}

void    sleeping_and_thinking(t_info *pinfo, int philosophers_id)
{
    pthread_mutex_lock(&pinfo->print);
    gettimeofday(&pinfo->current_time, NULL);
    printf("%d %d is sleeping\n", timestamp_in_ms(pinfo->current_time, pinfo->starting_time), philosophers_id);
    pthread_mutex_unlock(&pinfo->print);
    usleep(pinfo->time_to_sleep*1000);

    pthread_mutex_lock(&pinfo->print);
    gettimeofday(&pinfo->current_time, NULL);
    printf("%d %d is thinking\n", timestamp_in_ms(pinfo->current_time, pinfo->starting_time), philosophers_id);
    pthread_mutex_unlock(&pinfo->print);
}

void    *death_monitoring(void *arg)
{
    int     i;
    t_info	*info;

	info = (t_info *)arg;
	while (info->flag_die)
	{
		if (info->number_of_times_each_philosopher_must_eat > -1)
		{
			pthread_mutex_lock(&info->lock);
			i = -1;
			while (++i < info->number_of_philosophers)
			{
				if (info->philosophers[i].eating_time < info->number_of_times_each_philosopher_must_eat)
					break;
			}
			if (i == info->number_of_philosophers)
				info->flag_die = 0;
			pthread_mutex_unlock(&info->lock);
		}
	}
	return (NULL);
}

void    *basic_routine(void *arg)
{
    t_info	*info;
	int		myid;

	info = (t_info *)arg;
	myid = info->id;
    while (info->flag_die)
    {
		pickup_forks(info, myid, myid);
        pickup_forks(info, myid, (myid + 1) % info->number_of_philosophers);
        dinning(info, myid);
        if (!info->flag_die)
            break;
        sleeping_and_thinking(info, myid);
        if (!info->flag_die)
            break;
    }
	return (NULL);
}

int main(int argc, char *argv[])
{
    t_info info;
    info.flag_die = 1;
    gettimeofday(&info.starting_time, NULL);

    if (5 > argc || 6 < argc)
		exit(1);
    info.number_of_philosophers = atoi(argv[1]);
    info.time_to_die = atoi(argv[2]);
    info.time_to_eat = atoi(argv[3]);
    info.time_to_sleep = atoi(argv[4]);
    if (argc == 6)
        info.number_of_times_each_philosopher_must_eat = atoi(argv[5]);
	else
		info.number_of_times_each_philosopher_must_eat = -1;

    if (info.number_of_philosophers == 1)
    {
        printf("0 0 has taken a fork\n");
        printf("%d 0 died\n", info.time_to_die);
        return 0;
    }

    init_info(&info, info.number_of_philosophers);

    if (pthread_mutex_init(&info.lock, NULL))
        exit(1);
    if (pthread_mutex_init(&info.print, NULL))
        exit(1);
    info.id = -1;
    while (++info.id < info.number_of_philosophers)
    {
        if (pthread_mutex_init(&info.forks[info.id], NULL))
            exit(1);
    }

    if (pthread_create(&info.tid_of_death, NULL, death_monitoring, (void *)&info))
        exit(1);

    info.id = -1;
    while (++info.id < info.number_of_philosophers)
    {
		usleep(1000);
		info.philosophers[info.id].eating_time = 0;
        pthread_create(&info.philosophers[info.id].tid, NULL, basic_routine, (void *)&info);
    }

    info.id = -1;
    while (++info.id < info.number_of_philosophers)
    {
        if (!pthread_join(info.philosophers[info.id].tid, NULL))
            exit(1);
    }

    printf("All threads are finished\n");

    info.id = -1;
    while (++info.id < info.number_of_philosophers)
    {
        if (!pthread_mutex_destroy(&info.forks[info.id]))
            exit(1);
    }
    if (!pthread_mutex_destroy(&info.lock))
        exit(1);
    if (!pthread_mutex_destroy(&info.print))
        exit(1);

    free(info.philosophers);
    free(info.forks);

    return 0;
}
