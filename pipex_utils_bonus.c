/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:10:38 by asabbar           #+#    #+#             */
/*   Updated: 2022/01/20 17:35:35 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**ft_comds(char **av)
{
	int		i;
	char	*s1;
	char	**s2;

	s1 = (char *)malloc(1 * sizeof(char));
	s1[0] = '\0';
	i = 2;
	while (av[i])
	{
		if (!av[i + 1])
			break ;
		else
		{
			s1 = ft_strjoin(s1, av[i]);
			s1 = ft_strjoin(s1, "\t");
		}
		i++;
	}
	s2 = ft_spilealfa(s1, '\t');
	free(s1);
	return (s2);
}

int	is2or1(int i)
{
	if ((i % 2) == 0)
		return (1);
	else
		return (0);
}
