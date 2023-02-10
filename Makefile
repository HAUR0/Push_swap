# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rloos <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 16:23:43 by rloos             #+#    #+#              #
#    Updated: 2023/02/10 16:23:54 by rloos            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c \
	op_1.c \
	op_2.c \
	op_3.c \
	call_sorting.c \
	2_numbers.c \
	3_numbers.c \
	4_numbers.c \
	5_numbers.c \
	6_numbers_up.c \
	ps_utils_1.c \
	ps_utils_2.c \
	ps_utils_3.c \
	
OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -rf

#/////////////////////////////////////////////

.PHONY: all clean fclean re

all:	${NAME}

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJ) $(LIBFT)
	@echo "👺 DONE"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

#cleaning-stuff////////////////////////////////

clean: 
	@$(MAKE) clean -C ./libft
	@$(RM) ./push_swap

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(OBJ)

re: fclean all
	@echo "DELETED AND RECOMPILED"
	
#/////////////////////////////////////////////


1: all 
	@echo "max Int:"
	./push_swap 2147483648

4: all
	./checker_linux 0 1 2

5: all
	./checker_linux 0 9 1 8 2 7 3 6 4 5

6: all
	./push_swap "1 4 6 3 123"
