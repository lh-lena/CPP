NAME	= a.out

SRC	= main.c Animal.cpp Cat.cpp Dog.cpp 
OBJ	= ${SRC:.cpp=.0}

CPP	= c++

FLAGS = -Wall -Wextra -Werror -std=c++98

RM	= rm -f

all:	 ${NAME}

${NAME}:	${OBJ}
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(FLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

