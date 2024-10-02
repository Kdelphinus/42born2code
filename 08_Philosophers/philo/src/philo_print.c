/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:43:37 by myko              #+#    #+#             */
/*   Updated: 2023/03/08 17:51:37 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_print(t_dining *dining, char *string, int id, long long ts)
{
	if (flag_check(dining) == DIE)
		return ;
	printf("%lld %d %s\n", ts - dining->start_time, id + 1, string);
}
