/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:06:07 by myko              #+#    #+#             */
/*   Updated: 2022/09/30 17:06:07 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	complex_init(t_frac *frac, t_complex *complex)
{
	frac->c_bd = 7;
	complex->z_r = 0;
	complex->z_i = 0;
	complex->c_r = -frac->c_bd;
	complex->c_i = -frac->c_bd;
	if (frac->c_argc == 3)
		return (str_to_double(frac->c_argv[2]));
	if (!frac->flag)
	{
		printf("Set default value.\nd: 2\n");
		frac->flag = 1;
	}
	return (2);
}

static int	mandelbox_calculation(t_complex *complex, double scale)
{
	int		n;

	n = -1;
	while (++n <= MAX_REPEAT)
	{
		if (complex->z_r > 1)
			complex->z_r = 2 - complex->z_r;
		else if (complex->z_r < -1)
			complex->z_r = -2 - complex->z_r;
		if (complex->z_i > 1)
			complex->z_i = 2 - complex->z_i;
		else if (complex->z_i < -1)
			complex->z_i = -2 - complex->z_i;
		if (pow(complex->z_i, 2) + pow(complex->z_r, 2) < 0.5)
		{
			complex->z_i *= 2;
			complex->z_r *= 2;
		}
		else if (pow(complex->z_i, 2) + pow(complex->z_r, 2) < 1)
		{
			complex->z_i /= pow(complex->z_i, 2) + pow(complex->z_r, 2);
			complex->z_r /= pow(complex->z_i, 2) + pow(complex->z_r, 2);
		}
		if (pow(complex->z_i, 2) + pow(complex->z_r, 2) > pow(BOUNDARY, 10))
			return (n);
		complex->z_i = scale * complex->z_i + complex->c_i;
		complex->z_r = scale * complex->z_r + complex->c_r;
	}
	return (MAX_REPEAT);
}

void	mandelbox_draw(t_frac *frac)
{
	int		value;
	int		coor;
	double	fix;
	double	scale;

	scale = complex_init(frac, frac->complex);
	fix = frac->c_bd * 2.0;
	while (frac->complex->c_i <= frac->c_bd)
	{
		while (frac->complex->c_r <= frac->c_bd)
		{
			coor = (frac->complex->c_i + frac->c_bd) * (SIDE / fix) \
				* SIDE + (frac->complex->c_r + frac->c_bd) * (SIDE / fix);
			value = mandelbox_calculation(frac->complex, scale);
			coloring(coor, value, frac);
			frac->complex->c_r += fix / SIDE;
			frac->complex->z_r = 0;
			frac->complex->z_i = 0;
		}
		frac->complex->c_i += fix / SIDE;
		frac->complex->c_r = -fix / 2;
	}
}