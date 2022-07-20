/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:42:10 by myko              #+#    #+#             */
/*   Updated: 2022/07/20 17:14:21 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd)
{
	int		rd;
	int		idx;
	char	*tmp;
	char	*buff;
	char	*line;

	line = ft_strdup("");
	tmp = ft_strdup("");
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rd = read(fd, buff, BUFFER_SIZE);
	idx = ft_strchr(buff, '\n');
	while (rd > 0 && idx == -1)
	{
		line = ft_strjoin(line, buff);
		rd = read(fd, buff, BUFFER_SIZE);
		idx = ft_strchr(buff, '\n');
	}
	if (idx >= 0)
	{
		ft_strlcpy(tmp, buff, idx + 2);
		line = ft_strjoin(line, tmp);
	}
	free(buff);
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_read(fd);
	return (line);
}
