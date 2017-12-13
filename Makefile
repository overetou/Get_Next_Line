# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 17:05:18 by fchevrey          #+#    #+#              #
#    Updated: 2017/12/07 16:18:58 by overetou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_gnl

LIB = libft.a

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(LIB)
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

$(LIB):
	make -C libft/

clean:
	make -C libft/	fclean

fclean: clean
	rm -f $(NAME)

cleanall:
	rm libft/*.o
	rm libft/$(LIB)

re: fclean all
