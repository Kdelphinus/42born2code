/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:22 by myko              #+#    #+#             */
/*   Updated: 2022/09/30 18:31:21 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// TODO 왜 printf문을 없애면 segmentation fault가 뜨는가
static void	all_init(t_frac *frac)
{
	t_img	image;
	void	*mlx;

	mlx = mlx_init();
	frac->mlx_ptr = mlx;
	frac->win = mlx_new_window(frac->mlx_ptr, SIDE, SIDE, "fract-ol");
	image.img_ptr = mlx_new_image(frac->mlx_ptr, SIDE, SIDE);
	image.data = (int *)mlx_get_data_addr(image.img_ptr, &image.bpp, \
			&image.size_l, &image.endian);
	frac->img = &image;
	frac->flag = 0;
	frac->color = 1;
	frac->c_bd = 2;
	printf("init done\n");
}

// TODO 이미지 이동 구현
static int	key_press(int keycode, t_frac *frac)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_AR)
		frac->color = 0;
	else if (keycode == KEY_A)
		frac->color = 1;
	else if (keycode == KEY_B)
		frac->color = 2;
	else if (keycode == KEY_G)
		frac->color = 3;
	return (0);
}

// TODO x, y는 마우스의 위치
static int	mouse_scroll(int scroll, int x, int y, t_frac *frac)
{
	(void)x;
	(void)y;
	if (scroll == SCROLL_UP)
		frac->c_bd *= 0.95;
	else if (scroll == SCROLL_DOWN)
		frac->c_bd *= 1.05;
	fractal_draw(frac);
	mlx_put_image_to_window(frac->mlx_ptr, frac->win, frac->img->img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_frac	frac;

	all_init(&frac);
	frac.c_argv = argv;
	frac.c_argc = argc;
	if (!fractal_draw(&frac))
		return (ft_error());
	mlx_put_image_to_window(frac.mlx_ptr, frac.win, frac.img->img_ptr, 0, 0);
	mlx_mouse_hook(frac.win, &mouse_scroll, &frac);
	mlx_hook(frac.win, X_EVENT_KEY_PRESS, 0, &key_press, &frac);
	mlx_hook(frac.win, X_EVENT_KEY_EXIT, 0, &ft_close, &frac);
	mlx_loop(frac.mlx_ptr);
}
