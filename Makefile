##
## EPITECH PROJECT, 2021
## Autocompletion
## File description:
## Makefile
##

CC	=	g++

NAME	=	autoCompletion

SRCS	=	src/main.cpp 	\
			src/help.cpp  	\
			src/parser.cpp 	\
			src/tools.cpp	\
			src/check.cpp	\

OBJS	=	$(SRCS:.cpp=.o)

CFLAGS += -Wall -Wextra -g3

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re