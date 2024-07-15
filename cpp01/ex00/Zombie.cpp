/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:46:38 by ohladkov          #+#    #+#             */
/*   Updated: 2024/03/21 08:58:42 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	_name = name;
	std::cout << "Constructor called" << "\n";
}

Zombie::~Zombie( void ) {
	std::cout << _name << " is destroyed" << "\n";
	return ;
}

void Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << "\n";
}
