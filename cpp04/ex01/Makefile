NAME	= a.out

SRC	= 	main.cpp \
		Animal.cpp \
		Cat.cpp \
		Brain.cpp \
		Dog.cpp \
		WrongCat.cpp \
		WrongAnimal.cpp \


OBJ	= ${SRC:.cpp=.o}

CPP	= c++

FLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98 #-g -fsanitize=address

RM	= rm -f

all:	 ${NAME}

%.o: %.cpp
	$(CPP) $(FLAGS) -c -o $@ $<

${NAME}:	${OBJ}
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

