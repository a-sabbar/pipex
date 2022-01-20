/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:08:09 by asabbar           #+#    #+#             */
/*   Updated: 2022/01/20 17:27:20 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_childa(int f1, char **av, char **env, int *end)
{
	char	*pat;
	char	**cmd;

	pat = ft_path(env, av[2]);
	cmd = ft_spilealfa(av[2], ' ');
	dup2(f1, 0);
	close(f1);
	close(end[0]);
	dup2(end[1], 1);
	if (execve(pat, cmd, env) == -1)
	{
		ft_putstr("error in ft_childa\n");
		exit (1);
	}
}

void	ft_childb(int f2, char **av, char **env)
{
	char	*pat;
	char	**cmd;

	pat = ft_path(env, av[3]);
	cmd = ft_spilealfa(av[3], ' ');
	dup2(f2, 1);
	if (execve(pat, cmd, env) == -1)
	{
		ft_putstr("error in ft_childb\n");
		exit (1);
	}
}

static int	test(int *end)
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

void	pipex(int f1, int f2, char **av, char **env)
{
	int		end[2];
	int		id;
	char	**cmds;
	int		i;

	i = -1;
	cmds = ft_comds(av);
	while (cmds[++i])
	{
		id = test(end);
		if (id == 0)
		{
			if (is2or1(i))
				ft_childa(f1, av, env, end);
			else
				ft_childb(f2, av, env);
		}
		else if (id == -1)
			exit(1);
		close(end[1]);
		dup2(end[0], 0);
	}
	waitpid(id, NULL, 0);
	waitpid(id, NULL, 0);
	ft_fre(cmds);
}
