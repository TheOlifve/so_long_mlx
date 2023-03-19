# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 16:30:24 by hrahovha          #+#    #+#              #
#    Updated: 2023/03/19 18:36:15 by hrahovha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c

U_DIR = utils/
U_C = utils/*.c
S_DIR = src/
S_C = src/*.c
MLX = minilibx

LMLX = -L./$(MLX) -lmlx -framework OpenGL -framework AppKit 

OBJ = $(SRC:.c=.o)

all : mlx $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX)
	$(MAKE) all -C $(U_DIR)
	$(MAKE) all -C $(S_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LMLX) -L./utils -lutils -L./src -lsrc

mlx:
	$(MAKE) -C $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	$(MAKE) fclean -C $(U_DIR) 
	$(MAKE) fclean -C $(S_DIR)
	rm -rf $(NAME)

clean:
	$(MAKE) clean -C $(MLX)
	$(MAKE) clean -C $(U_DIR) 
	$(MAKE) clean -C $(S_DIR)
	rm -rf $(OBJ)

re: fclean all
	$(MAKE) re -C $(MLX)

.PHONY: mlx all clean fclean re

