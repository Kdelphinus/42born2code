/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:18:06 by jaekkang          #+#    #+#             */
/*   Updated: 2023/04/17 21:18:08 by jaekkang         ###   ########.fr       */
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
