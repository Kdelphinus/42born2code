/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_fractals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:28:58 by myko              #+#    #+#             */
/*   Updated: 2023/03/13 21:39:45 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	comp_init(t_frac *frac)
{
	frac->multi = 0;
	frac->comp->z_r = 0;
	frac->comp->z_i = 0;
	frac->comp->c_r = -frac->c_bd + frac->move_rl;
	frac->comp->c_i = -frac->c_bd + frac->move_ud;
}

static int	newton_calculation(t_comp *comp, int max_r)
{
	double	x;
	double	y;
	int		n;

	x = 0;
	y = 0;
	n = -1;
	while (++n <= max_r)
	{
		x = (pow(pow(comp->z_r, 2) + pow(comp->z_i, 2), 3 / 2.0) \
			* cos(3 * atan2(comp->z_i, comp->z_r)) \
			+ comp->c_r - 1) \
			/ (3 * (pow(comp->z_r, 2) - pow(comp->z_i, 2) + comp->c_r));
		y = (pow(pow(comp->z_r, 2) + pow(comp->z_i, 2), 3 / 2.0) \
			* sin(3 * atan2(comp->z_i, comp->z_r)) \
			+ comp->c_i) \
			/ (3 * (2 * comp->z_r * comp->z_i + comp->c_i));
		if ((pow(x, 2) + pow(y, 2)) > pow(BOUNDARY, 2))
			return (n);
		comp->z_r = x ;
		comp->z_i = y;
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

void	newton_draw(t_frac *frac)
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
			value = newton_calculation(frac->comp, frac->max_r);
			coloring(coor, value, frac);
			frac->comp->c_r += fix / SIDE;
			frac->comp->z_r = 0;
			frac->comp->z_i = 0;
		}
		frac->comp->c_i += fix / SIDE;
		frac->comp->c_r = -frac->c_bd + frac->move_rl;
	}
}
