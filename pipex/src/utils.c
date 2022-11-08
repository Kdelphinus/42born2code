/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:05:31 by myko              #+#    #+#             */
/*   Updated: 2022/11/08 20:11:03 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	**path_init(void)
{
	char	**paths;

	paths = malloc(sizeof(char *) * 6);
	paths[0] = ft_strdup("/usr/local/bin");
	paths[1] = ft_strdup("/usr/bin");
	paths[2] = ft_strdup("/bin");
	paths[3] = ft_strdup("/usr/sbin");
	paths[4] = ft_strdup("/sbin");
	paths[5] = NULL;
	return (paths);
}

char	**envp_path(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			return (ft_split(envp[i] + 5, ':'));
	}
	return (path_init());
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

void	check_str(char **new_argv)
{
	int	i;

	i = -1;
	while (new_argv[++i])
	{
		if (new_argv[i][0] == '\'' && new_argv[i][ft_strlen(new_argv[i]) - 1] == '\'')
		{
			new_argv[i]++;
			new_argv[i][ft_strlen(new_argv[i]) - 1] = 0;
		}
		else if (new_argv[i][0] == '"' && new_argv[i][ft_strlen(new_argv[i]) - 1] == '"')
		{
			new_argv[i]++;
			new_argv[i][ft_strlen(new_argv[i]) - 1] = 0;
		}
	}
}
