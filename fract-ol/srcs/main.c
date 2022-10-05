/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:22 by myko              #+#    #+#             */
/*   Updated: 2022/10/05 16:45:04 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	img_init(t_frac *frac)
{
	t_img	*image;

	image = (t_img *)malloc(sizeof(t_img));
	if (!image)
	{
		free(frac->complex);
		free(frac);
		ft_close();
	}
	image->img_ptr = mlx_new_image(frac->mlx_ptr, SIDE, SIDE);
	image->data = (int *)mlx_get_data_addr(image->img_ptr, &image->bpp, \
			&image->size_l, &image->endian);
	frac->img = image;
}

static void	frac_init(t_frac *frac)
{
	void		*mlx;
	t_complex	*comp;

	comp = (t_complex *)malloc(sizeof(t_complex));
	if (!comp)
	{
		free(frac);
		ft_close();
	}
	frac->complex = comp;
	frac->flag = 0;
	frac->color = 0;
	frac->move_ud = 0;
	frac->move_rl = 0;
	frac->c_bd = 2;
	mlx = mlx_init();
	frac->mlx_ptr = mlx;
	frac->win = mlx_new_window(frac->mlx_ptr, SIDE, SIDE, "fract-ol");
	img_init(frac);
}

static int	key_press(int keycode, t_frac *frac)
{
	if (keycode == KEY_ESC)
		ft_close();
	if (keycode == KEY_AR)
		frac->color = 0;
	else if (keycode == KEY_A)
		frac->color = 1;
	else if (keycode == KEY_B)
		frac->color = 2;
	else if (keycode == KEY_G)
		frac->color = 3;
	if (keycode == KEY_UP)
		frac->move_ud -= frac->c_bd / 20.0;
	else if (keycode == KEY_DOWN)
		frac->move_ud += frac->c_bd / 20.0;
	else if (keycode == KEY_RIGHT)
		frac->move_rl += frac->c_bd / 20.0;
	else if (keycode == KEY_LEFT)
		frac->move_rl -= frac->c_bd / 20.0;
	fractal_draw(frac);
	mlx_put_image_to_window(frac->mlx_ptr, frac->win, frac->img->img_ptr, 0, 0);
	return (0);
}

// TODO 마우스 위치에 따라 줌인아웃 되도록
static int	mouse_scroll(int scroll, int x, int y, t_frac *frac)
{
	(void)x;
	(void)y;
	if (scroll == SCROLL_UP)
	{
		frac->c_bd *= 0.95;
		// frac->move_rl = 2 * frac->c_bd / (x - SIDE / 2.0);
		// frac->move_ud = 2 * frac->c_bd / (y - SIDE / 2.0);
	}
	else if (scroll == SCROLL_DOWN)
	{
		frac->c_bd *= 1.05;
		// frac->move_rl = 2 * frac->c_bd / (x - SIDE / 2.0);
		// frac->move_ud = 2 * frac->c_bd / (y - SIDE / 2.0);
	}
	fractal_draw(frac);
	mlx_put_image_to_window(frac->mlx_ptr, frac->win, frac->img->img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_frac	*frac;

	frac = (t_frac *)malloc(sizeof(t_frac));
	if (!frac)
		return (ft_close());
	frac_init(frac);
	frac->c_argv = argv;
	frac->c_argc = argc;
	if (!fractal_draw(frac))
	{
		free(frac->img);
		free(frac->complex);
		free(frac);
		return (ft_error());
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->win, frac->img->img_ptr, 0, 0);
	mlx_mouse_hook(frac->win, &mouse_scroll, frac);
	mlx_hook(frac->win, X_EVENT_KEY_PRESS, 0, &key_press, frac);
	mlx_hook(frac->win, X_EVENT_KEY_EXIT, 0, &ft_close, frac);
	mlx_loop(frac->mlx_ptr);
	return (0);
}
