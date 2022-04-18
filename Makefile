NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEAD_FILE = philo/philo.h

SRCS =	philo/main.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c $(HEAD_FILE) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re