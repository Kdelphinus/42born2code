/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:22 by myko              #+#    #+#             */
/*   Updated: 2022/09/21 16:10:01 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	all_init(t_mlx *mlx, t_img *img, t_complex *complex)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, 500, 500, "mlx");
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, 50, 50);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
	complex->real = 0;
	complex->imaginary=0;
}

int	key_press(int keycode, t_complex *complex)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int	close(t_complex *complex)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_img		img;
	t_complex	complex;
	int			count_h;
	int			count_w;

	all_init(&mlx, &img, &complex);
	count_h = -1;
	while (++count_h < 50)
	{
		count_w = -1;
		while (++count_w < 50)
		{
			if (count_w % 2)
				img.data[count_h * 50 + count_w] = 0xFFFFFF;
			else
				img.data[count_h * 50 + count_w] = 0xFF0000;
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, img.img_ptr, 0, 0);
	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, &key_press, &complex);
	mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 0, &close, &complex);
	mlx_loop(mlx.mlx_ptr);
}