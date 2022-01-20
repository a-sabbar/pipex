/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:40:01 by asabbar           #+#    #+#             */
/*   Updated: 2022/01/20 17:49:51 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strnstr(char *str, char *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		j = 0;
		if (str[(i + j) - 1] == '\n' && str[i + j] == to_find[j])
		{
			while (str[i + j] && str[i + j] == to_find[j])
			{
				if ((str[(i + j) + 1] == '\n' || str[(i + j) + 1] == '\0')
					&& (to_find[j + 1] == '\0'))
					return ("yes");
				j++;
			}
		}
		i++;
	}
	return (0);
}

void	ft_child(int a, char **av, char **env, int *end)
{
	char	*path;
	char	**cmd;
	int		f2;
	int		i;

	if (a == 2)
	{
		path = ft_path(env, av[3]);
		cmd = ft_spilealfa(av[3], ' ');
		close(end[0]);
		dup2(end[1], 1);
		i = execve(path, cmd, env);
		if (i == -1)
			ft_error(i, "error execve 2\n");
	}
	else if (a == 1)
	{
		f2 = open(av[5], O_CREAT | O_WRONLY | O_APPEND, 0777);
		path = ft_path(env, av[4]);
		cmd = ft_spilealfa(av[4], ' ');
		dup2(f2, 1);
		i = execve(path, cmd, env);
		if (i == -1)
			ft_error(i, "error execve 2\n");
	}
}

void	ft_ft(char *p, int *end)
{
	ft_putstr_fd(p, end[1]);
	close(end[1]);
	exit(0);
}

char	*ft_reade(char **av, char *p)
{
	char	*p2;
	char	*p3;

	while (!ft_strnstr(p, av[2]))
	{
		write(1, "pipe heredoc> ", 15);
		p2 = get_next_line(0);
		p3 = ft_strtrim(p2, "\n");
		if (ft_strncmp(p3, av[2]) == 0)
		{
			free(p2);
			free(p3);
			break ;
		}
		p = ft_strjoin(p, p2);
		free(p2);
		free(p3);
	}
	return (p);
}

void	waitp(char **cmd, int id)
{
	int	i;

	i = -1;
	while (cmd[++i])
		waitpid(id, NULL, 0);
	ft_fre(cmd);
}
