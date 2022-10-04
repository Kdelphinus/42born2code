/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:59:51 by myko              #+#    #+#             */
/*   Updated: 2022/09/30 21:59:51 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	complex_init(t_frac *frac)
{
	frac->multi = 1;
	frac->c_bd = 7;
	frac->complex->z_r = frac->move_rl;
	frac->complex->z_i = frac->move_ud;
	frac->complex->c_r = -frac->c_bd + frac->move_rl;
	frac->complex->c_i = -frac->c_bd + frac->move_ud;
	if (!frac->flag)
	{
		if (frac->c_argc == 3)
			frac->d = str_to_double(frac->c_argv[2]);
		else
			frac->d = 2;
		frac->flag = 1;
	}
}

static void	z_calculation(t_complex *complex)
{
	if (complex->z_r > 1)
			complex->z_r = 2 - complex->z_r;
	else if (complex->z_r < -1)
		complex->z_r = -2 - complex->z_r;
	if (complex->z_i > 1)
		complex->z_i = 2 - complex->z_i;
	else if (complex->z_i < -1)
		complex->z_i = -2 - complex->z_i;
}

static int	mandelbox_calculation(t_complex *complex, double scale)
{
	int		n;

	n = -1;
	while (++n <= MAX_REPEAT)
	{
		z_calculation(complex);
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

static int	coor_calculation(t_frac *frac, double fix)
{
	int	coor;

	coor = (frac->complex->c_i + frac->c_bd - frac->move_ud) \
		* (SIDE / fix) * SIDE \
		+ (frac->complex->c_r + frac->c_bd - frac->move_rl) \
		* (SIDE / fix);
	return (coor);
}

void	mandelbox_draw(t_frac *frac)
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
			value = mandelbox_calculation(frac->complex, frac->d);
			coloring(coor, value, frac);
			frac->complex->c_r += fix / SIDE;
			frac->complex->z_r = frac->move_rl;
			frac->complex->z_i = frac->move_ud;
		}
		frac->complex->c_i += fix / SIDE;
		frac->complex->c_r = -fix / 2 + frac->move_rl;
	}
}
