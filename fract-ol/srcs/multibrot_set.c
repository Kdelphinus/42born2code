/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/10/05 18:51:49 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	complex_init(t_frac *frac)
{
	frac->multi = 1;
	frac->complex->z_r = 0;
	frac->complex->z_i = 0;
	frac->complex->c_r = -frac->c_bd + frac->move_rl;
	frac->complex->c_i = -frac->c_bd + frac->move_ud;
	if (!frac->flag)
	{
		if (frac->c_argc == 3)
			frac->d = str_to_double(frac->c_argv[2]);
		else
		{
			printf("Set default value.\nd: 4\n");
			frac->d = 4;
		}
		frac->flag = 1;
	}
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

static int	coor_calculation(t_frac *frac, double fix)
{
	int	coor;

	coor = (frac->complex->c_i + frac->c_bd - frac->move_ud) \
		* (SIDE / fix) * SIDE \
		+ (frac->complex->c_r + frac->c_bd - frac->move_rl) \
		* (SIDE / fix);
	return (coor);
}

void	multibrot_draw(t_frac *frac)
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
			value = multibrot_calculation(frac->complex, frac->d);
			coloring(coor, value, frac);
			frac->complex->c_r += fix / SIDE;
			frac->complex->z_r = 0;
			frac->complex->z_i = 0;
		}
		frac->complex->c_i += fix / SIDE;
		frac->complex->c_r = -fix / 2 + frac->move_rl;
	}
}
