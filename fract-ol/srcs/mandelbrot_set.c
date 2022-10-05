/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/10/05 16:39:17 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	complex_init(t_frac *frac)
{
	frac->multi = 0;
	frac->complex->z_r = frac->move_rl;
	frac->complex->z_i = frac->move_ud;
	frac->complex->c_r = -frac->c_bd + frac->move_rl;
	frac->complex->c_i = -frac->c_bd + frac->move_ud;
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

static int	coor_calculation(t_frac *frac, double fix)
{
	int	coor;

	coor = (frac->complex->c_i + frac->c_bd - frac->move_ud) \
		* (SIDE / fix) * SIDE \
		+ (frac->complex->c_r + frac->c_bd - frac->move_rl) \
		* (SIDE / fix);
	return (coor);
}

void	mandelbrot_draw(t_frac *frac)
{
	int		value;
	int		coor;
	double	fix;

	complex_init(frac);
	fix = frac->c_bd * 2.0;
	while (frac->complex->c_i <= frac->c_bd + frac->move_ud)
	{
		while (frac->complex->c_r <= frac->c_bd + frac->move_rl)
		{
			coor = coor_calculation(frac, fix);
			value = mandelbrot_calculation(frac->complex);
			coloring(coor, value, frac);
			frac->complex->c_r += fix / SIDE;
			frac->complex->z_r = frac->move_rl;
			frac->complex->z_i = frac->move_ud;
		}
		frac->complex->c_i += fix / SIDE;
		frac->complex->c_r = -fix / 2 + frac->move_rl;
	}
}
