/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:19:38 by jaekkang          #+#    #+#             */
/*   Updated: 2023/04/17 21:19:39 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	temp;
	unsigned char	*ptr_temp;
	size_t			i;

	temp = (unsigned char)c;
	ptr_temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr_temp[i] == temp)
			return (ptr_temp + i);
		i++;
	}
	return (0);
}
