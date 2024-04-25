GREEN = \033[0;32m
BLUE = \033[0;34m
CYAN = \033[0;36m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
NC = \033[0m

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread -g3 
# -fsanitize=thread -g

NAME = philo

SRCS = eat.c \
		errors.c \
		free.c \
		getter_setter.c \
		init.c \
		main.c \
		parse.c \
		routine.c \
		routine_utils.c \
		supervise.c \
		think.c \
		utils.c \
		ft_sleep.c

OBJS = $(SRCS:.c=.o)

HEADER = philo.h

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)		*----------------------------------*\n \
			|        [OK] $(NAME) created        |\n \
			*----------------------------------*$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "$(PURPLE)[OK]$(NC) philo clean completed"

fclean: clean
	rm -f $(NAME)
	@echo "$(PURPLE)[OK]$(NC) philo fclean completed"

re: fclean all

.PHONY: all clean fclean re