/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multicron.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/10/06 17:25:24 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	comp_init(t_frac *frac)
{
	frac->multi = 1;
	frac->comp->z_r = 0;
	frac->comp->z_i = 0;
	frac->comp->c_r = -frac->c_bd + frac->move_rl;
	frac->comp->c_i = -frac->c_bd + frac->move_ud;
	if (!frac->flag)
	{
		if (frac->c_argc == 3)
			frac->d = str_to_double(frac->c_argv[2]);
		else
		{
			printf("Set default value.\nd: 2\n");
			frac->d = 2;
		}
		frac->flag = 1;
	}
}

static int	multicron_calculation(t_comp *comp, double d, int max_r)
{
	double	x;
	double	y;
	int		n;

	x = 0;
	y = 0;
	n = -1;
	while (++n <= max_r)
	{
		x = pow(pow(comp->z_r, 2) + pow(comp->z_i, 2), d / 2.0) \
			* cos(d * atan2(comp->z_i, comp->z_r)) \
			+ comp->c_r;
		y = pow(pow(comp->z_r, 2) + pow(comp->z_i, 2), d / 2.0) \
			* sin(d * atan2(comp->z_i, comp->z_r)) \
			+ comp->c_i;
		if ((pow(x, 2) + pow(y, 2)) > pow(BOUNDARY, 2))
			return (n);
		comp->z_r = x;
		comp->z_i = -y;
	}
	return (max_r);
}

static int	coor_calculation(t_frac *frac, double fix)
{
	int	coor;

	coor = (frac->comp->c_i + frac->c_bd - frac->move_ud) \
		* (SIDE / fix) * SIDE \
		+ (frac->comp->c_r + frac->c_bd - frac->move_rl) \
		* (SIDE / fix);
	return (coor);
}

void	multicron_draw(t_frac *frac)
{
	int		value;
	int		coor;
	double	fix;

	comp_init(frac);
	fix = frac->c_bd * 2.0;
	while (frac->comp->c_i <= frac->c_bd + frac->move_ud)
	{
		while (frac->comp->c_r <= frac->c_bd + frac->move_rl)
		{
			coor = coor_calculation(frac, fix);
			value = multicron_calculation(frac->comp, frac->d, frac->max_r);
			coloring(coor, value, frac);
			frac->comp->c_r += fix / SIDE;
			frac->comp->z_r = 0;
			frac->comp->z_i = 0;
		}
		frac->comp->c_i += fix / SIDE;
		frac->comp->c_r = -fix / 2 + frac->move_rl;
	}
}
