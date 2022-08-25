/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:37:01 by myko              #+#    #+#             */
/*   Updated: 2022/08/25 13:40:51 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

int		ft_strlen(const char *s);
char	*ft_strljoin(char *s1, const char *s2, int s2_len);
int		ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);

#endif
