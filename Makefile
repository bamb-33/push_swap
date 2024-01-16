CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = mandatory/main.c mandatory/functions_a.c mandatory/functions_b.c mandatory/stack_len.c \
		mandatory/algorithme.c mandatory/move.c mandatory/sort.c mandatory/free.c mandatory/error.c \
		mandatory/is_sorted.c

SRC_B = bonus/main_bonus.c bonus/ft_call_bonus.c bonus/functions_a_bonus.c \
		 bonus/functions_b_bonus.c  bonus/ss_bonus.c mandatory/free.c mandatory/error.c \
		 mandatory/is_sorted.c mandatory/stack_len.c

SRC_LIBFT = libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_strlen.c \
	   libft/ft_toupper.c libft/ft_tolower.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strncmp.c \
	   libft/ft_strnstr.c libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_atoi.c libft/ft_strdup.c \
	   libft/ft_substr.c libft/ft_strjoin.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c \
	   libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_isprint.c \
	   libft/ft_putnbr_fd.c libft/ft_strtrim.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c \
	   libft/ft_memcmp.c libft/ft_memchr.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_striteri.c \
	   libft/get_next_line_utils.c libft/get_next_line.c

OBJ_LIBFT = $(SRC_LIBFT:.c=.o)
LIBFT = libft/libft.a
NAME = push_swap
BONUS = checker

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJ_LIBFT) $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

$(BONUS): $(OBJ_LIBFT) $(SRC_B)
	$(CC) $(CFLAGS) $(SRC_B) $(LIBFT) -o $(BONUS)

%.o: %.c
	$(MAKE) -C libft

clean:
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re