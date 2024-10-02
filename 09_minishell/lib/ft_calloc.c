/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:04:12 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/22 20:29:09 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	arr_size;
	char	*temp;
	void	*ptr;

	arr_size = size * count;
	ptr = malloc(arr_size);
	if (!ptr)
		return (0);
	i = 0;
	temp = (char *)ptr;
	while (i < arr_size)
	{
		temp[i] = 0;
		i++;
	}
	return (ptr);
}
