# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gusujio <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 14:43:32 by gusujio           #+#    #+#              #
#    Updated: 2019/12/01 17:21:02 by gusujio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRC = checker.c			checker2.c		stack_a.c		stack_b.c\
	  stack_ab.c

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME):
	make -C ./libft re
	gcc -o $(NAME) $(SRC) -L ./libft -lft

clean:
	make -C ./libft fclean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)

re: fclean all
