# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 10:17:50 by asabbar           #+#    #+#              #
#    Updated: 2022/01/20 17:07:33 by asabbar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HEADER = pipex.h

HEADERB = pipex_bonus.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	ft_split.c		\
		ft_strjoin.c	\
		ft_spilealfa.c	\
		get_path.c		\
		main.c 			\
		pipex.c 		\
		pipex_utils.c	\

SRCB =	ft_split_bonus.c		\
		ft_strjoin_bonus.c 		\
		get_next_line_bonus.c 	\
		main_bonus.c			\
		ft_spilealfa_bonus.c	\
		get_path_bonus.c		\
		pipex_bonus.c			\
		pipex_utils_bonus.c		\
		utils_bonus.c 			\
		utils2_bonus.c			\
		utils1_bonus.c			\

OBJECTSB = $(SRCB:.c=.o)

ifeq ($(OBJECTS),)
	OBJECTS = $(SRC:.c=.o)
else
	OBJECTSB = $(SRC:.c=.o)
endif

.PHONY: bonus

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER) | wierd_clean
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

bonus: $(OBJECTSB)
	@OBJECTS="$(OBJECTSB)" make

wierd_clean:
	@rm -rf $(OBJECTSB)

clean: wierd_clean
	@rm -rf $(OBJECTS)

fclean: wierd_clean clean
	@rm -rf $(NAME)

re: fclean all