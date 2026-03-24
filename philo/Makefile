NAME ?= philo
NAME_BONUS := philo_bonus

CC := cc

CFLAGS ?= -Wall -Wextra -Werror -g3 -fsanitize=thread
CPPFLAGS := -Iinclude

RM ?= rm -rf

SRCS := main.c init.c utils.c time.c write.c core.c nukem.c monitor.c
BONUS_SRCS :=

SRC_DIR := ./src
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

OBJS := $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) $(BONUS_OBJS)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus
