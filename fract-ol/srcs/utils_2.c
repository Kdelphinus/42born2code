/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:17:48 by myko              #+#    #+#             */
/*   Updated: 2022/09/27 22:07:40 by myko             ###   ########.fr       */
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
	printf("- julia [c_real] [c_imagin]\n");
	printf("- multibrot [d]\n");
	return (-1);
}
