/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:25:46 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/20 16:26:34 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria()
{
	std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "Parametric AMateria constructor called" << std::endl;
}

AMateria::AMateria( const AMateria & src )
{
	*this = src;
    std::cout << "AMateria copy constructor called for "  << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &				AMateria::operator=( AMateria const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
		std::cout << "AMateria copy assignment operator called" << std::endl;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AMateria const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

// AMateria*	AMateria::clone() const
// {
	
// }

// void	AMateria::use(ICharacter& target)
// {
	
// }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	const & AMateria::getType() const
{
	return (this->_type);
}

/* ************************************************************************** */