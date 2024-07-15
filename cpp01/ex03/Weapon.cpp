/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:36:47 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/10 12:37:02 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon () {}
Weapon::~Weapon( void ) {}

Weapon::Weapon(const std::string& str) {
	setType(str);
}

const std::string& Weapon::getType() {
	return (type);
}

void Weapon::setType(const std::string& newType) {
	type = newType;
}
