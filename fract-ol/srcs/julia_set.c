/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/09/30 17:00:57 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	complex_init(t_frac *frac, t_complex *complex)
{
	complex->z_r = -frac->c_bd;
	complex->z_i = -frac->c_bd;
	if (frac->c_argc != 4)
	{
		if (!frac->flag)
		{
			printf("Set default value.\nc_r: -0.5125, c_i: -0.5213\n");
			frac->flag = 1;
		}
		complex->c_r = -0.5125;
		complex->c_i = -0.5213;
	}
	else
	{
		complex->c_r = str_to_double(frac->c_argv[2]);
		complex->c_i = str_to_double(frac->c_argv[3]);
	}
}

static int	julia_calculation(t_complex *complex)
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

void	julia_draw(t_frac *frac)
{
	int		value;
	int		coor;
	double	tmp_r;
	double	tmp_i;
	double	fix;

	complex_init(frac, frac->complex);
	fix = frac->c_bd * 2.0;
	while (frac->complex->z_i <= frac->c_bd)
	{
		tmp_i = frac->complex->z_i;
		while (frac->complex->z_r <= frac->c_bd)
		{
			tmp_r = frac->complex->z_r;
			coor = (frac->complex->z_i + frac->c_bd) * (SIDE / fix) \
				* SIDE + (frac->complex->z_r + frac->c_bd) * (SIDE / fix);
			value = julia_calculation(frac->complex);
			coloring(coor, value, frac);
			frac->complex->z_r = tmp_r + (fix / SIDE);
			frac->complex->z_i = tmp_i;
		}
		frac->complex->z_i = tmp_i + (fix / SIDE);
		frac->complex->z_r = -fix / 2;
	}
}
