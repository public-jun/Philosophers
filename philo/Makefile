NAME := philo

CC := gcc
CFLAGS := -Wall -Wextra -Werror
LIBS := -pthread
INCLUDE := -I includes/

SRCDIR := srcs/
SRCNAME := main.c \
			free_all.c \
			ft_atoi.c \
			ft_err.c \
			init_args.c \
			philo_init_eat.c \
			philo_init_man.c \
			philo_init_fork.c \
			philo_lunch.c \
			philo_utils.c \
			time.c \
			utils.c \

SRCS := $(addprefix $(SRCDIR), $(SRCNAME))
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)

RM := rm -rf

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -MMD -MP -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDE) $(OBJS) -o $@

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME) $(NAME).dSYM

re: fclean all

test:
	$(CC) -g $(CFLAGS) $(SRCS) $(LIBS) $(INCLUDE) -o $(NAME)

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=666 ./$(NAME) 3 300 100 100

.PHONY: all clean fclean re test valgrind
