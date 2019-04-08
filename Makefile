CC	=	gcc

RM	=	rm -f

NAME	=	maze_generator

CFLAGS	=	-Wall -Wextra

SRCS	=	generator/main.c	\
	 		generator/check.c	\
	 		generator/generator.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
