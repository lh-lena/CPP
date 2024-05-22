/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:02:50 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/22 11:37:02 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal() : type("[AAnimal]")
{
	std::cout << "Default AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal & src )
{
	*this = src;
    std::cout << "AAnimal copy constructor called for " << this->type << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &				AAnimal::operator=( AAnimal const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
		std::cout << "AAnimal copy assignment operator called" << std::endl;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AAnimal const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	AAnimal::makeSound() const {
	// std::cout << "Random AAnimal sound" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AAnimal::getType() const {
	return (this->type);
}

void			AAnimal::setType(std::string type) {
	this->type = type;
}


/* ************************************************************************** */