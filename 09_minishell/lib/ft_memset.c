/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:53:51 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/13 21:51:24 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp_b;
	unsigned char	uch_c;
	size_t			i;

	i = 0;
	uch_c = (unsigned char)c;
	temp_b = (unsigned char *)b;
	while (i < len)
	{
		temp_b[i] = uch_c;
		i++;
	}
	return (b);
}
