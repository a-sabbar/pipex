/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:56:27 by asabbar           #+#    #+#             */
/*   Updated: 2022/01/20 17:44:02 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_putstr(char	*c)
{
	int		i;

	i = 0;
	while (c[i] != '\0')
	{
		write(2, &c[i], 1);
		i++;
	}
}

void	ft_child1(int f1, char **av, char **env, int *end)
{
	char	*pat;
	char	**cmds;

	pat = ft_path(env, av[2]);
	cmds = ft_spilealfa(av[2], ' ');
	dup2(f1, 0);
	close(f1);
	close(end[0]);
	dup2(end[1], 1);
	if (execve(pat, cmds, env) == -1)
	{
		ft_putstr("error in ft_child1\n");
		exit (1);
	}
}

void	ft_child3(char *cmd, char **env, int *end)
{
	char	*pat;
	char	**cmds;

	pat = ft_path(env, cmd);
	if (cmd[0] != ' ')
		cmds = ft_spilealfa(cmd, ' ');
	close(end[0]);
	dup2(end[1], 1);
	if (execve(pat, cmds, env) == -1)
	{
		ft_putstr("error in ft_child3\n");
		exit (1);
	}
}

void	ft_child2(int f2, char *av, char **env)
{
	char	*pat;
	char	**cmd;

	pat = ft_path(env, av);
	cmd = ft_spilealfa(av, ' ');
	dup2(f2, 1);
	if (execve(pat, cmd, env) == -1)
	{
		ft_putstr("error in ft_child2\n");
		exit (1);
	}
}

void	ft_error(int i, char *p)
{
	if (i == -1)
	{
		ft_putstr(p);
	}
	exit(1);
}
