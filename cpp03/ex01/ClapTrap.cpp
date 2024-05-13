#include "ClapTrap.hpp"

ClapTrap::ClapTrap ( std::string name)
{
    this->_name = name;
    this->_hit_points = 0;
    this->_energy_points = 10;
    this->_attack_damage = 10;
    std::cout << "Default constructor called for " << this->_name << std::endl;
}

ClapTrap::~ClapTrap ( void )
{
    std::cout << "Default destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_energy_points == 0 || this->_hit_points == 0 || this->_hit_points < this->_attack_damage)
    {
        std::cout << "There is no point to attack!" << std::endl;
        std::cout << "\tHit points: " << this->_hit_points << " | Energy points: " << this->_energy_points << std::endl;
        return ;
    }
    this->_energy_points--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target 
    << " causing " << this->_attack_damage << " point of damage!" << std::endl;
    std::cout << "\tHit points: " << this->_hit_points << " | Energy points: " << this->_energy_points << std::endl;
    this->_attack_damage = 0;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (!amount)
    {
        std::cout << "Invalid amount of points" << std::endl;
        return ;
    }
    if (this->_hit_points < amount)
    {
        this->_attack_damage += amount;
        std::cout << "There is no point to take damage!" << std::endl;
        std::cout << "\tHit points: " << this->_hit_points << " | Energy points: " << this->_energy_points << std::endl;
        return ;
    }
    this->_attack_damage += amount;
    std::cout << "Damage - " << amount << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!amount)
    {
        std::cout << "Invalid amount of points" << std::endl;
        return ;
    }
    if (this->_energy_points == 0)
    {
        std::cout << "There is no energy point to be repaired!" << std::endl;
        std::cout << "\tHit points: " << this->_hit_points << " | Energy points: " << this->_energy_points << std::endl;
        return ;
    }
    this->_energy_points--;
    this->_hit_points += amount;
    std::cout << this->_name << " got " << amount << " hit points back." << std::endl;
}
