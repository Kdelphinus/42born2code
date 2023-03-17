/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:18:54 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/16 01:10:31 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_after_trim(char *str, char const *set)
{
	char	*temp;
	size_t	str_len;
	size_t	len;

	str_len = ft_strlen(str);
	if (str_len == 0)
		return (0);
	len = 0;
	temp = str + str_len - 1;
	while (ft_strchr(set, *temp))
	{
		str++;
		len++;
	}
	if (str_len == len)
		return (0);
	while (ft_strchr(set, *temp))
	{
		temp--;
		len++;
	}
	return (str_len - len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	char	*str;
	char	*str_temp;
	size_t	len;

	if (!s1)
		return (0);
	temp = (char *)s1;
	len = ft_len_after_trim(temp, set);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str_temp = str;
	while (ft_strchr(set, *temp))
		temp++;
	while (len > 0)
	{
		*str_temp = *temp;
		str_temp++;
		temp++;
		len--;
	}
	*str_temp = '\0';
	return (str);
}
