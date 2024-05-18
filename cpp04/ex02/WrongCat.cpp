/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:02:57 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/18 12:01:14 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
	setType("WrongCat");
	std::cout << "Default WrongCat constractor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat & src )
{
	*this = src;
    std::cout << "WrongCat copy constructor called" << std::endl;

}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
        std::cout << "WrongCat copy assignment operator called" << std::endl;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongCat const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	WrongCat::makeSound() const {
	std::cout << "Definitely not  the cat sound!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */