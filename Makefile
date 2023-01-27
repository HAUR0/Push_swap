


NAME = push_swap
SRC = push_swap.c \
	op_1.c \
	op_2.c \
	op_3.c \
	
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

fclean: clean
	@$(MAKE) fclean -C ./libft 
#deleting pushswap .o files fehlt noch

re: fclean all
	@echo "DELETED AND RECOMPILED"
	
#running-stuff////////////////////////////////

run: all
	./push_swap

5: all
	./push_swap "1 4 6 3 123"
