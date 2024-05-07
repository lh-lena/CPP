#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(const std::string& nm, Weapon& weaponA) : _name(nm), _weapon(weaponA) {}

HumanA::~HumanA ( void ) {}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
