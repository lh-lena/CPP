/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:48:57 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/22 13:15:43 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		_materias[i] = NULL;
	// std::cout << "Default MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	for (int i = 0; i < 4; ++i) {
		if (src._materias[i])
			_materias[i] = src._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
	// std::cout << "MateriaSource copy constructor called" << std::endl;

}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++) {
		if (_materias[i])
			delete _materias[i];
	}
	// std::cout << "MateriaSource destructor called" << std::endl;
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
			if (_materias[i])
				delete _materias[i];
			if (rhs._materias[i])
				_materias[i] = rhs._materias[i]->clone();
			else
				_materias[i] = NULL;
		}
		// std::cout << "MateriaSource copy assignment operator called" << std::endl;
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!_materias[i])
		{
			_materias[i] = m;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_materias[i] && _materias[i]->getType() == type)
		{
			std::cout << "Created Materia " << type << std::endl;
			return (_materias[i]->clone());
		}
	}
	std::cout << "createMateria(): Type is unknown" << std::endl;

	return (0);

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