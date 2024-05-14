#include "ScavTrap.hpp"


// ScavTrap::ScavTrap()
// {
// }

// ScavTrap::ScavTrap( const ScavTrap & src )
// {
// }



// ScavTrap::~ScavTrap()
// {
// }


// ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

// std::ostream &			operator<<( std::ostream & o, ScavTrap const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }

void	ScavTrap::guardGate() {
	std::cout << this->_name << " is guarding the gate!" << std::endl;
}