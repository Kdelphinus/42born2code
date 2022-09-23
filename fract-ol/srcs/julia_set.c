/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/09/23 17:16:11 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

static void	complex_init(t_complex *complex)
{
	complex->z_real = -5;
	complex->z_imagin = -5;
	complex->c_real = -0.194;
	complex->c_imagin = 0.656;
}

void	julia_draw(t_complex *complex, t_img *img)
{
	int		value;
	int		coor;
	double	tmp_real;
	double	tmp_imagin;

	complex_init(complex);
	while (complex->z_imagin <= 5)
	{
		tmp_imagin = complex->z_imagin;
		while (complex->z_real <= 5)
		{
			tmp_real = complex->z_real;
			coor = (int)((complex->z_imagin + 5) * 100) * WIDTH + \
				(int)((complex->z_real + 5) * 100);
			value = julia(complex);
			if (value == SUCCESS)
				img->data[coor] = 0x006AFF;
			// else if (value > 2)
			// 	img->data[coor] = 0x408FFF;
			// else if (value > 1)
			// 	img->data[coor] = 0x80B5FF;
			// else if (value > 0)
			// 	img->data[coor] = 0xBFDAFF;
			else
				img->data[coor] = 0xFFFFFF;
			complex->z_real = tmp_real + 0.01;
			complex->z_imagin = tmp_imagin;
		}
		complex->z_imagin = tmp_imagin + 0.01;
		complex->z_real = -5;
	}
}
