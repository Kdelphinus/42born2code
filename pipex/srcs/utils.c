/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:05:31 by myko              #+#    #+#             */
/*   Updated: 2022/10/26 14:06:02 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	all_free(char ***tmp)
{
	int	i;

	i = -1;
	while (*tmp[++i])
		free(*tmp[i]);
	free(*tmp);
}

char	*ft_path(char *filename, char **envp)
{
	int		i;
	char	*tmp;
	char	**path_option;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			break ;
	}
	path_option = ft_split(envp[i] + 5, ':');
	i = -1;
	while (path_option[++i])
	{
		if (path_option[i][ft_strlen(path_option[i]) - 1] != '/')
			tmp = ft_strjoin(path_option[i], "/");
		tmp = ft_strjoin(tmp, filename);
		if (access(tmp, F_OK) == 0)
			return (tmp);
		free(tmp);
	}
	all_free(&path_option);
	return (NULL);
}
