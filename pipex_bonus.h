/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:47:24 by asabbar           #+#    #+#             */
/*   Updated: 2022/01/20 17:44:13 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <fcntl.h>

char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_spilealfa(char *s, char c);
char	*ft_path(char **env, char *cd);
void	ft_free(char **p, int a);
void	ft_fre(char **cmd);
char	**ft_comds(char **av);
void	pipex_bonus(int f1, int f2, char **av, char **env);
int		is2or1(int i);
void	ft_child1(int f1, char **av, char **env, int *end);
void	ft_child3(char *av, char **env, int *end);
void	ft_child4(char *cmd, char **env, int *end);
void	ft_child2(int f2, char *av, char **env);
void	ft_putstr(char	*c);
int		forkpipe(int *end);
int		ft_strncmp(char *str1, char *str2);
char	*ft_strtrim(char *s1, char *set);
int		ft_strlcpy(char *dest, char *src, int size);
char	*ft_strchrr(char *str, int c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strnstr( char *str, char *to_find);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *s);
char	*get_next_line(int fd);
void	waitp(char **cmd, int id);
char	*ft_reade(char **av, char *p);
void	ft_ft(char *p, int *end);
void	ft_child(int a, char **av, char **env, int *end);
void	ft_error(int i, char *p);
#endif