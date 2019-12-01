# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 23:24:55 by jfelty            #+#    #+#              #
#    Updated: 2019/11/30 23:03:37 by jfelty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -framework OpenGL -framework AppKit

MLXLIB = minilibx_macos/libmlx.a

LIBFT = sources/libft/libft.a

SRC =	sources/fractol.c \
		sources/key_hooks.c \
		sources/key_hooks_help.c \
		sources/frac_math.c \
		sources/frac_load.c

all: $(NAME)

$(NAME): lib mlx out clean

mlx:
	@make -C minilibx_macos

lib:
	@make -C sources/libft
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
	@make -C sources/libft/ clean

fclean: clean
	@rm -f fractol
	@make -C sources/libft/ fclean
	@make -C minilibx_macos/ clean

re: fclean all

.PHONY: lib out clean all fclean re fractol mlx