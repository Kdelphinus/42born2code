/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:05:31 by myko              #+#    #+#             */
/*   Updated: 2022/11/03 21:14:12 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// TODO 우선 그냥 바로 할당
static char	**path_init(void)
{
	char	**paths;

	paths = malloc(sizeof(char *) * 6);
	paths[0] = "/usr/local/bin";
	paths[1] = "/usr/bin";
	paths[2] = "/bin";
	paths[3] = "/usr/sbin";
	paths[4] = "/sbin";
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
	if (access(filename, F_OK) == 0)
		return (filename);
	return (NULL);
}
