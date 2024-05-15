#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap()
{
	_name = "name";
	this->_hit_pnt = FragTrap::getHitPnt();
	this->_energy_pnt = ScavTrap::getEnergyPnt();
	this->_attack_damage = FragTrap::getAttackDmg();
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
	this->_name = name;
	this->_hit_pnt = FragTrap::getHitPnt();
	this->_energy_pnt = ScavTrap::getEnergyPnt();
	this->_attack_damage = FragTrap::getAttackDmg();
	std::cout << "DiamondTrap constructor called for " << getName() << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ) : ClapTrap(src)
{
	*this = src;
	std::cout << "DiamondTrap copy constructor called for " << src.getName() << std::endl;
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & src )
{
	if ( this != &src )
	{
		this->_name = src.getName();
		this->_hit_pnt = src.getHitPnt();
		this->_energy_pnt = src.getEnergyPnt();
		this->_attack_damage = src.getAttackDmg();
		std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void	DiamondTrap::whoAmI( void ) {
	std::cout << "I am " << getName() << "and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}

/**
 * By using virtual inheritance, we prevent multiple copies of the ClapTrap base class from being included in DiamondTrap, 
 * ensuring that the name attribute is shared between FragTrap and ScavTrap in DiamondTrap. This avoids the diamond problem
 * and ensures that there's only one instance of name in DiamondTrap.
 */
/* ************************************************************************** */