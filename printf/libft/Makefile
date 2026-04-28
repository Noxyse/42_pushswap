# ===== VARIABLE ===== #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
RM = rm -f
AR = ar rcs

# ===== PART 1 : LIBC FUNCTIONS ===== #
SRCS_PART1 = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
             ft_isprint.c ft_strlen.c ft_strncmp.c ft_memcmp.c \
             ft_atoi.c ft_tolower.c ft_toupper.c ft_memset.c \
             ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
             ft_calloc.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
             ft_strdup.c ft_strlcpy.c ft_strlcat.c

# ===== PART 2 : ADDITIONAL FUNCTIONS ===== #
SRCS_PART2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
             ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
             ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# ===== PART 3 : LINKED LIST ===== #
SRCS_PART3 = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
             ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
             ft_lstmap.c

# ===== ALL ===== #

SRCS = $(SRCS_PART1) $(SRCS_PART2) $(SRCS_PART3)
OBJS = $(SRCS:.c=.o)

# ===== LIB ===== #

bonus: all

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# ===== CLEANER ===== #

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re