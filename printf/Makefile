# ===== VARIABLE ===== #

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
RM = rm -f
AR = ar rcs

# ===== DIRECTORY AND FILES ===== #

SRC_DIR = srcs/
INC_DIR = includes/

SRCS = $(SRC_DIR)ft_printf.c $(SRC_DIR)ft_check_txt.c $(SRC_DIR)ft_check_baset.c $(SRC_DIR)ft_check_hex.c
OBJS = $(SRCS:.c=.o)
INC = -I $(INC_DIR) -I $(LIBFT_PATH)

# ===== LIB CREATION ===== #

bonus: all

all: $(NAME)

main: $(NAME)
	$(CC) $(CFLAGS) $(INC) main.c $(NAME) -o run

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH)
	@echo "libft compiled"
	@cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	@echo "libftprintf compiled"

# ===== CLEANER ===== #

clean:
	@make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)
	@echo "Object files deleted"

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)
	rm -f run
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re