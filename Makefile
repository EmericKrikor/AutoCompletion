CC	=	g++

NAME	=	autoCompletion

SRCS	=	src/main.cpp	\
			src/parser.cpp	\
			src/tool.cpp	\
			src/selecter.cpp\
			src/witch_one.cpp\
			src/correct.cpp	\
			src/sort.cpp	\
			src/street.cpp

OBJS	=	$(SRCS:.cpp=.o)

CPPFLAGS	+=	-Wall -Wextra -I./include

G	+= -g3

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CPPFLAGS)

debug:
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(G)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug