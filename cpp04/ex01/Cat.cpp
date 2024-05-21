/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:02:57 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/21 17:20:42 by ohladkov         ###   ########.fr       */
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

void	Cat::setIdea(int index, const std::string & idea)
{
	this->_brain->setIdea(index, idea);
}

std::string		Cat::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}

/* ************************************************************************** */