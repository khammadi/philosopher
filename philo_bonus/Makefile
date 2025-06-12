NAME = philo_bonus
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g3
src = main_bonus.c utils_bonus.c utils2_bonus.c
OBJS = $(src:.c=.o)
CC=clang
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean : 
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
#MAKEFLAGS += --silent