/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:02:57 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/20 22:43:30 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : _brain(new Brain())
{
	this->setType("Cat");
	std::cout << "Default Cat constractor called" << std::endl;
}

Cat::Cat( const Cat & src )
{
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*src._brain);
	this->type = src.type;
	std::cout << "Cat copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	delete	_brain;
	std::cout << "Cat destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
		this->type = rhs.type;
        std::cout << "Cat copy assignment operator called" << std::endl;
	}
	return (*this);
}

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */