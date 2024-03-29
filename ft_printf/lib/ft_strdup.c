/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:18:32 by myko              #+#    #+#             */
/*   Updated: 2022/07/07 19:18:33 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		s1_len;
	char	*s2;

	i = 0;
	s1_len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (s2 == 0)
		return (0);
	while (i < s1_len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
