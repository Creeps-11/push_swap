SOURCES = 	push_swap.c\
			parsing.c\
			stack_utils.c\
			struct_utils.c\
			operations.c\
			sorting.c\
			in_n_out.c
HEADERS = push_swap.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = $(SOURCES:.c=.o)
NAME = push_swap
LIBFT = libft/libft.a

%.o: %.c $(HEADERS)
	$(CC) -o $@ -c $< $(CFLAGS)

all: $(NAME)

$(NAME) : $(OBJECTS)
	(cd libft ; make)
	cc $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

libclean:
	(cd libft ; make clean)

libexclean:
	(cd libft ; make fclean)

clean: libclean
	rm -rf $(OBJECTS)

fclean: clean libexclean
	rm -f $(NAME)

re: fclean all