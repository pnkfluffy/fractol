# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 23:24:55 by jfelty            #+#    #+#              #
#    Updated: 2019/11/26 18:06:53 by jfelty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -framework OpenGL -framework AppKit

MLXLIB = minilibx_macos/libmlx.a

LIBFT = libft/libft.a

SRC =	fractol.c \
		key_hooks.c \
		key_hooks_help.c \
		frac_math.c \
		frac_load.c

all: $(NAME)

$(NAME): lib mlx out clean

mlx:
	@make -C minilibx_macos

lib:
	@make -C libft
	@echo "libft complete"
#uses make command in library

out:
	@$(CC) $(CFLAGS) $(SRC) $(MLXLIB) $(LIBFT) $(MLXFLAGS) -o fractol
	@echo "Fractol Generation Complete"

test:
	@$(CC) $(CFLAGS) $(SRC) $(MLXLIB) $(LIBFT) -g $(MLXFLAGS) -o fractol
	@echo "Test Generation Complete"

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f fractol
	@make -C libft/ fclean
	@make -C minilibx_macos/ clean

re: fclean all

.PHONY: lib out clean all fclean re fractol mlx