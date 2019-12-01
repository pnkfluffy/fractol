# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/14 10:38:32 by jfelty            #+#    #+#              #
#    Updated: 2019/11/09 00:26:47 by jfelty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#unnecessary now?

NAME = libftprintf.a

CC =gcc

SRC =	ft_printf.c \
		populate.c \
		dispatch.c \
		print.c \
		format_help.c \
		format_help2.c \
		format_cspf.c \
		format_diouxx.c

OBJ = $(SRC:.c=.o)

OB = ./*.o

FT_LIB = ../libft/libft.a

FT_LIB_OB = ../libft/*.o

all: $(NAME)


$(NAME): $(OBJ) lib 
	ar rc $(NAME) $(OB) $(FT_LIB_OB)
	ranlib $(NAME)

lib:
	make -C src/libft/

test: lib
	$(CC) $(CFLAGS) $(SRC) test.c -g src/libft/libft.a -o test.out

clean:
	rm -rf $(OBJ)
	make -C src/libft/ clean

fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	rm -f test.out
	make -C src/libft/ fclean

re: fclean all

.PHONY: lib out clean all fclean re
