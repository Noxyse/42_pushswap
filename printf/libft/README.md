*This project has been created as part of the 42 curriculum by celgremy*

# Libft

## Description
The **Libft** project is a foundational assignment at 42 school. It's goal is to create a custom C library containing a collection of standard functions that will be reused in future projects. By recoding these functions, I gained a deeper understanding of memory management, pointer manipulation, and data structures.

### Detailed Library Description
My library is organized into three main categories:

**Standard Libc Functions:**
ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint, ft_strlen, ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_strlcpy, ft_strlcat, ft_toupper, ft_tolower, ft_strchr, ft_strrchr, ft_strncmp, ft_memchr, ft_memcmp, ft_strnstr, ft_atoi, ft_calloc, ft_strdup.

**Additional Functions:**
ft_substr, ft_strjoin, ft_strtrim, ft_split, ft_itoa, ft_strmapi, ft_striteri, ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd.

**Linked Lists:**
ft_lstnew, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back, ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap.

## Instructions

- Compilation:
To compile the library, navigate to the root of the repository and run:
```bash
make
```
The Makefile will automatically use the required flags and compile all the .c files into a static library called libft.a

- Usage:

Since this is a library and not a standalone executable, you need to include it in a C project to use it:

	- Include the header in your code: #include "libft.h"

    - Compile your project by linking the library:
```bash
cc main.c -L. -lft -o run
```

And then run:
```bash
./run
```

- CLeanup:

To remove all the objects files (.o) created during the compilation:
```bash
make clean
```
To remove all object files and the compiled library (libft.a):
```bash
make fclean
```
To re-compile the entire library from scratch:
```bash
make re
```

## Ressources

To complete this project, I mainly use the **peer to peer system**, collaborating with students on campus. I verified the validity of my functions using **Francinette** (in both classic and strict modes).
- AI Usage:
I used AI (Gemini / Claude) to double-check my logic and clarify complex concepts, specifically for:

    - Memory manipulation functions (mem family).

    - Function pointers used in ft_strmapi and ft_striteri.

    - Pointer redirection logic in Linked Lists.