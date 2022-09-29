/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:22 by myko              #+#    #+#             */
/*   Updated: 2022/09/30 01:25:12 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	all_init(t_fractal *fractal)
{
	t_img	image;
	void	*mlx;

	mlx = mlx_init();
	fractal->mlx_ptr = mlx;
	fractal->win = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	image.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	image.data = (int *)mlx_get_data_addr(image.img_ptr, &image.bpp, \
			&image.size_l, &image.endian);
	fractal->img = &image;
	printf("img done\n");
	fractal->color = -1;
	fractal->coor_boundary = 2;
}

// TODO 이미지를 변환할 방법을 찾아야 함
static int	key_press(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		fractal->color *= -1;
	return (0);
}

// TODO zoom 기능을 추가해야 함
static int	mouse_scroll(int scroll, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (scroll == SCROLL_UP)
		fractal->coor_boundary *= 0.9;
	else if (scroll == SCROLL_DOWN)
		fractal->coor_boundary *= 1.1;
	mandel_draw(fractal);
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win, fractal->img->img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	int			flag;

	if (argc == 1)
		return (ft_error());
	flag = kind_fractal(argv[1]);
	if (!flag)
		return (ft_error());
	all_init(&fractal);
	if (flag == 1)
		mandel_draw(&fractal);
	else if (flag == 2)
		julia_draw(&fractal, argc, argv);
	else if (flag == 3)
		multibrot_draw(&fractal, argc, argv);
	mlx_put_image_to_window(fractal.mlx_ptr, fractal.win, fractal.img->img_ptr, 0, 0);
	mlx_mouse_hook(fractal.win, &mouse_scroll, &fractal);
	mlx_hook(fractal.win, X_EVENT_KEY_PRESS, 0, &key_press, &fractal);
	mlx_hook(fractal.win, X_EVENT_KEY_EXIT, 0, &ft_close, &fractal);
	mlx_loop(fractal.mlx_ptr);
}
