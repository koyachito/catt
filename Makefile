NAME = catt

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDLIBS = -lncurses

PREFIX = /usr/local
BINDIR = $(PREFIX)/bin

SRCS = catt.c
OBJS = $(SRCS:.c=.o)
HEADERS = catt.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDLIBS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

install: $(NAME)
	install -d $(BINDIR)
	install -m 755 $(NAME) $(BINDIR)/$(NAME)

uninstall:
	rm -f $(BINDIR)/$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all install uninstall clean fclean re
