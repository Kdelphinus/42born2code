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

int	ft_val_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

size_t	ft_len_after_trim(char *str, char const *set)
{
	char	*temp;
	size_t	str_len;
	size_t	len;

	str_len = ft_strlen(str);
	if (str_len == 0)
		return (0);
	len = 0;
	temp = str + str_len - 1;
	while (ft_val_set(*str, set))
	{
		str++;
		len++;
	}
	if (str_len == len)
		return (0);
	while (ft_val_set(*temp, set))
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
	while (ft_val_set(*temp, set))
		temp++;
	while (len > 0)
	{
		*str = *temp;
		str++;
		temp++;
		len--;
	}
	*str = '\0';
	return (str_temp);
}
