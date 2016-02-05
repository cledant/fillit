# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2015/12/06 11:12:56 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./includes
SRC =	main.c ft_check_hashtag.c ft_check_tetriminos.c ft_cpy_file.c ft_cpy_tab.c \
		ft_init_tab.c ft_list_tetris.c ft_lstcustom_clean.c ft_main_solver.c \
		ft_save_tetris.c ft_solver.c ft_trytetris.c
OBJ =	$(SRC:.c=.o)
LIBFT_PATH = ./Libft
NAME = fillit

all : libft $(NAME)

libft :
	make -C $(LIBFT_PATH)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -lft -L$(LIBFT_PATH) -I$(INCLUDES)

$(OBJ) :
	$(CC) -c $(SRC) $(CFLAGS) -I$(INCLUDES)

clean :
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY : all clean fclean re libft
