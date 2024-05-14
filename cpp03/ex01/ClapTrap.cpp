#include "ClapTrap.hpp"

ClapTrap::ClapTrap ( std::string name)
{
    this->_name = name;
    this->_hit_pnt = 0;
    this->_energy_pnt = 10;
    this->_attack_damage = 10;
    std::cout << "ClapTrap constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap& src) {
    *this = src;
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=( ClapTrap const & src )
{
	if ( this != &src )
	{
		this->_name = src._name;
        this->_hit_pnt = src._hit_pnt;
        this->_energy_pnt = src._energy_pnt;
        this->_attack_damage = src._attack_damage;
	}
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap ( void ) {
    std::cout << "ClapTrap destructor called" << std::endl;
}

std::string ClapTrap::getName ( void ) {
    return (this->_name);
}

unsigned int       ClapTrap::getHitPnt( void ) {
    return (this->_hit_pnt);
}

unsigned int       ClapTrap::getEnergyPnt( void ) {
    return (this->_energy_pnt);
}

unsigned int       ClapTrap::getAttackDmg( void ) {
    return (this->_attack_damage);
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_energy_pnt == 0 || this->_hit_pnt == 0)
    {
        std::cout << this->_name + " has no points to attack!" << std::endl;
        std::cout << "\tHit points: " << this->_hit_pnt << " | Energy points: " << this->_energy_pnt << std::endl;
        return ;
    }
    this->_energy_pnt--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target 
    << " causing " << this->_attack_damage << " point of damage!" << std::endl;
    std::cout << "\tHit points: " << this->_hit_pnt << " | Energy points: " << this->_energy_pnt << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (!amount)
    {
        std::cout << "Invalid amount of points" << std::endl;
        return ;
    }
    if (this->_hit_pnt == 0)
    {
        std::cout << this->_name << " is dead" << std::endl;
        std::cout << "\tHit points: " << this->_hit_pnt << " | Energy points: " << this->_energy_pnt << std::endl;
        return ;
    }
    this->_hit_pnt -= amount;
    std::cout << this->_name << " takes " << amount << " damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!amount)
    {
        std::cout << "Invalid amount of points" << std::endl;
        return ;
    }
    if (this->_energy_pnt == 0)
    {
        std::cout << this->_name << " has no energy points to be repaired." << std::endl;
        return ;
    }
    if (this->_hit_pnt == 10)
    {
        std::cout << this->_name << " has already full amount of points" << std::endl;
        return ;
    }
    this->_energy_pnt--;
    this->_hit_pnt += amount;
    std::cout << this->_name << " is repaired for " << amount << " hit points!" << std::endl;
}



/* std::ostream &			operator<<( std::ostream & o, ClapTrap const & i )
{
    o << i._name << "has\nHit points: " << i.getHitPnt() << " | Energy points: " << this->_energy_pnt << std::endl;

	// o << "Value = " << i.getValue();
	return o;
} */