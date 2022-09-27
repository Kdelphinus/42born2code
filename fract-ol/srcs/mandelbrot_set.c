/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/09/27 15:03:44 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	complex_init(t_complex *complex)
{
	complex->z_real = 0;
	complex->z_imagin = 0;
	complex->c_real = -COOR_BOUNDARY;
	complex->c_imagin = -COOR_BOUNDARY;
}

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

static void	mandel_coloring(int coor, int value, t_img *img)
{
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
}

void	mandel_draw(t_complex *complex, t_img *img)
{
	int	value;
	int	coor;

	complex_init(complex);
	while (complex->c_imagin <= COOR_BOUNDARY)
	{
		while (complex->c_real <= COOR_BOUNDARY)
		{
			coor = (complex->c_imagin + COOR_BOUNDARY) * 100 * WIDTH + \
				(complex->c_real + COOR_BOUNDARY) * 100;
			value = mandelbrot(complex);
			mandel_coloring(coor, value, img);
			complex->c_real += 0.01;
			complex->z_real = 0;
			complex->z_imagin = 0;
		}
		complex->c_imagin += 0.01;
		complex->c_real = -COOR_BOUNDARY;
	}
}
