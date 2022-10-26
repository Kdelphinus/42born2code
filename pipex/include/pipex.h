/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:06:02 by myko              #+#    #+#             */
/*   Updated: 2022/10/26 17:30:55 by myko             ###   ########.fr       */
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

typedef enum s_erroridx {
	ARGC_ERROR = 0,
	PIPE_ERROR = 1,
	FORK_ERROR = 2,
	PATH_ERROR = 3,
	RUN_ERROR = 4
}	t_erroridx;

typedef struct s_envp{
	int		argc;
	char	**argv;
	char	**paths;
	char	**envp;
}			t_envp;

// main.c
int		main(int argc, char **argv, char **envp);

// error.c
int		error(int errnum);

// pipe_pid.c
void	child_pid(int fds2[], t_envp envp);
void	parent_pid(int fds[], int fds2[], t_envp tenvp);

//utils.c
// void	all_free(char ***tmp);
char	**envp_path(char **envp);
char	*ft_path(char *filename, char **path_option);

#endif