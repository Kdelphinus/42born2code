/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:38:17 by myko              #+#    #+#             */
/*   Updated: 2022/10/06 17:28:56 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	coloring_green(int coor, int value, t_img *img, int max_r)
{
	if (value == max_r)
		img->data[coor] = 0x6dcf6d;
	else if (value > max_r * 0.9)
		img->data[coor] = 0x4baf4b;
	else if (value > max_r * 0.8)
		img->data[coor] = 0x46aa46;
	else if (value > max_r * 0.7)
		img->data[coor] = 0x41a541;
	else if (value > max_r * 0.6)
		img->data[coor] = 0x3ca03c;
	else if (value > max_r * 0.5)
		img->data[coor] = 0x329632;
	else if (value > max_r * 0.3)
		img->data[coor] = 0x288c28;
	else if (value > max_r * 0.1)
		img->data[coor] = 0x1e821e;
	else if (value > 3)
		img->data[coor] = 0x147814;
	else if (value > 2)
		img->data[coor] = 0x0a6e0a;
	else
		img->data[coor] = 0x006400;
}

static void	coloring_blue(int coor, int value, t_img *img, int max_r)
{
	if (value == max_r)
		img->data[coor] = 0xd3eeff;
	else if (value > max_r * 0.9)
		img->data[coor] = 0xb1ccf0;
	else if (value > max_r * 0.8)
		img->data[coor] = 0x7fa7dc;
	else if (value > max_r * 0.7)
		img->data[coor] = 0x6e9ddc;
	else if (value > max_r * 0.6)
		img->data[coor] = 0x5c93dc;
	else if (value > max_r * 0.5)
		img->data[coor] = 0x4b89dc;
	else if (value > max_r * 0.3)
		img->data[coor] = 0x397edc;
	else if (value > max_r * 0.1)
		img->data[coor] = 0x2774dc;
	else if (value > 3)
		img->data[coor] = 0x166adc;
	else if (value > 2)
		img->data[coor] = 0x065acc;
	else
		img->data[coor] = 0x064abc;
}

static void	coloring_achromatic(int coor, int value, t_img *img, int max_r)
{
	if (value == max_r)
		img->data[coor] = 0xffffff;
	else if (value > max_r * 0.9)
		img->data[coor] = 0xd3d3d3;
	else if (value > max_r * 0.8)
		img->data[coor] = 0xa9a9a9;
	else if (value > max_r * 0.7)
		img->data[coor] = 0x949494;
	else if (value > max_r * 0.6)
		img->data[coor] = 0x808080;
	else if (value > max_r * 0.5)
		img->data[coor] = 0x6a6a6a;
	else if (value > max_r * 0.3)
		img->data[coor] = 0x545454;
	else if (value > max_r * 0.1)
		img->data[coor] = 0x3f3f3f;
	else if (value > 3)
		img->data[coor] = 0x2c2c2c;
	else if (value > 2)
		img->data[coor] = 0x191919;
	else
		img->data[coor] = 0x000000;
}

void	coloring(int coor, int value, t_frac *frac)
{
	if (frac->color % 3 == 0)
		coloring_achromatic(coor, value, frac->img, frac->max_r);
	else if (frac->color % 3 == 1)
		coloring_blue(coor, value, frac->img, frac->max_r);
	else if (frac->color % 3 == 2)
		coloring_green(coor, value, frac->img, frac->max_r);
}
