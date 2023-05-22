#include "../../includes/cub3d.h"

static void	set_ray(t_game_info *info, t_dir dir, int x, t_obj *obj)
{
	const double	ray_dir_x[4] = {0, 0, -1, 1};
	const double	ray_dir_y[4] = {-1, 1, 0, 0};
	const double	ray_plane_x[4] = {0.66, -0.66, 0, 0};
	const double	ray_plane_y[4] = {0, 0, -0.66, 0.66};

	info->ray->pos[X] = x + 0.5;
	info->ray->pos[Y] = obj->h + 0.5;
	info->ray->dir[X] = ray_dir_x[dir];
	info->ray->dir[Y] = ray_dir_y[dir];
	info->ray->plane[X] = ray_plane_x[dir];
	info->ray->plane[Y] = ray_plane_y[dir];
	obj->p_cnt++;
}

void	add_mapping_node(t_mapping **list, t_mapping *new_node)
{
	t_mapping	*cur;

	cur = *list;
	if (cur == NULL)
	{
		*list = new_node;
		return ;
	}
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new_node;
	new_node->next = NULL;
}

static int	check_obj(char *line, t_obj *obj, t_game_info *info)
{
	int	i;

	i = -1;
	while (line[++i] != '\n')
	{
		if (line[i] == '\0')
			break ;
		if (line[i] == 'N')
			set_ray(info, NO, i, obj);
		else if (line[i] == 'E')
			set_ray(info, EA, i, obj);
		else if (line[i] == 'S')
			set_ray(info, SO, i, obj);
		else if (line[i] == 'W')
			set_ray(info, WE, i, obj);
		else if (line[i] == ' ' || line[i] == '0' || line[i] == '1')
			continue ;
		else
			print_err_exit(WRONGDATA);
	}
	++obj->h;
	return (i);
}

t_mapping	*new_mapping(char *line, t_obj *obj, t_game_info *info)
{
	t_mapping	*ret;

	if (*line == '\n')
		print_err_exit(WRONGDATA);
	ret = (t_mapping *)malloc(sizeof(t_mapping));
	ret->line = line;
	ret->line_len = check_obj(line, obj, info);
	if (obj->w < ret->line_len)
		obj->w = ret->line_len;
	ret->next = NULL;
	return (ret);
}
