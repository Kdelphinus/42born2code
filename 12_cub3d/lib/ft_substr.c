/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:22:23 by jaekkang          #+#    #+#             */
/*   Updated: 2023/04/17 21:22:23 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		len_str;
	size_t		i;
	char		*n_str;

	len_str = ft_strlen(s);
	if (len_str <= start)
		len = 0;
	else
		len_str -= start;
	if (len_str < len)
		len = len_str;
	n_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!n_str)
		return (0);
	i = 0;
	while (i < len)
	{
		n_str[i] = s[start + i];
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
