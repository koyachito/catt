NAME = a.out
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDLIBS = -lncurses

SRCS = catt.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDLIBS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDLIBS)

clean: 
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re
