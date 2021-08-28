NAME := philo

CC := gcc
CFLAGS := -Wall -Wextra -Werror
LIBS := -pthread
INCLUDE := -I includes/

SRCDIR := srcs/
SRCNAME := main.c \
			parse.c \
			ft_atoi.c \
			print_err.c \
			utils.c \


SRCS := $(addprefix $(SRCDIR), $(SRCNAME))
OBJS := $(SRCS:.c=.o)

RM := rm -rf

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDE) $(OBJS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME).dSYM

re: fclean all

test:
		$(CC) -g $(CFLAGS) $(SRCS) $(LIBS) $(INCLUDE) -o $(NAME)

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=666 ./$(NAME) '-30'

.PHONY: all clean fclean re
