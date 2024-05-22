/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:18:25 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/22 13:18:04 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character()
{
	// std::cout << "Default Character constructor called" << std::endl;
}

Character::Character( std::string const & name ) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	// std::cout << "Parametric Character constructor called for " << name << std::endl;
}

Character::Character( const Character & src ) :_name(src._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	// std::cout << "Character copy constructor called for " << src._name << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
}
	// std::cout << "Character destructor called" << std::endl;
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
			if (_inventory[i])
				delete _inventory[i];
			if (rhs._inventory[i])
				_inventory[i] = rhs._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
		// std::cout << "Character copy assignment operator called" << std::endl;
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
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "The _inventory is full" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		_inventory[idx] = NULL;
		std::cout << "unequiped _inventory with index " << idx << std::endl;

		return ;
	}
	std::cout << "unequip(): Invalid index" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4)
	{
		if (this->_inventory[idx])
		{
			this->_inventory[idx]->use(target);
			return ; 
		}
	}
	std::cout << "use(): Invalid index" << std::endl; 
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */