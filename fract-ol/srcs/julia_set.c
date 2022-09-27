/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/09/27 16:57:18 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	complex_init(t_complex *complex)
{
	complex->z_real = -COOR_BOUNDARY;
	complex->z_imagin = -COOR_BOUNDARY;
	// complex->c_real = 0.2733;
	// complex->c_imagin = -0.0074;
	complex->c_real = -0.5125;
	complex->c_imagin = 0.5213;
}

static int	julia(t_complex *complex)
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

static void	julia_coloring(int coor, int value, t_img *img)
{
	if (value == SUCCESS || value > 100)
		img->data[coor] = 0x4baf4b;
	else if (value > 80)
		img->data[coor] = 0x46aa46;
	else if (value > 60)
		img->data[coor] = 0x41a541;
	else if (value > 40)
		img->data[coor] = 0x3ca03c;
	else if (value > 20)
		img->data[coor] = 0x329632;
	else if (value > 10)
		img->data[coor] = 0x288c28;
	else if (value > 5)
		img->data[coor] = 0x1e821e;
	else if (value > 3)
		img->data[coor] = 0x147814;
	else if (value > 2)
		img->data[coor] = 0x0a6e0a;
	else
		img->data[coor] = 0x006400;
}

void	julia_draw(t_complex *complex, t_img *img)
{
	int		value;
	int		coor;
	double	tmp_real;
	double	tmp_imagin;

	complex_init(complex);
	while (complex->z_imagin <= COOR_BOUNDARY)
	{
		tmp_imagin = complex->z_imagin;
		while (complex->z_real <= COOR_BOUNDARY)
		{
			tmp_real = complex->z_real;
			coor = (complex->z_imagin + COOR_BOUNDARY) * 100 * WIDTH + \
				(complex->z_real + COOR_BOUNDARY) * 100;
			value = julia(complex);
			julia_coloring(coor, value, img);
			complex->z_real = tmp_real + 0.01;
			complex->z_imagin = tmp_imagin;
		}
		complex->z_imagin = tmp_imagin + 0.01;
		complex->z_real = -COOR_BOUNDARY;
	}
}
