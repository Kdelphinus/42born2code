#include "cub3d.h"

void	ray_dir_init(int x, t_ray *ray)
{
	ray->camera_x = 2 * x / (double)SCREENWIDTH - 1;
	ray->ray_dir[X] = ray->dir[X] + ray->plane[X] * ray->camera_x;
	ray->ray_dir[Y] = ray->dir[Y] + ray->plane[Y] * ray->camera_x;
	ray->map[X] = (int)ray->pos[X];
	ray->map[Y] = (int)ray->pos[Y];
	ray->delta_dist[X] = fabs(1 / ray->ray_dir[X]);
	ray->delta_dist[Y] = fabs(1 / ray->ray_dir[Y]);
}

void	ray_step_init(t_ray *ray)
{
	if (ray->ray_dir[X] < 0)
	{
		ray->step[X] = -1;
		ray->side_dist[X] = (ray->pos[X] - ray->map[X]) * ray->delta_dist[X];
	}
	else
	{
		ray->step[X] = 1;
		ray->side_dist[X] = (ray->map[X] + 1.0 - ray->pos[X]) * \
		ray->delta_dist[X];
	}
	if (ray->ray_dir[Y] < 0)
	{
		ray->step[Y] = -1;
		ray->side_dist[Y] = (ray->pos[Y] - ray->map[Y]) * ray->delta_dist[Y];
	}
	else
	{
		ray->step[Y] = 1;
		ray->side_dist[Y] = (ray->map[Y] + 1.0 - ray->pos[Y]) * \
		ray->delta_dist[Y];
	}
}

void	dda(t_ray *ray, t_map_data *map_data)
{
	while (1)
	{
		if (ray->side_dist[X] < ray->side_dist[Y])
		{
			ray->side_dist[X] += ray->delta_dist[X];
			ray->map[X] += ray->step[X];
			ray->side = 0;
		}
		else
		{
			ray->side_dist[Y] += ray->delta_dist[Y];
			ray->map[Y] += ray->step[Y];
			ray->side = 1;
		}
		if (map_data->map[ray->map[Y]][ray->map[X]] == '1')
			break ;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map[X] - ray->pos[X] + \
		(1 - ray->step[X]) / 2) / ray->ray_dir[X];
	else
		ray->perp_wall_dist = (ray->map[Y] - ray->pos[Y] + \
		(1 - ray->step[Y]) / 2) / ray->ray_dir[Y];
}

void	ray_cast(t_ray *ray, t_game_info *game_info)
{
	int	x;

	x = -1;
	window_init(game_info->map_data, game_info->img);
	while (++x < SCREENWIDTH)
	{
		ray_dir_init(x, ray);                                        // ray의 방향 초기화
		ray_step_init(ray);                                          // ray가 나가는 방향 초기화 및 가까운 x, y면 거리 계산
		dda(ray, game_info->map_data);                               // dda 알고리즘으로 벽의 좌표 계산
		choice_tex(ray);                                             // 벽까지의 거리와 어느 텍스쳐를 출력할 지 결정
		put_color(x, ray, game_info->map_data->textures, game_info); // 각 벽에 대해서 텍스쳐의 비율 조정 및 픽셀값 입력
	}
	ray->frame_time = 0.022;
	ray->move_speed = ray->frame_time * 15.0;                        // 플레이어가 움직이는 속도
	ray->rot_speed = ray->frame_time * 3.0;                          // 플레이어의 시야가 회전하는 속도
}
