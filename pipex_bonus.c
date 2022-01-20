/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:55:09 by asabbar           #+#    #+#             */
/*   Updated: 2022/01/20 02:21:37 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_cheak(int i, char **cmd)
{
	if (!is2or1(i))
	{
		if (!cmd[i + 1])
			return (2);
		else
			return (3);
	}
	else if (is2or1(i))
	{
		if (!cmd[i + 1])
			return (2);
		else
			return (3);
	}
	return (0);
}

int	forkpipe(int *end)
{
	int	id;

	pipe(end);
	if (pipe(end) == -1)
	{
		ft_putstr("error pipe\n");
		return (-1);
	}
	id = fork();
	if (id == -1)
	{
		ft_putstr("error fork\n");
		return (-1);
	}
	return (id);
}

void	bonus1(int f1, int f2, char **av, char **env)
{
	int		end[2];
	int		id;
	int		i;
	char	**cmd;

	cmd = ft_comds(av);
	i = -1;
	while (cmd[++i])
	{
		id = forkpipe(end);
		if (id == -1)
			exit(1);
		else if (id == 0)
		{
			if (i == 0)
				ft_child1(f1, av, env, end);
			else if (ft_cheak(i, cmd) == 2)
				ft_child2(f2, cmd[i], env);
			else if (ft_cheak(i, cmd) == 3)
				ft_child3(cmd[i], env, end);
		}
		close(end[1]);
		dup2(end[0], 0);
	}
	waitp(cmd, id);
}

void	ft_exeve(int a, char **env, char **av, char *p)
{
	int		id;
	int		end[2];

	while (--a)
	{
		id = forkpipe(end);
		if (id == -1)
			break ;
		else if (id == 0)
		{
			if (a == 3)
				ft_ft(p, end);
			else
				ft_child(a, av, env, end);
		}
		close(end[1]);
		dup2(end[0], 0);
	}
	a = -1;
	while (++a < 3)
		waitpid(id, NULL, 0);
}

void	pipex_bonus(int f1, int f2, char **av, char **env)
{
	char	*p;
	int		a;

	if (ft_strncmp(av[1], "here_doc") == 0)
	{
		p = malloc(1);
		p[0] = '\0';
		p = ft_reade(av, p);
		a = 4;
		ft_exeve(a, env, av, p);
		free(p);
	}
	else
		bonus1(f1, f2, av, env);
}
