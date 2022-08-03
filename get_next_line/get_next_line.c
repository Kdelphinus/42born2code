/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:42:10 by myko              #+#    #+#             */
/*   Updated: 2022/07/21 16:40:09 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char **line)
{
	int		rd;
	int		idx;
	char	*tmp;
	char	*buff;
	char	*c_line;

	c_line = ft_strdup("");
	tmp = ft_strdup("");
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == 0)
		return (0);
	rd = read(fd, buff, BUFFER_SIZE);
	if (rd <= 0)
		return (0);
	idx = ft_strchr(buff, '\n');
	while (rd > 0 && idx == -1)
	{
		c_line = ft_strjoin(c_line, buff);
		rd = read(fd, buff, BUFFER_SIZE);
		idx = ft_strchr(buff, '\n');
	}
	if (idx >= 0)
	{
		ft_strlcpy(tmp, buff, idx + 1);
		c_line = ft_strjoin(c_line, tmp);
		*line = ft_strdup(buff + idx + 1);
	}
	free(buff);
	free(tmp);
	return (c_line);
}

char	*get_next_line(int fd)
{
	char		*c_line;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	c_line = ft_read(fd, &line);
	return (c_line);
}
