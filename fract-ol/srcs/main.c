/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:22 by myko              #+#    #+#             */
/*   Updated: 2022/10/06 17:23:41 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	img_init(t_frac *frac)
{
	t_img	*image;

	image = (t_img *)malloc(sizeof(t_img));
	if (!image)
	{
		free(frac->comp);
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
	void	*mlx;
	t_comp	*comp;

	comp = (t_comp *)malloc(sizeof(t_comp));
	if (!comp)
	{
		free(frac);
		ft_close();
	}
	frac->comp = comp;
	frac->flag = 0;
	frac->kind = -1;
	frac->color = 0;
	frac->move_ud = 0;
	frac->move_rl = 0;
	frac->c_bd = 2;
	frac->max_r = 128;
	mlx = mlx_init();
	frac->mlx_ptr = mlx;
	frac->win = mlx_new_window(frac->mlx_ptr, SIDE, SIDE, "fract-ol");
	img_init(frac);
}

static int	main_loop(t_frac *frac)
{
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
	mlx_mouse_hook(frac->win, &mouse_scroll, frac);
	mlx_hook(frac->win, X_EVENT_KEY_PRESS, 0, &key_press, frac);
	mlx_hook(frac->win, X_EVENT_KEY_EXIT, 0, &ft_close, frac);
	if (!fractal_draw(frac))
	{
		ft_all_free(frac);
		return (ft_error());
	}
	mlx_loop_hook(frac->mlx_ptr, &main_loop, frac);
	mlx_loop(frac->mlx_ptr);
	return (0);
}
