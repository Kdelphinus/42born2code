#include "cub3d.h"

void	window_init(t_map_data *map_data, t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SCREENHEIGHT)
	{
		j = -1;
		while (++j < SCREENWIDTH)
		{
			if (i < SCREENHEIGHT / 2)
				img->data[i * SCREENWIDTH + j] = map_data->ceil_color;
			else
				img->data[i * SCREENWIDTH + j] = map_data->flr_color;
		}
	}
}

void	choice_tex(t_ray *ray)
{
	if (ray->side == 0 && ray->ray_dir[X] < 0)
		ray->tex_num = WE;
	else if (ray->side == 0 && ray->ray_dir[X] > 0)
		ray->tex_num = EA;
	else if (ray->side == 1 && ray->ray_dir[Y] < 0)
		ray->tex_num = NO;
	else if (ray->side == 1 && ray->ray_dir[Y] > 0)
		ray->tex_num = SO;
	if (ray->side == 0)
		ray->wall_x = ray->pos[Y] + ray->perp_wall_dist * ray->ray_dir[Y];
	else
		ray->wall_x = ray->pos[X] + ray->perp_wall_dist * ray->ray_dir[X];
	ray->wall_x -= floor(ray->wall_x);
	ray->tex[X] = (int)(ray->wall_x * (double)IMG_W);
	if (ray->side == 0 && ray->ray_dir[X] < 0)
		ray->tex[X] = IMG_W - ray->tex[X] - 1;
	if (ray->side == 1 && ray->ray_dir[Y] > 0)
		ray->tex[X] = IMG_W - ray->tex[X] - 1;
}

void	put_color(int x, t_ray *ray, t_texture *texture, t_game_info *game_info)
{
	int	j;
	int	*tex;
	int	img_info;
	int	color;

	ray->line_h = (int)(SCREENHEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_h / 2 + SCREENHEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_h / 2 + SCREENHEIGHT / 2;
	if (ray->draw_end >= SCREENHEIGHT)
		ray->draw_end = SCREENHEIGHT - 1;
	ray->step_d = 1.0 * IMG_H / ray->line_h;
	ray->tex_pos = (ray->draw_start - SCREENHEIGHT / 2 + ray->line_h / 2) \
	* ray->step_d;
	tex = (int *)mlx_get_data_addr(texture[ray->tex_num].img, &img_info, \
	&img_info, &img_info);
	j = ray->draw_start - 1;
	while (++j < ray->draw_end)
	{
		ray->tex[Y] = (int)ray->tex_pos;
		ray->tex_pos += ray->step_d;
		color = tex[ray->tex[Y] * IMG_W + ray->tex[X]];
		game_info->img->data[j * SCREENWIDTH + x] = color;
	}
}
