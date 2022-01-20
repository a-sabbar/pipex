/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:53:36 by asabbar           #+#    #+#             */
/*   Updated: 2022/01/20 17:19:32 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_check(char **av, char **env)
{
	int	i;
	int	f1;
	int	f2;

	if (ft_strncmp(av[1], "here_doc") != 0)
	{
		i = 0;
		while (av[i])
			i++;
		f1 = open(av[1], O_RDONLY, 0777);
		if (f1 == -1)
		{
			ft_putstr("file error\n");
			exit(1);
		}
		f2 = open(av[--i], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	}
	else
	{
		f1 = 0;
		f2 = 0;
	}
	pipex_bonus(f1, f2, av, env);
}

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
	{
		ft_putstr("The program takes 4 arguments or more\n");
		exit(1);
	}
	if (ft_strncmp(av[1], "here_doc") == 0 && ac != 6)
	{
		ft_putstr("Here Doc takes 5 arguments \nNo more, No less\n");
		exit(1);
	}
	ft_check(av, env);
	return (0);
}
