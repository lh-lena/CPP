NAME	= PmergeMe

SRC	= main.cpp PmergeMe.cpp
OBJ	= ${SRC:.cpp=.o}

CPP	= c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -O3

RM	= rm -f

all:	 ${NAME}

${NAME}:	${OBJ}
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp PmergeMe.hpp Makefile
	$(CPP) $(FLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
