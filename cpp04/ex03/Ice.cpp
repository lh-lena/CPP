/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:17:36 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/22 12:48:08 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Default Ice constructor called" << std::endl;
}

Ice::Ice( const Ice & src ) : AMateria("ice")
{
	*this = src;
    // std::cout << "Ice copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
	// std::cout << "Ice destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &				Ice::operator=( Ice const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
		// std::cout << "Ice copy assignment operator called" << std::endl;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria*	Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */