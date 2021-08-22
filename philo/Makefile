NAME := philo

CC := gcc
CFLAGS := -Wall -Wextra -Werror
LIBS := -pthread
INCLUDE := -I includes/

SRCDIR := srcs/
SRCNAME := main.c \

SRCS := $(addprefix $(SRCDIR), $(SRCNAME))
OBJS := $(SRCS:.c=.o)

RM := rm -f

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDE) $(OBJS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean re

.PHONY: all clean fclean re
