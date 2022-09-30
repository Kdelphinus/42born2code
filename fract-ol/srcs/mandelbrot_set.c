/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/09/30 16:53:04 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	complex_init(t_frac *frac, t_complex *complex)
{
	complex->z_r = 0;
	complex->z_i = 0;
	complex->c_r = -frac->c_bd;
	complex->c_i = -frac->c_bd;
}

static int	mandelbrot_calculation(t_complex *complex)
{
	double	x;
	double	y;
	int		n;

	x = 0;
	y = 0;
	n = -1;
	while (++n <= MAX_REPEAT)
	{
		x = pow(complex->z_r, 2) - pow(complex->z_i, 2) + complex->c_r;
		y = 2 * complex->z_r * complex->z_i + complex->c_i;
		if ((pow(x, 2) + pow(y, 2)) > pow(BOUNDARY, 2))
			return (n);
		complex->z_r = x;
		complex->z_i = y;
	}
	return (MAX_REPEAT);
}

void	mandelbrot_draw(t_frac *frac)
{
	int		value;
	int		coor;
	double	fix;

	complex_init(frac, frac->complex);
	fix = frac->c_bd * 2.0;
	while (frac->complex->c_i <= frac->c_bd)
	{
		while (frac->complex->c_r <= frac->c_bd)
		{
			coor = (frac->complex->c_i + frac->c_bd) * (SIDE / fix) \
				* SIDE + (frac->complex->c_r + frac->c_bd) * (SIDE / fix);
			value = mandelbrot_calculation(frac->complex);
			coloring(coor, value, frac);
			frac->complex->c_r += fix / SIDE;
			frac->complex->z_r = 0;
			frac->complex->z_i = 0;
		}
		frac->complex->c_i += fix / SIDE;
		frac->complex->c_r = -fix / 2;
	}
}
