#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		materias[i] = NULL;
	std::cout << "Default MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	for (int i = 0; i < 4; ++i) {
		if (src.materias[i])
			materias[i] = src.materias[i]->clone();
		else
			materias[i] = NULL;
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;

}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i) {
		if (materias[i])
			delete materias[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (materias[i])
				delete materias[i];
			if (rhs.materias[i])
				materias[i] = rhs.materias[i]->clone();
			else
				materias[i] = NULL;
		}
		std::cout << "MateriaSource copy assignment operator called" << std::endl;
	}
	return (*this);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

// void	MateriaSource::learnMateria(AMateria*)
// {
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (!materias[i])
// 		{
// 			materias[i] = ;
// 			break ;
// 		}
// 	}
// }

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i) {
		if (materias[i] && materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return 0;

}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/*
** ----------------------------------- NOTES ----------------------------------
*/
/**
 * • learnMateria(AMateria*)
Copies the Materia passed as a parameter and store it in memory so it can be cloned
later. Like the Character, the MateriaSource can know at most 4 Materias. They
are not necessarily unique.
• createMateria(std::string const &)
Returns a new Materia. The latter is a copy of the Materia previously learned by
the MateriaSource whose type equals the one passed as parameter. Returns 0 if
the type is unknown.
In a nutshell, your MateriaSource must be able to learn "templates" of Materias to
create them when needed. Then, you will be able to generate a new Materia using just
a string that identifies its type.
*/


/* ************************************************************************** */