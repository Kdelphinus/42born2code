/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:42:10 by myko              #+#    #+#             */
/*   Updated: 2022/07/15 21:38:09 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_new_line(char *line)
{
	int		i;
	int		nl;
	char	*c_line;

	i = 0;
	nl = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		nl++;
	c_line = (char *)malloc(sizeof(char) * (i + 1 + nl));
	if (c_line == 0)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		c_line[i] = line[i];
		i++;
	}
	if (nl == 1)
		c_line[i++] = '\n';
	c_line[i] = 0;
	return (c_line);
}

static char	*get_read(char *line, int fd)
{
	ssize_t	rd;
	char	*buff;

	rd = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == 0)
		return (0);
	while (rd > 0 && !ft_strchr(buff, '\n'))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (0);
		}
		buff[rd] = 0;
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*n_line;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = get_read(line, fd);
	if (line == 0)
		return (0);
	n_line = get_new_line(line);
	return (n_line);
}
