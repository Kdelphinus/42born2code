#include "../../includes/cub3d.h"

void	free_data(char **data)
{
	int	i;

	i = -1;
	while (data[++i])
		free(data[i]);
	free(data);
}
