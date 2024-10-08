/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:36:15 by myko              #+#    #+#             */
/*   Updated: 2023/01/10 17:06:02 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

static int	gnl_read(int fd, char **c_line, char **buff)
{
	int		rd;
	int		idx;

	rd = read(fd, *buff, BUFFER_SIZE);
	if (rd <= 0)
		return (-2);
	(*buff)[rd] = 0;
	idx = gnl_strchr(*buff, '\n');
	while (idx == -1)
	{
		*c_line = gnl_strljoin(*c_line, *buff, rd);
		rd = read(fd, *buff, BUFFER_SIZE);
		if (rd <= 0)
			return (-2);
		(*buff)[rd] = 0;
		idx = gnl_strchr(*buff, '\n');
	}
	return (idx);
}

static char	*gnl_remain_line(char **line)
{
	int		idx;
	char	*tmp;
	char	*c_line;

	idx = gnl_strchr(*line, '\n');
	c_line = gnl_strljoin(0, *line, idx + 1);
	if (idx + 1 == gnl_strlen(*line))
	{
		free(*line);
		*line = 0;
	}
	else
	{
		tmp = gnl_strdup(*line + idx + 1);
		free(*line);
		*line = gnl_strdup(tmp);
		free(tmp);
	}
	return (c_line);
}

static char	*gnl_follow_up(char **c_line, char **buff, char **line, int idx)
{
	if (idx == -2)
	{
		free(*buff);
		if (*c_line)
			return (*c_line);
		return (char_free(line, c_line));
	}
	if (idx >= 0)
	{
		*c_line = gnl_strljoin(*c_line, *buff, idx + 1);
		free(*line);
		if (idx + 1 == gnl_strlen(*buff))
			*line = 0;
		else
			*line = gnl_strdup(*buff + idx + 1);
	}
	free(*buff);
	return (*c_line);
}

static char	*error_handler(char **line)
{
	if (*line)
		free(*line);
	*line = NULL;
	return (0);
}

char	*get_next_line(int fd)
{
	int			idx;
	char		*buff;
	char		*c_line;
	static char	*line;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (error_handler(&line));
	if (line && gnl_strchr(line, '\n') > -1)
		return (gnl_remain_line(&line));
	else if (line)
	{
		c_line = gnl_strdup(line);
		free(line);
		line = 0;
	}
	else
		c_line = 0;
	buff = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (buff == 0)
		return (char_free(&line, &c_line));
	idx = gnl_read(fd, &c_line, &buff);
	return (gnl_follow_up(&c_line, &buff, &line, idx));
}
