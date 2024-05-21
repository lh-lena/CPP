/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:03:03 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/21 17:16:56 by ohladkov         ###   ########.fr       */
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

Dog::Dog( const Dog & src )
{
	this->_brain = new Brain(*src._brain);
	this->type = src.getType();
    std::cout << "Dog copy constructor called" << std::endl;

}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
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
		this->type = rhs.getType();
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
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

void	Dog::setIdea(int index, const std::string & idea)
{
	this->_brain->setIdea(index, idea);
}

std::string		Dog::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}

/* ************************************************************************** */