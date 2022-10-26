/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:05:31 by myko              #+#    #+#             */
/*   Updated: 2022/10/26 15:20:23 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// void	all_free(char ***tmp)
// {
// 	int	i;

// 	i = -1;
// 	while (*tmp[++i])
// 		free(*tmp[i]);
// 	free(*tmp);
// }

char	**envp_path(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			return (ft_split(envp[i] + 5, ':'));
	}
	return (NULL);
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
		tmp = ft_strjoin(tmp, filename);
		if (access(tmp, F_OK) == 0)
			return (tmp);
		// free(tmp);
	}
	// all_free(&path);
	return (NULL);
}
