/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/09/23 16:42:00 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mandelbrot(t_complex *complex)
{
	double	x;
	double	y;
	int		n;

	x = 0;
	y = 0;
	n = -1;
	while (n++ <= MAX_REPEAT)
	{
		x = pow(complex->z_real, 2) - pow(complex->z_imagin, 2) \
			+ complex->c_real;
		y = 2 * complex->z_real * complex->z_imagin + complex->c_imagin;
		if ((pow(x, 2) + pow(y, 2)) > pow(BOUNDARY, 2))
			return (n);
		complex->z_real = x;
		complex->z_imagin = y;
	}
	return (SUCCESS);
}

static void	complex_init(t_complex *complex)
{
	complex->z_real = 0;
	complex->z_imagin = 0;
	complex->c_real = -5;
	complex->c_imagin = -5;
}

void	mandel_draw(t_complex *complex, t_img *img)
{
	int	value;
	int	coor;

	complex_init(complex);
	while (complex->c_imagin <= 5)
	{
		while (complex->c_real <= 5)
		{
			coor = (int)((complex->c_imagin + 5) * 100) * WIDTH + \
				(int)((complex->c_real + 5) * 100);
			value = mandelbrot(complex);
			if (value == SUCCESS)
				img->data[coor] = 0x006AFF;
			else if (value > 2)
				img->data[coor] = 0x408FFF;
			else if (value > 1)
				img->data[coor] = 0x80B5FF;
			else if (value > 0)
				img->data[coor] = 0xBFDAFF;
			else
				img->data[coor] = 0xFFFFFF;
			complex->c_real += 0.01;
			complex->z_real = 0;
			complex->z_imagin = 0;
		}
		complex->c_imagin += 0.01;
		complex->c_real = -5;
	}
}
