/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/10/06 17:37:24 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	comp_init(t_frac *frac)
{
	frac->multi = 0;
	frac->comp->z_r = -frac->c_bd + frac->move_rl;
	frac->comp->z_i = -frac->c_bd + frac->move_ud;
	if (!frac->flag)
	{
		if (frac->c_argc != 4)
		{
			printf("Set default value.\nc_r: -0.5125, c_i: -0.5213\n");
			frac->comp->c_r = -0.5125;
			frac->comp->c_i = -0.5213;
		}
		else
		{
			frac->comp->c_r = str_to_double(frac->c_argv[2]);
			frac->comp->c_i = str_to_double(frac->c_argv[3]);
			printf("%f %f\n", frac->comp->c_r, frac->comp->c_i);
		}
		frac->flag = 1;
	}
}

static int	julia_calculation(t_comp *comp, int max_r)
{
	double	x;
	double	y;
	int		n;

	x = 0;
	y = 0;
	n = -1;
	while (++n <= max_r)
	{
		x = pow(comp->z_r, 2) - pow(comp->z_i, 2) + comp->c_r;
		y = 2 * comp->z_r * comp->z_i + comp->c_i;
		if ((pow(x, 2) + pow(y, 2)) > pow(BOUNDARY, 2))
			return (n);
		comp->z_r = x;
		comp->z_i = y;
	}
	return (max_r);
}

static int	coor_calculator(t_frac *frac, double fix)
{
	int	coor;

	coor = (frac->comp->z_i + frac->c_bd - frac->move_ud) \
		* (SIDE / fix) * SIDE \
		+ (frac->comp->z_r + frac->c_bd - frac->move_rl) \
		* (SIDE / fix);
	return (coor);
}

void	julia_draw(t_frac *frac)
{
	int		value;
	int		coor;
	double	tmp_r;
	double	tmp_i;
	double	fix;

	comp_init(frac);
	fix = frac->c_bd * 2.0;
	while (frac->comp->z_i <= frac->c_bd + frac->move_ud)
	{
		tmp_i = frac->comp->z_i;
		while (frac->comp->z_r <= frac->c_bd + frac->move_rl)
		{
			tmp_r = frac->comp->z_r;
			coor = coor_calculator(frac, fix);
			value = julia_calculation(frac->comp, frac->max_r);
			coloring(coor, value, frac);
			frac->comp->z_r = tmp_r + (fix / SIDE);
			frac->comp->z_i = tmp_i;
		}
		frac->comp->z_i = tmp_i + (fix / SIDE);
		frac->comp->z_r = -fix / 2 + frac->move_rl;
	}
}
