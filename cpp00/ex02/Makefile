NAME	= account
SRC		= Account.cpp tests.cpp
OBJ		= ${SRC:.cpp=.o}

CPP		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -f

all:		$(NAME)
$(NAME):	$(OBJ)
		$(CPP) $(FLAGS) $(SRC) -o $(NAME)

%.o: %.cpp
	$(CPP) $(FLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
