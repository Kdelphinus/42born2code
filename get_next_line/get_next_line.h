/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:37:01 by myko              #+#    #+#             */
/*   Updated: 2022/08/31 16:49:03 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

int		ft_strlen(const char *s);
char	*ft_strljoin(char *s1, char *s2, int s2_len);
int		ft_strchr(char *s, char c);
char	*ft_strdup(char *s1);
char	*char_free(char **line, char **c_line);

#endif
