#include "../../includes/cub3d.h"

void	allocate_dir(char **data, t_game_info *info, t_dir dir)
{
	t_texture	*cur;

	cur = info->map_data->textures;
	if (cur[dir].img != NULL)
		print_err_exit(WRONGDATA);
	cur[dir].img = mlx_xpm_file_to_image(info->mlx, data[1],
			&cur[dir].img_w, &cur[dir].img_h);
	if (cur[dir].img == NULL)
		print_err_exit(WRONGDATA);
	cur[dir].path = ft_strdup(data[1]);
}
