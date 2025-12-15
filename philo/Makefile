NAME = philo
NAME_BONUS = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread
RM = rm -rf
SRCS = main.c inicialiation.c utils.c
BONUS_SRCS = 
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} 

all: $(NAME)

$(NAME):$(OBJS)
	@echo "Compiling philo..."
	@$(CC) $(CFLAGS) $(OBJS)-o $(NAME)

bonus:$(BONUS_OBJS)
	@echo "Compiling bonus philo..."
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)

clean:
	@echo "🗑️ Removing objs"
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@echo "🗑️ Removing $(NAME)"
	@$(RM) $(NAME) $(NAME_BONUS) $(BONUS_OBJS)

re: fclean all

.PHONY: all clean fclean re bonus
