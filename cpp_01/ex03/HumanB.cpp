/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:36:15 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/10 12:36:17 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB (const std::string& nm) : _name(nm), _weapon(NULL) {}

void HumanB::setWeapon(Weapon& newWeapon) {
	this->_weapon = &newWeapon;
}

HumanB::~HumanB ( void ) {}

void HumanB::attack() {
	if (_weapon != NULL)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with their bare hands" << std::endl;
}
