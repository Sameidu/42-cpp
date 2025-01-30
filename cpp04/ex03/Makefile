NAME		=	materia
SRC			=	main.cpp MateriaSource.cpp AMateria.cpp Character.cpp Ice.cpp Cure.cpp
CXX			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address
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