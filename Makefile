NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I .

SRC =	main.c \
		parsing/parse_args.c \
		parsing/check_errors.c \
		instructions/push.c \
		instructions/rotate.c \
		instructions/reverse_rotate.c\
		instructions/swap.c \
		sort/sort_small.c \
		sort/complex_sort.c \
		utils/stack_utils.c \
		utils/ft_atoi.c \
		utils/ft_isdigit.c \
		utils/ft_strlen.c \
		utils/ft_split.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
