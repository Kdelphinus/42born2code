#include "cub3d.h"

void	key_rotate(int keycode, t_ray *ray)
{
	double	old_dir;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = ray->rot_speed;
	if (keycode == KEY_LEFT)
		rot_speed = -rot_speed;
	old_dir = ray->dir[X];
	ray->dir[X] = ray->dir[X] * cos(rot_speed) - ray->dir[Y] \
	* sin(rot_speed);
	ray->dir[Y] = old_dir * sin(rot_speed) + ray->dir[Y] \
	* cos(rot_speed);
	old_plane_x = ray->plane[X];
	ray->plane[X] = ray->plane[X] * cos(rot_speed) - ray->plane[Y] \
	* sin(rot_speed);
	ray->plane[Y] = old_plane_x * sin(rot_speed) + ray->plane[Y] \
	* cos(rot_speed);
}

void	move_side(int keycode, t_ray *ray, char **map)
{
	double	tmp_dir[2];

	tmp_dir[X] = -ray->dir[Y];
	tmp_dir[Y] = ray->dir[X];
	if (keycode == KEY_D)
	{
		if (map[(int)(ray->pos[Y] + tmp_dir[Y] \
		* ray->move_speed)][(int)(ray->pos[X])] != '1')
			ray->pos[Y] += tmp_dir[Y] * ray->move_speed;
		if (map[(int)(ray->pos[Y])][(int)(ray->pos[X] + tmp_dir[X] \
		* ray->move_speed)] != '1')
			ray->pos[X] += tmp_dir[X] * ray->move_speed;
	}
	else if (keycode == KEY_A)
	{
		if (map[(int)(ray->pos[Y] - tmp_dir[Y] \
		* ray->move_speed)][(int)(ray->pos[X])] != '1')
			ray->pos[Y] -= tmp_dir[Y] * ray->move_speed;
		if (map[(int)(ray->pos[Y])][(int)(ray->pos[X] - tmp_dir[X] \
		* ray->move_speed)] != '1')
			ray->pos[X] -= tmp_dir[X] * ray->move_speed;
	}
}

void	key_move(int keycode, t_ray *ray, char **map)
{
	if (keycode == KEY_W)
	{
		if (map[(int)(ray->pos[Y] + ray->dir[Y] \
		* ray->move_speed)][(int)(ray->pos[X])] != '1')
			ray->pos[Y] += ray->dir[Y] * ray->move_speed;
		if (map[(int)(ray->pos[Y])][(int)(ray->pos[X] + ray->dir[X] \
		* ray->move_speed)] != '1')
			ray->pos[X] += ray->dir[X] * ray->move_speed;
	}
	else if (keycode == KEY_S)
	{
		if (map[(int)(ray->pos[Y] - ray->dir[Y] \
		* ray->move_speed)][(int)(ray->pos[X])] != '1')
			ray->pos[Y] -= ray->dir[Y] * ray->move_speed;
		if (map[(int)(ray->pos[Y])][(int)(ray->pos[X] - ray->dir[X] \
		* ray->move_speed)] != '1')
			ray->pos[X] -= ray->dir[X] * ray->move_speed;
	}
	else
		move_side(keycode, ray, map);
}

int	key_press(int keycode, t_game_info *game_info)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_A \
	|| keycode == KEY_S || keycode == KEY_D)
		key_move(keycode, game_info->ray, game_info->map_data->map);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		key_rotate(keycode, game_info->ray);
	return (0);
}
