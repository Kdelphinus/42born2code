/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:26:08 by myko              #+#    #+#             */
/*   Updated: 2023/03/03 13:57:06 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_dining	dining;

	if (check_arg(argc, argv, &dining))
		return (EXIT_FAILURE);
	if (dining.p_num == 1)
		return (EXIT_SUCCESS);
	if (philo_init(&dining))
		return (EXIT_FAILURE);
	if (dining_start(&dining))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
