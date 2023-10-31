# Variables
NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Files
SRCS = main.c action.c init.c philo.c time.c utils.c checkers.c 
OBJS = $(SRCS:.c=.o)

# Rules
all: $(NAME)

philo: $(OBJS)
	$(CC) $(CFLAGS) -o philo $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) philo

re: fclean all

.PHONY: all clean fclean re