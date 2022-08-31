/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:24:51 by myko              #+#    #+#             */
/*   Updated: 2022/08/31 16:02:41 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "get_next_line.h"

int	main(void)
{
	int		idx = 1;
	int		fd;
	char	*str;
	
	fd = open("test", O_RDWR);
	while (1)
	{
		str = get_next_line(fd);
		printf("%d: <%s>\n", idx, str);
		idx++;
		if (!str)
		{
			free(str);
			break;
		}
		free(str);
	}
	close(fd);
	return (0);
}
