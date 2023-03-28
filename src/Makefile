# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 01:47:32 by hrahovha          #+#    #+#              #
#    Updated: 2023/03/19 17:46:05 by hrahovha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libsrc.a

SRC =	check.c				\
		check2.c			\
		ft_error_print.c	\
		win.c				\
		map.c				\
		walls.c				\
		player_move.c		\
		empty.c				\
		move_r.c			\
		move_l.c			\
		move_u.c 			\
		move_d.c 			\
		anim.c				\
		door.c				\
		sound.c 			\
		girl.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

$(OBJ): $(SRC)
	@gcc $(FLAGS) -c $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
