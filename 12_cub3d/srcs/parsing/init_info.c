#include "cub3d.h"

static void	texture_init(t_texture *textures)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		textures[i].img = NULL;
		textures[i].path = NULL;
		textures[i].img_w = 0;
		textures[i].img_h = 0;
		++i;
	}
}

void	ray_init(t_ray *ray)
{
	ray->pos[X] = 5.5;
	ray->pos[Y] = 9.5;
	ray->dir[X] = 1;
	ray->dir[Y] = 0;
	ray->plane[X] = 0;
	ray->plane[Y] = 0.66;
	ray->camera_x = 0;
	ray->ray_dir[X] = 0;
	ray->ray_dir[Y] = 0;
	ray->side_dist[X] = 0;
	ray->side_dist[Y] = 0;
	ray->delta_dist[X] = 0;
	ray->delta_dist[Y] = 0;
	ray->step[X] = 0;
	ray->step[Y] = 0;
}

void	img_init(t_game_info *game_info)
{
	game_info->img->img_ptr = mlx_new_image(game_info->mlx,
			SCREENWIDTH, SCREENHEIGHT);
	game_info->img->data = (int *)mlx_get_data_addr(game_info->img->img_ptr,
			&game_info->img->bpp, &game_info->img->size_l,
			&game_info->img->endian);
}

void	info_init(t_game_info *info, t_obj *obj)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, SCREENWIDTH, SCREENHEIGHT, "./cub3d");
	info->stop_flag = FALSE;
	info->map_data = malloc(sizeof(t_map_data));
	info->map_data->map = NULL;
	info->map_data->flr_color = 0;
	info->map_data->flr_count = 0;
	info->map_data->ceil_color = 0;
	info->map_data->ceil_count = 0;
	info->map_data->textures = malloc(sizeof(t_texture) * 4);
	texture_init(info->map_data->textures);
	info->ray = malloc(sizeof(t_ray));
	ray_init(info->ray);
	info->img = malloc(sizeof(t_img));
	img_init(info);
	obj->p_cnt = 0;
	obj->w = 0;
	obj->h = 0;
}
