#include "Weapon.hpp"

// Weapon::Weapon () {}

Weapon::Weapon(const std::string& str) {
	setType(str);
}

Weapon::~Weapon( void ) {}

const std::string& Weapon::getType() {
	return (type);
}

void Weapon::setType(const std::string& newType) {
	type = newType;
}
