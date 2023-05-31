# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 14:55:10 by yuboktae          #+#    #+#              #
#    Updated: 2023/05/31 14:39:43 by yuboktae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

SRC_DIR	=	src/
OBJ_DIR	=	obj/


SRC_FILES	=	main.c \
				check_args.c \
				init_img.c \
				init_params.c \
				utils.c \
				mlx_utils.c \
				key_events.c \
				mouse_events.c \
				palette.c \
				julia.c \
				julia_set.c \
				mandelbrot.c \
				tricorn.c \
				free_win.c \
				

SRC				=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g3

all:	$(NAME)

$(NAME): $(OBJ)
	@echo "$(BGreen)******* Fractol: Compilation complete! *******$(BEnd)"
	$(CC) $(OBJ) $(CFLAGS) -Lminilibx-linux -lmlx_Linux \
	-Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -Iminilibx-linux -MMD -MP -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR) 

fclean: clean
	rm -f $(NAME)
	@echo "$(BBlue)******* Cleanup complete! *******$(BEnd)"

re: fclean all

.PHONY: all clean fclean re

BGreen=\033[1;32m
BBlue=\033[1;34m
BEnd=\033[1m