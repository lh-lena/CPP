#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap()
{
	this->_hit_pnt = 100;
	this->_energy_pnt = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name) : ClapTrap(name)
{
	this->_hit_pnt = 100;
	this->_energy_pnt = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap constructor called for " << this->_name << std::endl;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src)
{
	*this = src;
	std::cout << "FragTrap copy constructor called for " << src.getName() << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & src )
{
	if ( this != &src )
	{
		this->_name = src.getName();
		this->_hit_pnt = src.getHitPnt();
		this->_energy_pnt = src.getEnergyPnt();
		this->_attack_damage = src.getAttackDmg();
		std::cout << "FragTrap copy assignment operator called" << std::endl;
	}
	return (*this);
}

std::ostream &			operator<<( std::ostream & o, FragTrap const & i )
{
	o << "\tFragTrap " << i.getName() 
	<< " has:\n\tHit points: " << i.getHitPnt() 
	<< " | Energy points: " << i.getEnergyPnt()
	<< std::endl;

	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << ": High fives?" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */