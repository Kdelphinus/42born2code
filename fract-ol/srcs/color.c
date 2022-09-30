/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:38:17 by myko              #+#    #+#             */
/*   Updated: 2022/09/30 16:56:18 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	coloring_green(int coor, int value, t_img *img)
{
	if (value == MAX_REPEAT)
		img->data[coor] = 0x6dcf6d;
	else if (value > 100)
		img->data[coor] = 0x4baf4b;
	else if (value > 80)
		img->data[coor] = 0x46aa46;
	else if (value > 60)
		img->data[coor] = 0x41a541;
	else if (value > 40)
		img->data[coor] = 0x3ca03c;
	else if (value > 20)
		img->data[coor] = 0x329632;
	else if (value > 10)
		img->data[coor] = 0x288c28;
	else if (value > 5)
		img->data[coor] = 0x1e821e;
	else if (value > 3)
		img->data[coor] = 0x147814;
	else if (value > 2)
		img->data[coor] = 0x0a6e0a;
	else
		img->data[coor] = 0x006400;
}

static void	coloring_blue(int coor, int value, t_img *img)
{
	if (value == MAX_REPEAT)
		img->data[coor] = 0xd3eeff;
	else if (value > 100)
		img->data[coor] = 0xb1ccf0;
	else if (value > 80)
		img->data[coor] = 0x7fa7dc;
	else if (value > 60)
		img->data[coor] = 0x6e9ddc;
	else if (value > 40)
		img->data[coor] = 0x5c93dc;
	else if (value > 20)
		img->data[coor] = 0x4b89dc;
	else if (value > 10)
		img->data[coor] = 0x397edc;
	else if (value > 5)
		img->data[coor] = 0x2774dc;
	else if (value > 3)
		img->data[coor] = 0x166adc;
	else if (value > 2)
		img->data[coor] = 0x065acc;
	else
		img->data[coor] = 0x064abc;
}

void	coloring(int coor, int value, t_frac *frac)
{
	if (frac->color == 1)
		coloring_blue(coor, value, frac->img);
	else if (frac->color == -1)
		coloring_green(coor, value, frac->img);
}
