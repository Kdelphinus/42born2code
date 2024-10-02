/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:17:48 by myko              #+#    #+#             */
/*   Updated: 2023/03/13 21:35:46 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_close(void)
{
	exit(EXIT_SUCCESS);
}

void	ft_all_free(t_frac *frac)
{
	free(frac->img);
	free(frac->comp);
	free(frac);
}

int	ft_error(void)
{
	printf("Please enter one of the parameters below.\n");
	printf("- mandelbrot\n");
	printf("- julia [c_r] [c_i]\n");
	printf("- multibrot [d]\n");
	printf("- mandelbox [scale]\n");
	printf("- multicron [d]\n");
	printf("- burning\n");
	printf("- spider\n");
	printf("- newton\n");
	return (-1);
}
