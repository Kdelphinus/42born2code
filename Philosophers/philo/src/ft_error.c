/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:55:57 by myko              #+#    #+#             */
/*   Updated: 2023/03/06 21:37:31 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_free(t_dining *dining, int flag)
{
	if (flag >= CASE_TWO)
		free(dining->forks);
	if (flag >= CASE_THREE)
		free(dining->philos);
	if (flag >= CASE_FOUR)
		free(dining->pick_up);
	if (flag >= ALL_FREE)
	{
		free(dining->lock);
		if (flag == ALL_FREE_TWO)
			return (ft_error(CREATE_ERROR));
		return (ft_error(MUTEX_ERROR));
	}
	return (ft_error(MALLOC_ERROR));
}

int	ft_destroy(t_dining *dining, int flag, int i)
{
	int	j;

	if (flag >= CASE_TWO_MU)
	{
		j = i;
		i = dining->p_num;
	}
	if (flag >= CASE_ONE_MU)
	{
		while (--i >= 0)
			pthread_mutex_destroy(&dining->pick_up[i]);
	}
	if (flag >= CASE_TWO_MU)
	{
		while (--j >= 0)
			pthread_mutex_destroy(&dining->lock[j]);
	}
	if (flag >= CASE_THREE_MU)
		pthread_mutex_destroy(&dining->print);
	if (flag >= CASE_FOUR_MU)
		pthread_mutex_destroy(&dining->full);
	if (flag >= ALL_DESTROY)
	{
		pthread_mutex_destroy(&dining->death);
		ft_free(dining, ALL_FREE_TWO);
	}
	return (ft_free(dining, ALL_FREE));
}

int	ft_join(t_dining *dining, int i)
{
	while (--i >= 0)
		pthread_join(dining->philos[i].tid, NULL);
	return (ft_destroy(dining, ALL_DESTROY, dining->p_num));
}

int	ft_error(int flag)
{
	if (flag == ARG_ERROR)
		write(STDERR_FILENO, "ARG ERROR\n", 10);
	else if (flag == MALLOC_ERROR)
		write(STDERR_FILENO, "MALLOC ERROR\n", 13);
	else if (flag == MUTEX_ERROR)
		write(STDERR_FILENO, "MUTEX ERROR\n", 12);
	else if (flag == CREATE_ERROR)
		write(STDERR_FILENO, "CREATE ERROR\n", 13);
	return (FAIL_FLAG);
}
