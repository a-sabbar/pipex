/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:10:18 by asabbar           #+#    #+#             */
/*   Updated: 2022/01/18 22:18:45 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	main(int ac, char **av, char **env)
{
	int	f1;
	int	f2;

	if (ac == 5)
	{
		f1 = open(av[1], O_RDONLY, 07777);
		if (f1 == -1)
		{
			ft_putstr("No infile\n");
			exit(0);
		}
		f2 = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (f2 == -1)
		{
			ft_putstr("error from outfile\n");
			exit(0);
		}
		pipex(f1, f2, av, env);
	}
	else
	{
		ft_putstr("The program takes 4 arguments\nNo more, No less\n");
		exit(0);
	}
	return (0);
}
