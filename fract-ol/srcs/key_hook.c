/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:22:39 by myko              #+#    #+#             */
/*   Updated: 2022/10/05 21:15:20 by myko             ###   ########.fr       */
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

// TODO 줌인이 될 수록 움직이는 범위가 너무 큼
int	mouse_scroll(int scroll, int x, int y, t_frac *frac)
{
	if (scroll == SCROLL_UP)
	{
		frac->c_bd *= 1.05;
		frac->move_rl += ((x - SIDE / 2.0) / SIDE) / (frac->c_bd * frac->c_bd);
		frac->move_ud += ((y - SIDE / 2.0) / SIDE) / (frac->c_bd * frac->c_bd);
	}
	else if (scroll == SCROLL_DOWN)
	{
		frac->c_bd *= 0.95;
		frac->move_rl += ((x - SIDE / 2.0) / SIDE) / (frac->c_bd * frac->c_bd);
		frac->move_ud += ((y - SIDE / 2.0) / SIDE) / (frac->c_bd * frac->c_bd);
	}
	return (0);
}
