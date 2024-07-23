NAME= minitry
CC=cc
CFLAGS= -Wall -Wextra -Werror

SRCS= minitry.c 

OBJS=$(SRCS:.c=.o)

$(NAME) :$(OBJS)
	make -C Libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) Libft/libft.a -lreadline

all : $(NAME)

clean :
	make clean -C Libft
	rm -rf $(OBJS)

fclean : clean
	make fclean -C Libft
	rm -rf  $(NAME)

re: fclean all

.PHONY: all clean fclean re
