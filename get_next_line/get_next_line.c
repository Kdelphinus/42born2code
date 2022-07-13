/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:42:10 by myko              #+#    #+#             */
/*   Updated: 2022/07/13 18:03:43 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	int		j;
	ssize_t	nr;
	char	*buff;
	char	*cbuff;

	buff = (char *)malloc(BUFFER_SIZE);
	if (buff == 0)
		return (0);
	nr = read(fd, buff, BUFFER_SIZE);
	while (nr > 0)
	{
		i = 0;
		while (i < nr && buff[i] != '\n')
			i++;
		j = 0;
		cbuff = (char *)malloc(i);
		while (j < i)
		{
			cbuff[j] = buff[j];
			j++;
		}
		free(buff);
		return (cbuff);
	}
	return (0);
}
