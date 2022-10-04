/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:17:48 by myko              #+#    #+#             */
/*   Updated: 2022/10/03 16:31:00 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(void)
{
	exit(0);
}

int	ft_error(void)
{
	printf("❌ Please enter one of the parameters below. ❌\n");
	printf("- mandelbrot\n");
	printf("- julia [c_r] [c_i]\n");
	printf("- multibrot [d]\n");
	printf("- mandelbox [scale]\n");
	return (-1);
}
