#include "../../includes/cub3d.h"

void	read_map(t_game_info *info, t_obj *obj, t_mapping *m_head, int i)
{
	t_mapping	*tmp;

	tmp = m_head;
	info->map_data->map = malloc(sizeof(char *) * obj->h);
	while (++i < obj->h)
	{
		info->map_data->map[i] = malloc(sizeof(char) * obj->w);
		ft_strlcpy(info->map_data->map[i], tmp->line, tmp->line_len + 1);
		while (obj->w > tmp->line_len)
		{
			info->map_data->map[i][tmp->line_len] = ' ';
			++tmp->line_len;
		}
		tmp = tmp->next;
	}
	while (m_head != NULL)
	{
		free(m_head->line);
		tmp = m_head->next;
		free(m_head);
		m_head = tmp;
	}
}
