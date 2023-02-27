/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:26:08 by myko              #+#    #+#             */
/*   Updated: 2023/02/27 19:13:44 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_dining	dining;

	if (check_arg(argc, argv, &dining))
		return (EXIT_FAILURE);
	if (philo_init(&dining))
		return (EXIT_FAILURE);
	if (dining_start(&dining))
		return (EXIT_FAILURE);
}
