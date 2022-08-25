/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:36:15 by myko              #+#    #+#             */
/*   Updated: 2022/08/25 14:06:37 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read(int fd, char *c_line, char *buff)
{
	int	rd;
	int	idx;

	rd = read(fd, buff, BUFFER_SIZE);
	if (rd <= 0)
	{
		free(buff);
		return (-2);
	}
	idx = ft_strchr(buff, '\n');
	while (rd > 0 && idx == -1)
	{
		c_line = ft_strljoin(c_line, buff, BUFFER_SIZE);
		rd = read(fd, buff, BUFFER_SIZE);
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	c_line = ft_strdup("");
	if (line != 0)
		c_line = ft_strdup(line);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == 0)
		return (0);
	idx = ft_read(fd, c_line, buff);
	if (idx == -2)
		return (0);
	if (idx >= 0)
	{
		c_line = ft_strljoin(c_line, buff, idx + 1);
		line = ft_strdup(buff + idx + 1);
	}
	free(buff);
	return (c_line);
}
