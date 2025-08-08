NAME		= get_next_line.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE)

BUFFER_SIZE ?= 32

SRC			= get_next_line.c get_next_line_utils.c
OBJ			= $(SRC:.c=.o)

HEADER		= get_next_line.h

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re