/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:22:39 by myko              #+#    #+#             */
/*   Updated: 2022/10/05 18:05:00 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// TODO 화살표로 움직이다 보면 그림이 깨짐
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
		frac->move_ud -= frac->c_bd / 20.0;
	else if (keycode == KEY_DOWN)
		frac->move_ud += frac->c_bd / 20.0;
	else if (keycode == KEY_RIGHT)
		frac->move_rl += frac->c_bd / 20.0;
	else if (keycode == KEY_LEFT)
		frac->move_rl -= frac->c_bd / 20.0;
	return (0);
}

// TODO 마우스 위치에 따라 줌인아웃 되도록
int	mouse_scroll(int scroll, int x, int y, t_frac *frac)
{
	(void)x;
	(void)y;
	if (scroll == SCROLL_UP)
	{
		frac->c_bd *= 0.75;
		// frac->move_rl = 2 * frac->c_bd / (x - SIDE / 2.0);
		// frac->move_ud = 2 * frac->c_bd / (y - SIDE / 2.0);
	}
	else if (scroll == SCROLL_DOWN)
	{
		frac->c_bd *= 1.25;
		// frac->move_rl = 2 * frac->c_bd / (x - SIDE / 2.0);
		// frac->move_ud = 2 * frac->c_bd / (y - SIDE / 2.0);
	}
	return (0);
}
