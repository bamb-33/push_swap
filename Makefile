# compile:
# 	cc -I /usr/local/include main.c -L /usr/local/bin/  -lmlx -framework OpenGL -framework AppKit && ./a.out

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = mandatory/main.c mandatory/functions_a.c mandatory/functions_b.c mandatory/stack_len.c \
		mandatory/algorithme.c mandatory/move.c mandatory/sort.c mandatory/free.c mandatory/error.c \

SRC_B = bonus/main.c bonus/ft_call_bonus.c bonus/functions_a_bonus.c \
		 bonus/functions_b_bonus.c bonus/is_sorted_bonus.c bonus/ss.c

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
NAME = push_swap.a
NAME_BONUS = checker.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	cc mandatory/main.c libft/libft.a push_swap.a -o push_swap

$(NAME_BONUS): $(OBJ_B) $(NAME)
	ar -rcs $(NAME_BONUS) $(OBJ_B)
	cc bonus/main.c libft/libft.a push_swap.a checker.a -o checker

bonus: 	$(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	$(MAKE) -C libft

clean:
	rm -f $(OBJ) $(OBJ_B)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re