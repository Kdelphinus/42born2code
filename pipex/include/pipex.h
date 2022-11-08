/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:06:02 by myko              #+#    #+#             */
/*   Updated: 2022/11/08 21:32:50 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <sys/wait.h>

typedef enum s_erroridx {
	ARGC_ERROR = 0,
	COMMAND_ERROR = 1,
	ERROR = 2,
	PERMISSION_ERROR = 3,
	EXIT_COMMAND_ERROR = 127,
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
int		error(int errnum, char *problem);

// pipe_pid.c
void	child_pid(int fds[], t_envp envp);
void	parent_pid(int fds[], t_envp tenvp);

//utils.c
char	**envp_path(char **envp);
char	*ft_path(char *filename, char **path_option);
void	check_str(int flag, char **new_argv);

//ft_split_set.c
char	**ft_split_set(char *str, char *charset);

#endif
