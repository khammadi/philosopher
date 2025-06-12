NAME = philo
CFLAGS = -Wall -Wextra -Werror 
src = main.c utils.c utils2.c
CC=clang
OBJS = $(src:.c=.o)
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean : 
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
#MAKEFLAGS += --silent
