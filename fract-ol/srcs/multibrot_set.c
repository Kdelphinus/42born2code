/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/09/30 17:00:27 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	complex_init(t_frac *frac, t_complex *complex)
{
	complex->z_r = 0;
	complex->z_i = 0;
	complex->c_r = -frac->c_bd;
	complex->c_i = -frac->c_bd;
	if (frac->c_argc == 3)
		return (str_to_double(frac->c_argv[2]));
	if (!frac->flag)
	{
		printf("Set default value.\nd: 6\n");
		frac->flag = 1;
	}
	return (6);
}

static int	multibrot_calculation(t_complex *complex, double d)
{
	double	x;
	double	y;
	int		n;

	x = 0;
	y = 0;
	n = -1;
	while (++n <= MAX_REPEAT)
	{
		x = pow(pow(complex->z_r, 2) + pow(complex->z_i, 2), d / 2.0) \
			* cos(d * atan2(complex->z_i, complex->z_r)) \
			+ complex->c_r;
		y = pow(pow(complex->z_r, 2) + pow(complex->z_i, 2), d / 2.0) \
			* sin(d * atan2(complex->z_i, complex->z_r)) \
			+ complex->c_i;
		if ((pow(x, 2) + pow(y, 2)) > pow(BOUNDARY, 2))
			return (n);
		complex->z_r = x;
		complex->z_i = y;
	}
	return (MAX_REPEAT);
}

void	multibrot_draw(t_frac *frac)
{
	int		value;
	int		coor;
	double	d;
	double	fix;

	d = complex_init(frac, frac->complex);
	fix = frac->c_bd * 2.0;
	while (frac->complex->c_i <= frac->c_bd)
	{
		while (frac->complex->c_r <= frac->c_bd)
		{
			coor = (frac->complex->c_i + frac->c_bd) * (SIDE / fix) \
				* SIDE + (frac->complex->c_r + frac->c_bd) * (SIDE / fix);
			value = multibrot_calculation(frac->complex, d);
			coloring(coor, value, frac);
			frac->complex->c_r += fix / SIDE;
			frac->complex->z_r = 0;
			frac->complex->z_i = 0;
		}
		frac->complex->c_i += fix / SIDE;
		frac->complex->c_r = -fix / 2;
	}
}
