NAME		=	zombie0
SRC			=	Zombie.cpp newZombie.cpp main.cpp randomChump.cpp
CXX			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
OBJ			=	$(SRC:.cpp=.o)

$(NAME):	$(OBJ)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re