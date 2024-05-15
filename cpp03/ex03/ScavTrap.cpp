#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->_hit_pnt = 100;
    this->_energy_pnt = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap default costructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name) : ClapTrap(name)
{
    this->_hit_pnt = 100;
    this->_energy_pnt = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap constructor called for " << this->_name << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
    *this = src;
    std::cout << "ScavTrap copy constructor called for " << src.getName() << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}


ScavTrap &  ScavTrap::operator=( ScavTrap const & src )
{
    if ( this != &src )
    {
        this->_name = src.getName();
        this->_hit_pnt = src.getHitPnt();
        this->_energy_pnt = src.getEnergyPnt();
        this->_attack_damage = src.getAttackDmg();
        std::cout << "ScavTrap copy assignment operator called" << std::endl;
    }
    return *this;
}

// Operator overload for <<
std::ostream &  operator<<( std::ostream & o, ScavTrap const & i )
{
    o << "\tScavTrap " << i.getName() 
    << " has:\n\tHit points: " << i.getHitPnt() 
    << " | Energy points: " << i.getEnergyPnt()
    << std::endl;
    return (o);
}

void    ScavTrap::guardGate() {
    std::cout << this->_name << " is guarding the gate!" << std::endl;
}