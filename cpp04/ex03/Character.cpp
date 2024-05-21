/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:18:25 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/21 19:38:22 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character()
{
	std::cout << "Default Character constructor called" << std::endl;

}

Character::Character( std::string const & name ) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
	std::cout << "Parametric Character constructor called for" << name << std::endl;
}

Character::Character( const Character & src ) :_name(src._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (src.inventory[i])
			inventory[i] = src.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	std::cout << "Character copy constructor called for" << src._name << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (int i = 0; i < 4; ++i) {
		if (inventory[i])
			delete inventory[i];
	}
	std::cout << "Character destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if (this != &rhs)
	{
		_name = rhs._name;
		for (int i = 0; i < 4; i++) {
			if (inventory[i])
				delete inventory[i];
			if (rhs.inventory[i])
				inventory[i] = rhs.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
		std::cout << "Character copy assignment operator called" << std::endl;
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string const & Character::getName() const
{
	return(this->_name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx > 4)
	{
		this->inventory[idx]->use(target);
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */