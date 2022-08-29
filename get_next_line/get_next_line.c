/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:36:15 by myko              #+#    #+#             */
/*   Updated: 2022/08/29 17:21:35 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_read(int fd, char **c_line, char *buff)
{
	int		rd;
	int		idx;

	rd = read(fd, buff, BUFFER_SIZE);
	if (rd <= 0)
		return (-2);
	idx = ft_strchr(buff, '\n');
	while (rd > 0 && idx == -1)
	{
		*c_line = ft_strljoin(*c_line, buff, rd);
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd <= 0)
			return (idx);
		idx = ft_strchr(buff, '\n');
	}
	return (idx);
}

char	*get_next_line(int fd)
{
	int			idx;
	char		*buff;
	char		*c_line;
	static char	*line;

	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (0);
	c_line = ft_strdup("");
	if (line && ft_strchr(line, '\n') > -1)
	{
		idx = ft_strchr(line, '\n');
		c_line = ft_strljoin(c_line, line, idx + 1);
		line += idx + 1;
		return (c_line);
	}
	else if (line)
		c_line = ft_strdup(line);
	buff = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (buff == 0)
		return (0);
	buff[BUFFER_SIZE] = 0;
	idx = ft_read(fd, &c_line, buff);
	if (idx == -2)
	{
		free(c_line);
		free(buff);
		return (0);
	}
	if (idx >= 0)
	{
		c_line = ft_strljoin(c_line, buff, idx + 1);
		line = ft_strdup(buff + idx + 1);
	}
	free(buff);
	return (c_line);
}
