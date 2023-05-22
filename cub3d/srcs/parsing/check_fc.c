#include "../../includes/cub3d.h"

int	check_tmp_invalid(t_game_info *info, char *line, char **tmp)
{
	if (tmp == NULL)
		print_err_exit(WRONGDATA);
	if (ft_strlen(tmp[0]) > 3 || tmp[1] == NULL || tmp[2] != NULL)
	{
		if (tmp[0][0] == '\n')
		{
			free_data(tmp);
			free(line);
			return (0);
		}
		info->stop_flag = TRUE;
		free_data(tmp);
		return (0);
	}
	return (1);
}

int	simple_atoi(const char *str)
{
	int			sum;

	sum = 0;
	while (TRUE)
	{
		if (*str >= '0' && *str <= '9')
		{
			sum = (sum * 10) + (*str - '0');
			if (sum > 255)
				print_err_exit(WRONGDATA);
			str++;
		}
		else if (*str == '\0')
			return (sum);
		else
			print_err_exit(WRONGDATA);
	}
}

char	**simple_split_rgb(char *line)
{
	int	i;
	int	comma_cnt;

	i = 0;
	comma_cnt = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			++comma_cnt;
		++i;
	}
	if (comma_cnt != 2)
		print_err_exit(WRONGDATA);
	return (ft_split(line, ','));
}

void	allocate_flr(char **data, t_game_info *info)
{
	char	**rgb;
	int		i;

	i = 0;
	if (info->map_data->flr_count != 0)
		print_err_exit(WRONGDATA);
	++info->map_data->flr_count;
	rgb = simple_split_rgb(data[1]);
	if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL)
		print_err_exit(WRONGDATA);
	info->map_data->flr_color = simple_atoi(rgb[0]) << 16
		| simple_atoi(rgb[1]) << 8 | simple_atoi(rgb[2]);
	free_data(rgb);
}

void	allocate_ceil(char **data, t_game_info *info)
{
	char	**rgb;
	int		i;

	i = 0;
	if (info->map_data->ceil_count != 0)
		print_err_exit(WRONGDATA);
	++info->map_data->ceil_count;
	rgb = simple_split_rgb(data[1]);
	if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL)
		print_err_exit(WRONGDATA);
	info->map_data->ceil_color = simple_atoi(rgb[0]) << 16
		| simple_atoi(rgb[1]) << 8 | simple_atoi(rgb[2]);
	free_data(rgb);
}
