NAME	= a.out
SRC		= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJ		= ${SRC:.cpp=.o}

CPP		= c++
FLAGS	= -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98

RM		= rm -f

all:		$(NAME)
$(NAME):	$(OBJ)
		$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(FLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
