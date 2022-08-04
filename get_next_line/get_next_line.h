/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:43:07 by myko              #+#    #+#             */
/*   Updated: 2022/07/20 17:11:08 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, const char *s2);
int		ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		ft_strlcpy(char *dst, const char *src, int dstsize);

#endif