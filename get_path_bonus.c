/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:54:37 by asabbar           #+#    #+#             */
/*   Updated: 2022/01/20 12:54:55 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*get_path(char **str)
{
	int		i;
	int		j;
	int		x;
	char	*to_find;

	i = 0;
	j = 0;
	to_find = "PATH";
	while (str[i])
	{
		j = 0;
		x = 0;
		while (str[i][j] == to_find[x] && str[i][j] != '=')
		{
			if (str[i][j + 1] == '=')
				return (&str[i][j + 2]);
			x++;
			j++;
		}
		i++;
	}
	exit(0);
}

void	ft_fre(char **cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
}

char	*ft_path(char **env, char *cd)
{
	int		i;
	char	*str;
	char	*str2;
	char	**p;
	char	**cmd;

	str = get_path(env);
	p = ft_split(str, ':');
	cmd = ft_spilealfa(cd, ' ');
	i = -1;
	while (p[++i])
	{
		str2 = ft_strjoin(p[i], cmd[0]);
		if (access(str2, X_OK) == 0)
		{
			ft_fre(cmd);
			return (str2);
		}
		free(str2);
	}
	ft_putstr("error --> command not found: ");
	ft_putstr(cmd[0]);
	ft_putstr("\n");
	ft_fre(cmd);
	exit(1);
}
