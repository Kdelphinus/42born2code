/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spider_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2023/02/09 13:39:43 by myko             ###   ########.fr       */
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

static int	spider_calculation(t_comp *comp, int max_r, int n)
{
	double	x;
	double	y;
	double	cc_r;
	double	cc_i;

	x = 0;
	y = 0;
	cc_r = comp->c_r;
	cc_i = comp->c_i;
	while (++n <= max_r)
	{
		x = pow(comp->z_r, 2) - pow(comp->z_i, 2) + comp->c_r;
		y = 2 * comp->z_r * comp->z_i + comp->c_i;
		if ((pow(x, 2) + pow(y, 2)) > pow(BOUNDARY, 2))
			break ;
		comp->z_r = x;
		comp->z_i = y;
		comp->c_r = comp->c_r / 2 + comp->z_r;
		comp->c_i = comp->c_i / 2 + comp->z_i;
	}
	comp->c_i = cc_i;
	comp->c_r = cc_r;
	return (n);
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

void	spider_draw(t_frac *frac)
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
			value = spider_calculation(frac->comp, frac->max_r, -1);
			coloring(coor, value, frac);
			frac->comp->c_r += fix / SIDE;
			frac->comp->z_r = 0;
			frac->comp->z_i = 0;
		}
		frac->comp->c_i += fix / SIDE;
		frac->comp->c_r = -frac->c_bd + frac->move_rl;
	}
}
