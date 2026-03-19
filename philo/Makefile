NAME ?= philo
NAME_BONUS := philo_bonus

CC := cc

CFLAGS ?= -Wall -Wextra -Werror -g3 -fsanitize=thread
CPPFLAGS := -Iinc

RM ?= rm -rf

SRCS := main.c init.c utils.c time.c write.c core.c
BONUS_SRCS :=

SRC_DIR := ./src
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))


OBJS := $(SRCS:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)
BONUS_OBJS := $(BONUS_SRCS:.c=.o)


%.o: %.c
	$(CC) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus:$(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) $(BONUS_OBJS)

re: fclean all

.PHONY: all clean fclean re bonus
