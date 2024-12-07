SRCS = get_next_line.c get_next_line_utils.c
BSRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
CC = CC
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

NAME = libget_next_line.a

all: $(NAME)

$(NAME): $(OBJS)

bonus : $(BOBJS)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@
clean:
	rm -rf $(OBJS) $(BOBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONEY: clean
