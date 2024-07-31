NAME= minitry
CC=cc
CFLAGS= -Wall -Wextra -Werror

SRCS= src/parsing/minitry.c \
	  src/builtins/cd.c \
	  src/builtins/env.c \
	  src/environment/init_env.c\
	  src/environment/test_env.c \
	  src/execution/exec_command.c \
	  src/execution/exec_prompt.c

OBJS=$(SRCS:.c=.o)

$(NAME) :$(OBJS)
	make bonus -C Libft
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
