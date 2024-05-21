#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	for (int i = 0; i < 100; i++) {
        ideas[i] = "Default Idea";
    }
	std::cout << "Default Brain constructor called" << std::endl; 
}

Brain::Brain( const Brain & src )
{
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = src.ideas[i];
	}
    std::cout << "Brain copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = rhs.ideas[i];
		}
        std::cout << "Brain copy assignment operator called" << std::endl;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Brain const & i )
{
	for (int n = 0; n < 100; n++) {
		o << i.getIdea(n) << std::endl;
	}
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Brain::setIdea(int index, const std::string & idea)
{
	if (index >= 0 && index < 100)
	{
		this->ideas[index] = idea;
	}
}

std::string		Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	else
		return ("");
}

/* ************************************************************************** */