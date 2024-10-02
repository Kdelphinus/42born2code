#include "../../includes/cub3d.h"

void	check_extension(char *file_name)
{
	int	len;

	len = ft_strlen(file_name) - 1;
	if (len < 4 || file_name[len - 3] != '.' || file_name[len - 2] != 'c' \
		|| file_name[len - 1] != 'u' || file_name[len] != 'b' )
		print_err_exit(NOFILE);
}

void	check_texture(char *line, t_game_info *info)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_split(line, ' ');
	if (!check_tmp_invalid(info, line, tmp))
		return ;
	tmp[1][ft_strlen(tmp[1]) - 1] = '\0';
	if (!ft_strcmp(tmp[0], "NO"))
		allocate_dir(tmp, info, NO);
	else if (!ft_strcmp(tmp[0], "SO"))
		allocate_dir(tmp, info, SO);
	else if (!ft_strcmp(tmp[0], "WE"))
		allocate_dir(tmp, info, WE);
	else if (!ft_strcmp(tmp[0], "EA"))
		allocate_dir(tmp, info, EA);
	else if (!ft_strcmp(tmp[0], "F"))
		allocate_flr(tmp, info);
	else if (!ft_strcmp(tmp[0], "C"))
		allocate_ceil(tmp, info);
	else
		info->stop_flag = TRUE;
	free_data(tmp);
	if (info->stop_flag != TRUE)
		free(line);
}

void	check_object_map(char **map, t_obj *obj, int x, int y)
{
	if (y == 0 || y == obj->h - 1 || x == 0 || x == obj->w - 1)
		print_err_exit(NOWALL);
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' '
	|| map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
		print_err_exit(NOWALL);
}
