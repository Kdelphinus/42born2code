/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:06:02 by myko              #+#    #+#             */
/*   Updated: 2022/10/19 19:18:34 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

extern char	**environ;

# include "../lib/includes/libft.h"
# include <errno.h> // errno
# include <stdio.h> // perror
# include <string.h> // strerror
# include <unistd.h> // fork, waitpid, execve, dup, dup2, pipe
# include <stdlib.h> // exit

# define SUCCESS 0
# define FAIL	1

#endif