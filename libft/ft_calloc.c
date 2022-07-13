/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:17:32 by myko              #+#    #+#             */
/*   Updated: 2022/07/13 12:46:46 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;

	if (size != 0 && (size * count) / size != count)
		return (0);
	r = malloc(size * count);
	if (r == 0)
		return (0);
	ft_bzero(r, count * size);
	return (r);
}
