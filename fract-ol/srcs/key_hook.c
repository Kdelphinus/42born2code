/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:22:39 by myko              #+#    #+#             */
/*   Updated: 2022/10/05 19:44:23 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_press(int keycode, t_frac *frac)
{
	if (keycode == KEY_ESC)
	{
		ft_all_free(frac);
		ft_close();
	}
	else if (keycode == KEY_AR)
		frac->color = 0;
	else if (keycode == KEY_A)
		frac->color = 1;
	else if (keycode == KEY_B)
		frac->color = 2;
	else if (keycode == KEY_G)
		frac->color = 3;
	else if (keycode == KEY_UP)
		frac->move_ud -= frac->c_bd / 10.0;
	else if (keycode == KEY_DOWN)
		frac->move_ud += frac->c_bd / 10.0;
	else if (keycode == KEY_RIGHT)
		frac->move_rl += frac->c_bd / 10.0;
	else if (keycode == KEY_LEFT)
		frac->move_rl -= frac->c_bd / 10.0;
	return (0);
}

int	mouse_scroll(int scroll, int x, int y, t_frac *frac)
{
	if (scroll == SCROLL_UP)
	{
		frac->move_rl += (x - SIDE / 2.0) / SIDE;
		frac->move_ud += (y - SIDE / 2.0) / SIDE;
		frac->c_bd *= 0.9;
	}
	else if (scroll == SCROLL_DOWN)
	{
		frac->move_rl += (x - SIDE / 2.0) / SIDE;
		frac->move_ud += (y - SIDE / 2.0) / SIDE;
		frac->c_bd *= 1.1;
	}
	return (0);
}
