/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/09/27 18:09:59 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	complex_init(t_complex *complex, int argc, char **argv)
{
	complex->z_real = -COOR_BOUNDARY;
	complex->z_imagin = -COOR_BOUNDARY;
	if (argc != 4)
	{
		printf("Set default value.\nc_real: 0.3757, c_imagin: -0.3054\n");
		complex->c_real = -0.5125;
		complex->c_imagin = -0.5213;
	}
	else
	{
		complex->c_real = str_to_double(argv[2]);
		complex->c_imagin = str_to_double(argv[3]);
	}
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
	return (n);
}

void	julia_draw(t_complex *complex, t_img *img, int argc, char **argv)
{
	int		value;
	int		coor;
	double	tmp_real;
	double	tmp_imagin;

	complex_init(complex, argc, argv);
	while (complex->z_imagin <= COOR_BOUNDARY)
	{
		tmp_imagin = complex->z_imagin;
		while (complex->z_real <= COOR_BOUNDARY)
		{
			tmp_real = complex->z_real;
			coor = (complex->z_imagin + COOR_BOUNDARY) * 100 * WIDTH + \
				(complex->z_real + COOR_BOUNDARY) * 100;
			value = julia(complex);
			if (img->color == 1)
				coloring_green(coor, value, img);
			else
				coloring_blue(coor, value, img);
			complex->z_real = tmp_real + 0.01;
			complex->z_imagin = tmp_imagin;
		}
		complex->z_imagin = tmp_imagin + 0.01;
		complex->z_real = -COOR_BOUNDARY;
	}
}
