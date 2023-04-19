#include "minishell.h"

static void	cd_with_path(t_env_node *head, char **path, \
							char **old_path, char **argv)
{
	if (chdir(*path) == -1)
	{
		free_s(*old_path);
		free_s(*path);
		*old_path = ft_strjoin_s("minishell: cd: ", argv[1]);
		if (access(argv[1], F_OK))
			*path = ft_strjoin_s(*old_path, ": No such file or directory\n");
		else
			*path = ft_strjoin_s(*old_path, ": Not a directory\n");
		ft_putstr_fd(*path, STDERR_FILENO);
		g_exit_status = 1;
	}
	else
	{
		if (*old_path != NULL)
			ft_setenv("OLDPWD", ft_strdup_s(*old_path), head);
		else
			ft_setenv("OLDPWD", ft_getenv(head, "PWD"), head);
		ft_setenv("PWD", getcwd(NULL, 0), head);
		g_exit_status = 0;
	}
}

static char	*cd_with_oldpwd(t_env_node *head, char *old_path)
{
	char	*path;

	path = ft_getenv(head, "OLDPWD");
	if (!path)
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", STDERR_FILENO);
		free_s(old_path);
		g_exit_status = 1;
		return (NULL);
	}
	ft_putstr_fd(path, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	return (path);
}

static char	*check_path(t_env_node *head, char **argv, char *old_path)
{
	char	*tmp;
	char	*path;

	if (!argv[1])
		path = ft_getenv(head, "HOME");
	else if (argv[1][0] == '\0')
		path = ft_strdup_s(old_path);
	else if (argv[1][0] == '~')
	{
		tmp = ft_getenv(head, "HOME");
		path = ft_strjoin_s(tmp, argv[1] + 1);
		free_s(tmp);
	}
	else if (ft_strcmp(argv[1], "-") == 0)
		path = cd_with_oldpwd(head, old_path);
	else
		path = ft_strdup_s(argv[1]);
	return (path);
}

void	ft_cd(t_env_node *head, char **argv)
{
	char	*old_path;
	char	*path;

	old_path = getcwd(NULL, 0);
	path = check_path(head, argv, old_path);
	if (!path)
		return ;
	cd_with_path(head, &path, &old_path, argv);
	free_s(old_path);
	free_s(path);
}
