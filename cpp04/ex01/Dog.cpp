/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:03:03 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/18 15:44:25 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : _brain(new Brain())
{
	this->setType("Dog");
	std::cout << "Default Dog constractor called" << std::endl;
}

Dog::Dog( const Dog & src ) : Animal(src)
{
	if (_brain)
		delete _brain;
	_brain = new Brain(*src._brain);
    std::cout << "Dog copy constructor called" << std::endl;

}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	if (_brain)
		delete	_brain;
	std::cout << "Dog destractor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		Animal::operator=(rhs);// this->type = rhs.getType();
		if (_brain)
			delete _brain;
		_brain = new Brain(*rhs._brain);
        std::cout << "Dog copy assignment operator called" << std::endl;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Dog const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */