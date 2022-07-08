/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:18:38 by myko              #+#    #+#             */
/*   Updated: 2022/07/08 10:50:54 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*sj;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	sj = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (sj == 0)
		return (0);
	while (i < s1_len)
	{
		sj[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		sj[i + s1_len] = s2[i];
		i++;
	}
	sj[i + s1_len] = 0;
	return (sj);
}
