/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:22 by myko              #+#    #+#             */
/*   Updated: 2022/09/27 14:24:41 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	all_init(t_mlx *mlx, t_img *img)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, \
			&img->size_l, &img->endian);
}

static int	key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

static int	mouse_scroll(int scroll)

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_img		img;
	t_complex	complex;
	int			flag;

	if (argc != 2)
		return (ft_error());
	all_init(&mlx, &img);
	flag = kind_fractal(argv[1]);
	if (flag == 1)
		mandel_draw(&complex, &img);
	else if (flag == 2)
		julia_draw(&complex, &img);
	else
		return (ft_error());
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, img.img_ptr, 0, 0);
	mlx_mouse_hook(mlx.win, );
	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, &key_press, &complex);
	mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 0, &close, &complex);
	mlx_loop(mlx.mlx_ptr);
}