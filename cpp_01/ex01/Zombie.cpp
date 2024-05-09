#include "Zombie.hpp"

Zombie::Zombie( void ) : _name("Stepan")
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
