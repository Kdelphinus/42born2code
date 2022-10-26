/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:06:02 by myko              #+#    #+#             */
/*   Updated: 2022/10/26 14:14:48 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../ftprintf/includes/ft_printf.h"
# include <errno.h> // errno
# include <stdio.h> // perror
# include <string.h> // strerror
# include <unistd.h> // fork, waitpid, execve, dup, dup2, pipe
# include <stdlib.h> // exit
# include <fcntl.h> // open, write

// TODO linux
# include <sys/wait.h> // waitpid

typedef enum error_idx {
	ARGC_ERROR = 0,
	PIPE_ERROR = 1,
	FORK_ERROR = 2
}	e_idx;

// main.c
int		main(int argc, char **argv, char **envp);

// error.c
int		error(int i);

// pipe_pid.c
void	child_pid(int fds2[], char **argv, char **envp);
void	parent_pid(int fds[], int fds2[], char **argv, char **envp);

//utils.c
void	all_free(char ***tmp);
char	*ft_path(char *filename, char **envp);


#endif