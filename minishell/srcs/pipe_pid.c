#include "minishell.h"

static char	**exception2(int i, t_envp tenvp)
{
	char	**new_argv;

	new_argv = (char **)malloc(sizeof(char *) * 3);
	if (!new_argv)
		error(MALLOC_ERROR, "malloc");
	new_argv[0] = ft_strdup("/bin/bash");
	new_argv[1] = ft_strdup(tenvp.argv[i] + 2);
	new_argv[1] = ft_strtrim(new_argv[1], " 	");
	new_argv[2] = NULL;
	if (access(new_argv[1], X_OK) == -1 \
		&& access(new_argv[1], F_OK) == 0)
		error(PERMISSION_ERROR, new_argv[1]);
	check_str(1, new_argv);
	return (new_argv);
}

static char	**exception(int i, t_envp tenvp, char *cmd)
{
	char	**new_argv;

	new_argv = (char **)malloc(sizeof(char *) * 3);
	if (!new_argv)
		error(MALLOC_ERROR, "malloc");
	new_argv[0] = ft_strdup(cmd);
	new_argv[1] = ft_strdup(tenvp.argv[i] + ft_strlen(cmd));
	new_argv[1] = ft_strtrim(new_argv[1], " 	");
	new_argv[2] = NULL;
	check_str(1, new_argv);
	return (new_argv);
}

static char	**argv_init(int i, t_envp tenvp)
{
	char	**new_argv;

	if (ft_strncmp(tenvp.argv[i], "awk", 3) == 0)
		new_argv = exception(i, tenvp, "awk");
	else if (ft_strncmp(tenvp.argv[i], "sed", 3) == 0)
		new_argv = exception(i, tenvp, "sed");
	else if (ft_strncmp(tenvp.argv[i], "./", 2) == 0)
		new_argv = exception2(i, tenvp);
	else
	{
		new_argv = ft_split_set(tenvp.argv[i], " 	");
		check_str(0, new_argv);
	}
	return (new_argv);
}

void	work_pid(int argc, t_envp tenvp)
{
	char	*path;
	char	**new_argv;

	new_argv = argv_init(argc, tenvp);
	if (!new_argv)
		error(MALLOC_ERROR, "malloc");
	path = ft_path(new_argv[0], tenvp.paths);
	if (!path)
		error(COMMAND_ERROR, new_argv[0]);
	if (execve(path, new_argv, tenvp.envp) == -1)
		error(RUN_ERROR, new_argv[0]);
}

