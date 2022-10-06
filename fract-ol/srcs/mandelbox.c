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

static void	comp_init(t_frac *frac)
{
	frac->multi = 1;
	frac->c_bd = 7;
	frac->comp->z_r = 0;
	frac->comp->z_i = 0;
	frac->comp->c_r = -frac->c_bd + frac->move_rl;
	frac->comp->c_i = -frac->c_bd + frac->move_ud;
	if (!frac->flag)
	{
		if (frac->c_argc == 3)
			frac->d = str_to_double(frac->c_argv[2]);
		else
			frac->d = 2;
		frac->flag = 1;
	}
}

static void	z_calculation(t_comp *comp)
{
	if (comp->z_r > 1)
			comp->z_r = 2 - comp->z_r;
	else if (comp->z_r < -1)
		comp->z_r = -2 - comp->z_r;
	if (comp->z_i > 1)
		comp->z_i = 2 - comp->z_i;
	else if (comp->z_i < -1)
		comp->z_i = -2 - comp->z_i;
}

static int	mandelbox_calculation(t_comp *comp, double scale, int max_r)
{
	int		n;

	n = -1;
	while (++n <= max_r)
	{
		z_calculation(comp);
		if (pow(comp->z_i, 2) + pow(comp->z_r, 2) < 0.5)
		{
			comp->z_i *= 2;
			comp->z_r *= 2;
		}
		else if (pow(comp->z_i, 2) + pow(comp->z_r, 2) < 1)
		{
			comp->z_i /= pow(comp->z_i, 2) + pow(comp->z_r, 2);
			comp->z_r /= pow(comp->z_i, 2) + pow(comp->z_r, 2);
		}
		if (pow(comp->z_i, 2) + pow(comp->z_r, 2) > pow(BOUNDARY, 10))
			return (n);
		comp->z_i = scale * comp->z_i + comp->c_i;
		comp->z_r = scale * comp->z_r + comp->c_r;
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

void	mandelbox_draw(t_frac *frac)
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
			value = mandelbox_calculation(frac->comp, frac->d, frac->max_r);
			coloring(coor, value, frac);
			frac->comp->c_r += fix / SIDE;
			frac->comp->z_r = 0;
			frac->comp->z_i = 0;
		}
		frac->comp->c_i += fix / SIDE;
		frac->comp->c_r = -fix / 2 + frac->move_rl;
	}
}
