#include "cub3d.h"

int	main_loop(t_game_info *game_info)
{
	ray_cast(game_info->ray, game_info);
	mlx_put_image_to_window(game_info->mlx, game_info->win, \
	game_info->img->img_ptr, 0, 0);
	return (0);
}

static int	ft_close(void)
{
	exit(0);
}

int	main(int ac, char **av)
{
	t_game_info	*game_info;

	if (ac != 2)
		print_err_exit(WRONGARG);
	game_info = (t_game_info *)malloc(sizeof(t_game_info));
	parsing(game_info, av[1]);
	mlx_hook(game_info->win, X_EVENT_KEY_PRESS, 0, &key_press, game_info);
	mlx_hook(game_info->win, X_EVENT_KEY_EXIT, 0, &ft_close, NULL);
	mlx_loop_hook(game_info->mlx, &main_loop, game_info);
	mlx_loop(game_info->mlx);
	return (0);
}
