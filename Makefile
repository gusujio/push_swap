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

NAME2 = push_swap

SRC = checker.c			checker2.c		stack_a.c		stack_b.c\
	  stack_ab.c        check.c

SRC2 = 3till5.c         5till100.c      push_swap.c\
	  push_swap4.c      tll3.c          stack_a.c\
	  stack_ab.c        stack_b.c       checker.c\

OBJ = $(patsubst %.c, %.o, $(SRC))

OBJ2 = $(patsubst %.c, %.o, $(SRC2))

all: $(NAME) $(NAME2)

$(NAME):
	make -C ./libft re
	gcc -o $(NAME) $(SRC) -L ./libft -lft

$(NAME2):
	make -C ./libft re
	gcc -o $(NAME2) $(SRC2) -L ./libft -lft

clean:
	make -C ./libft fclean
	/bin/rm -f $(OBJ) $(OBJ2)

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME) $(NAME2)

re: fclean all
