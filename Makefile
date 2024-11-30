SRCS = get_next_line.c get_next_line_utils.c
CC = CC
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

NAME = libget_next_line.a

all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONEY: clean
