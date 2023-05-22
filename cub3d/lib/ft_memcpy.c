/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:19:48 by jaekkang          #+#    #+#             */
/*   Updated: 2023/04/17 21:19:49 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*temp_dst;
	const unsigned char	*temp_src;
	size_t				i;

	i = 0;
	if (!dst && !src)
		return (dst);
	temp_dst = (unsigned char *)dst;
	temp_src = (const unsigned char *)src;
	if (dst < src)
	{
		while (i < n)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	else if (dst > src)
	{
		i = n;
		while (i-- > 0)
			temp_dst[i] = temp_src[i];
	}
	return (dst);
}
