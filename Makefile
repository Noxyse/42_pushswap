# ===== NAMES ===== #

NAME = push_swap
LIBFT_PRINTF = ./printf/libftprintf.a

# ===== COMPILATION ===== #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# ===== DIRECTORIES AND FILES ===== #

SRC_ALGO = ft_simple_algo.c ft_medium_algo.c ft_medium_algo2.c ft_complex_algo.c ft_complex_algo2.c

SRC_HELPERS = stack_manipulation.c stack_manipulation2.c

SRC_RULES = push.c reverse_rotate.c rotate.c swap.c

SRC_MISC = ft_strcmp.c

SRC_MAIN = ft_parse_to_int.c ft_push_swap.c ft_value_to_index.c main.c

SRCS = $(SRC_ALGO) $(SRC_HELPERS) $(SRC_RULES) $(SRC_MISC) $(SRC_MAIN)
OBJS = $(SRCS:.c=.o)
INC = -I. -I./printf/includes -I./printf/libft

# ===== RULES ===== #

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./printf
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PRINTF) -o $(NAME)
	@echo "push_swap compiled successfully!"

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make clean -C ./printf
	$(RM) $(OBJS)
	@echo "push_swap objects deleted"

fclean: clean
	@make fclean -C ./printf
	$(RM) $(NAME)
	@echo "push_swap executable deleted"

re: fclean all

.PHONY: all clean fclean re