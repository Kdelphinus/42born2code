#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include "../lib/libft.h"

typedef enum s_erroridx {
	ARGC_ERROR = 0,
	PIPE_ERROR = 1,
	FORK_ERROR = 2,
	FD_ERROR = 3,
	MALLOC_ERROR = 4,
	COMMAND_ERROR = 5,
	RUN_ERROR = 6,
	PERMISSION_ERROR = 7,
	EXIT_PERMOSSION_ERROR = 126,
	EXIT_COMMAND_ERROR = 127,
}	t_erroridx;

typedef struct s_envp{
	int		argc;
	char	**argv;
	char	**paths;
	char	**envp;
}			t_envp;

// pipe_run.c
int		pipex(char *str, char **envp);

// pipe_error.c
int		error(int errnum, char *problem);

// pipe_utils.c
char	**path_init(void);
char	*ft_path(char *filename, char **path_option);
void	check_str(int flag, char **new_argv);

// pipe_split_set.c
char	**ft_split_set(char *str, char *charset);

// pipe_pid.c
void	work_pid(int argc, t_envp tenvp);


#endif