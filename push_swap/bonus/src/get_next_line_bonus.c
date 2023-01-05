/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:36:15 by myko              #+#    #+#             */
/*   Updated: 2023/01/05 21:55:23 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static int	ft_read(int fd, char **c_line, char **buff)
{
	int		rd;
	int		idx;

	rd = read(fd, *buff, 1024);
	if (rd <= 0)
		return (-2);
	(*buff)[rd] = 0;
	idx = ft_strchr(*buff, '\n');
	while (idx == -1)
	{
		*c_line = ft_strljoin(*c_line, *buff, rd);
		rd = read(fd, *buff, 1024);
		if (rd <= 0)
			return (-2);
		(*buff)[rd] = 0;
		idx = ft_strchr(*buff, '\n');
	}
	return (idx);
}

static char	*ft_remain_line(char **line)
{
	int		idx;
	char	*tmp;
	char	*c_line;

	idx = ft_strchr(*line, '\n');
	c_line = ft_strljoin(0, *line, idx + 1);
	if (idx + 1 == ft_strlen(*line))
	{
		free(*line);
		*line = 0;
	}
	else
	{
		tmp = ft_strdup(*line + idx + 1);
		free(*line);
		*line = ft_strdup(tmp);
		free(tmp);
	}
	return (c_line);
}

static char	*ft_follow_up(char **c_line, char **buff, char **line, int idx)
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
		*c_line = ft_strljoin(*c_line, *buff, idx + 1);
		free(*line);
		if (idx + 1 == ft_strlen(*buff))
			*line = 0;
		else
			*line = ft_strdup(*buff + idx + 1);
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

	if (read(fd, 0, 0) < 0 || 1024 <= 0)
		return (error_handler(&line));
	if (line && ft_strchr(line, '\n') > -1)
		return (ft_remain_line(&line));
	else if (line)
	{
		c_line = ft_strdup(line);
		free(line);
		line = 0;
	}
	else
		c_line = 0;
	buff = (char *)malloc(sizeof(char) * ((size_t)1024 + 1));
	if (buff == 0)
		return (char_free(&line, &c_line));
	idx = ft_read(fd, &c_line, &buff);
	return (ft_follow_up(&c_line, &buff, &line, idx));
}
