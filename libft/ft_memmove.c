/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:24:50 by myko              #+#    #+#             */
/*   Updated: 2022/07/06 19:29:36 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len && *(unsigned char *)(src + i))
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
	i--;
	while (++i < len)
		*(unsigned char *)(dst + i) = 0;
	return (dst);
}
