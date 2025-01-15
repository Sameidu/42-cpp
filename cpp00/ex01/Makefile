NAME		=	phonebook
SRC			=	PhoneBook.cpp Contact.cpp main.cpp
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
OBJ			=	$(SRC:.cpp=.o)

$(NAME):	$(OBJ)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re