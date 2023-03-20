#include "minishell.h"

char	**path_init(t_envp *tenvp)
{
	char	**paths;

	paths = malloc(sizeof(char *) * 6);
	if (!paths)
		error(MALLOC_ERROR, "malloc", tenvp);
	paths[0] = ft_strdup("/usr/local/bin");
	paths[1] = ft_strdup("/usr/bin");
	paths[2] = ft_strdup("/bin");
	paths[3] = ft_strdup("/usr/sbin");
	paths[4] = ft_strdup("/sbin");
	paths[5] = NULL;
	return (paths);
}

char	*ft_path(char *filename, char **path)
{
	int		i;
	char	*tmp;

	i = -1;
	while (path[++i])
	{
		if (path[i][ft_strlen(path[i]) - 1] != '/')
			tmp = ft_strjoin(path[i], "/");
		else
			tmp = ft_strdup(path[i]);
		tmp = ft_strjoin(tmp, filename);
		if (access(tmp, F_OK) == 0)
			return (tmp);
	}
	if (access(filename, F_OK) == 0 && ft_strchr(filename, '/'))
		return (filename);
	return (NULL);
}

void	check_str(int flag, char **new_argv)
{
	int		i;
	char	**tmp;

	i = -1;
	while (new_argv[++i])
	{
		if ((new_argv[i][0] == '\'' \
			&& new_argv[i][ft_strlen(new_argv[i]) - 1] == '\'') \
			|| (new_argv[i][0] == '"' \
			&& new_argv[i][ft_strlen(new_argv[i]) - 1] == '"'))
		{
			new_argv[i]++;
			new_argv[i][ft_strlen(new_argv[i]) - 1] = 0;
		}
	}
	if (flag)
	{
		tmp = ft_split(new_argv[1], '\\');
		i = -1;
		new_argv[1] = ft_strdup("");
		while (tmp[++i])
			new_argv[1] = ft_strjoin(new_argv[1], tmp[i]);
	}
}
