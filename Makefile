# ===== NAMES ===== #

NAME = push_swap
LIBFT_PRINTF = ./printf/libftprintf.a

# ===== COMPILATION ===== #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# ===== DIRECTORIES AND FILES ===== #

# All your push_swap source files in the root folder
SRCS = ft_medium_algo.c \
       ft_parse_to_int.c \
       ft_push_swap.c \
       ft_simple_algo.c \
       ft_value_to_index.c \
       main.c \
       push.c \
       reverse_rotate.c \
       rotate.c \
       stack_manipulation.c \
       stack_manipulation2.c \
	   ft_strcmp.c \
       swap.c \
	   ft_complex_algo.c

OBJS = $(SRCS:.c=.o)

# Includes: current directory (for push_swap.h) and printf includes
INC = -I. -I./printf/includes -I./printf/libft

# ===== RULES ===== #

all: $(NAME)

# 1. Compile the printf library by calling its Makefile
# 2. Compile push_swap using the library
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