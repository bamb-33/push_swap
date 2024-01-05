# compile:
# 	cc -I /usr/local/include main.c -L /usr/local/bin/  -lmlx -framework OpenGL -framework AppKit && ./a.out

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = mandatory/main.c mandatory/functions_a.c mandatory/functions_b.c mandatory/stack_len.c \
		mandatory/algorithme.c mandatory/move.c mandatory/sort.c mandatory/free.c mandatory/error.c \

SRC_B = bonus/main_bonus.c bonus/ft_call_bonus.c bonus/functions_a_bonus.c \
		 bonus/functions_b_bonus.c bonus/is_sorted.c

OBJ = $(SRC:.c=.o)
OBJ_b = $(SRC_b:.c=.o)
NAME = push_swap.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	cc mandatory/main.c libft/libft.a push_swap.a -o push_swap
# && ./push_swap 2 1 3

bonus: 	$(OBJ_B)

$(OBJ_B): $(SRC_B)
	@echo here
	$(CC) $(CFLAGS) -c $^ 
	ar rcs $(NAME) $(OBJ_B)
	cc bonus/main_bonus.c libft/libft.a push_swap.a -o push_swap

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	$(MAKE) -C libft

clean:
	rm -f $(OBJ) $(OBJ_B)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re