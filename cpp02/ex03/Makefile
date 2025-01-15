NAME		=	bsp
SRC			=	main.cpp Fixed.cpp Point.cpp bsp.cpp
CPP			=	c++
CPPFLAGSS	=	-Wall -Wextra -Werror -std=c++98
OBJ			=	$(SRC:.cpp=.o)

$(NAME):	$(OBJ)
	$(CPP) $(CPPFLAGSS) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re