/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:22 by myko              #+#    #+#             */
/*   Updated: 2022/09/28 19:56:19 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	all_init(t_mlx *mlx, t_img *img, t_complex *complex)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, \
			&img->size_l, &img->endian);
	img->color = -1;
	complex->zoom = 0.1;
}

// TODO 이미지를 변환할 방법을 찾아야 함
static int	key_press(int keycode, t_img *img)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		img->color *= -1;
	return (0);
}

// TODO zoom 기능을 추가해야 함
static int	mouse_scroll(int scroll, int x, int y, t_complex *complex)
{
	(void)x;
	(void)y;
	if (scroll == SCROLL_UP)
		complex->zoom *= 0.9;
	else if (scroll == SCROLL_DOWN)
		complex->zoom += 1.1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_img		img;
	t_complex	complex;
	int			flag;

	if (argc == 1)
		return (ft_error());
	flag = kind_fractal(argv[1]);
	if (!flag)
		return (ft_error());
	all_init(&mlx, &img, &complex);
	if (flag == 1)
		mandel_draw(&complex, &img);
	else if (flag == 2)
		julia_draw(&complex, &img, argc, argv);
	else if (flag == 3)
		multibrot_draw(&complex, &img, argc, argv);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, img.img_ptr, 0, 0);
	mlx_mouse_hook(mlx.win, &mouse_scroll, &complex);
	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, &key_press, &img);
	mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 0, &ft_close, &img);
	mlx_loop(mlx.mlx_ptr);
}
