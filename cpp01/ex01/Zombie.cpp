/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:29:59 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/10 12:30:01 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	std::cout << "Constructor called" << "\n";
}

Zombie::~Zombie( void ) {
	std::cout << _name << " is destroyed" << "\n";
	return ;
}

void Zombie::announce( void ) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << "\n";
}

void	Zombie::setName (std::string name)
{
	_name = name;
}
