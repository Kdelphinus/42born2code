/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:16:50 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/15 22:01:59 by juyojeon         ###   ########.fr       */
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
