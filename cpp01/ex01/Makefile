NAME	=	horde
SRC		=	Zombie.cpp zombieHorde.cpp main.cpp
CPP		=	c++
CPPFLAG	=	-Wall -Wextra -Werror -std=c++98
OBJ		=	$(SRC:.cpp=.o)

$(NAME):	$(OBJ)
	$(CPP) $(CPPFLAG) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re