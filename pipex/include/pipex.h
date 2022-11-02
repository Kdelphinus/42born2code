/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:06:02 by myko              #+#    #+#             */
/*   Updated: 2022/11/03 02:16:33 by delphinu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../ftprintf/includes/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <sys/wait.h>

typedef enum s_erroridx {
	ARGC_ERROR = 0,
	COMMAND_ERROR = 1,
	ERROR = 2,
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
void	child_pid(int fds2[], t_envp envp);
void	parent_pid(int fds[], int fds2[], t_envp tenvp);
void	check_str(char **new_argv);
char	**exception(int i, t_envp tenvp);

//utils.c
char	**envp_path(char **envp);
char	*ft_path(char *filename, char **path_option);

#endif
