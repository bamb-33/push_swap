# compile:
# 	cc -I /usr/local/include main.c -L /usr/local/bin/  -lmlx -framework OpenGL -framework AppKit && ./a.out

CC = cc
CFLAGS = #-Wall -Wextra -Werror

SRC = main.c a_functions.c b_functions.c functions.c big_stack.c move.c small_stack.c
OBJ = $(SRC:.c=.o)
NAME = push_swap.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	cc main.c libft/libft.a push_swap.a -o push_swap
# && ./push_swap 2 1 3

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	$(MAKE) -C libft

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re