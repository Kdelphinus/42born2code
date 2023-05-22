/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:11:26 by jaekkang          #+#    #+#             */
/*   Updated: 2023/04/27 14:02:19 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*ft_util(t_info *info)
{
	info->idx = 0;
	while (info->line[info->idx] != '\n' && info->line[info->idx] != '\0')
		info->idx++;
	if (info->line[info->idx] == '\0')
		return (NULL);
	info->ret = ft_substr(info->line, info->idx + 1, \
				ft_strlen(info->line) - info->idx);
	if (!info->ret)
		return (NULL);
	if (!info->ret[0])
	{
		free(info->ret);
		info->ret = NULL;
		return (NULL);
	}
	info->line[info->idx + 1] = '\0';
	return (info->ret);
}

static char	*ft_read_line(t_info *info)
{
	info->idx = 1;
	while (info->idx)
	{
		info->idx = read(info->fd, info->buf, BUFFER_SIZE);
		if (info->idx == -1)
			return (NULL);
		else if (info->idx == 0)
			break ;
		info->buf[info->idx] = '\0';
		if (!info->save)
			info->save = ft_strdup("");
		info->ret = info->save;
		info->save = ft_strjoin(info->ret, info->buf);
		if (!info->save)
			return (NULL);
		free(info->ret);
		info->ret = NULL;
		if (ft_strchr(info->buf, '\n'))
			break ;
	}
	return (info->save);
}

char	*get_next_line(int fd)
{
	static t_info	info;

	info.fd = fd;
	if (read(fd, NULL, 0) == -1)
		return (NULL);
	info.buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!info.buf)
		return (NULL);
	info.line = ft_read_line(&info);
	free(info.buf);
	info.buf = NULL;
	if (!info.line)
		return (NULL);
	info.save = ft_util(&info);
	return (info.line);
}
