/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:25:46 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/22 12:50:26 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria()
{
	// std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	// std::cout << "Parametric AMateria constructor called for type " << type << std::endl;
}

AMateria::AMateria( const AMateria & src )
{
	*this = src;
    // std::cout << "AMateria copy constructor called for "  << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
	// std::cout << "AMateria destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &				AMateria::operator=( AMateria const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
		// std::cout << "AMateria copy assignment operator called" << std::endl;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	AMateria::use(ICharacter& target)
{
	// std::cout << "AMateria::use Name" << target.getName() << std::endl;
	(void)target;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	const & AMateria::getType() const
{
	return (this->_type);
}

/* ************************************************************************** */