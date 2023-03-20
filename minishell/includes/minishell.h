#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
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

# define READ_END 0
# define WRITE_END 1

typedef enum s_erroridx {
	ARGC_ERROR,
	PIPE_ERROR,
	FORK_ERROR,
	MALLOC_ERROR,
	COMMAND_ERROR,
	RUN_ERROR,
	PERMISSION_ERROR,
	EXIT_PERMOSSION_ERROR = 126,
	EXIT_COMMAND_ERROR = 127,
}	t_erroridx;

typedef struct s_envp{
	int		argc;
	char	**argv;
	char	**paths;
	char	**envp;
}			t_envp;

// envp_init.c
void	envp_init(t_envp *tenvp, char **envp);

// run_cmd.c
void	run_cmd(char *str, t_envp tenvp);

// pipe_run.c
int		pipex(char *str, t_envp tenvp);

// pipe_pid.c
char	**exception2(int i, t_envp tenvp);
char	**exception(int i, t_envp tenvp, char *cmd);
char	**argv_init(int i, t_envp tenvp);
void	work_pid(int argc, t_envp tenvp);

// pipe_error.c
int		error(int errnum, char *problem);

// pipe_utils.c
char	**path_init(void);
char	*ft_path(char *filename, char **path_option);
void	check_str(int flag, char **new_argv);

// pipe_split_set.c
char	**ft_split_set(char *str, char *charset);

#endif
