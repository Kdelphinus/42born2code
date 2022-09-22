/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/09/22 20:10:12 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mandelbrot(t_complex *complex)
{
	double	x;
	double	y;
	int	n;

	x = 0;
	y = 0;
	n = -1;
	while (n++ <= MAX_REPEAT)
	{
		x = pow(complex->z_real, 2) - pow(complex->z_imaginary, 2) \
			+ complex->c_real / 100;
		y = 2 * complex->z_real * complex->z_imaginary + complex->c_imaginary / 100;
		if ((pow(x, 2) + pow(y, 2)) > BOUNDARY)
			return (n);
		complex->z_real = x;
		complex->z_imaginary = y;
	}
	return (SUCCESS);
}

void	mandel_draw(t_complex *complex, t_img *img)
{
	int	value;
	int	coor;

	while (complex->c_imaginary <= 200)
	{
		while (complex->c_real <= 300)
		{
			value = mandelbrot(complex);
			coor = (int)(complex->c_imaginary + 200) * WIDTH + ((int)complex->c_real + 300);
			if (value == SUCCESS)
				img->data[coor] = 0xFFFFFF;
			else
				img->data[coor] = 0x333333;
			complex->c_real++;
			complex->z_real = 0;
			complex->z_imaginary = 0;
		}
		complex->c_imaginary++;
		complex->c_real = -300;
	}
}