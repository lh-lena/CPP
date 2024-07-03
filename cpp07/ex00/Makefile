NAME	= a.out

SRC	= ex00.cpp
OBJ	= ${SRC:.cpp=.o}

CPP	= c++

FLAGS = -Wall -Wextra -Werror -std=c++98 

RM	= rm -f

all:	 ${NAME}

${NAME}:	${OBJ}
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Makefile
	$(CPP) $(FLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
