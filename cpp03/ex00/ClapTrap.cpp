/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:58:23 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/16 10:58:24 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap ()
{
    this->_name = "no-name";
    this->_hit_pnt = 10;
    this->_energy_pnt = 10;
    this->_attack_damage = 0;
    std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap ( std::string name)
{
    this->_name = name;
    this->_hit_pnt = 10;
    this->_energy_pnt = 10;
    this->_attack_damage = 0;
    std::cout << "ClapTrap constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap& src) {
    *this = src;
    std::cout << "ClapTrap copy constructor called for " << this->_name << std::endl;
}

ClapTrap::~ClapTrap ( void )
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=( ClapTrap const & src )
{
	if ( this != &src )
	{
		this->_name = src.getName();
        this->_hit_pnt = src.getHitPnt();
        this->_energy_pnt = src.getEnergyPnt();
        this->_attack_damage = src.getAttackDmg();
        std::cout << "ClapTrap copy assignment operator called" << std::endl;
	}
	return *this;
}

std::string ClapTrap::getName ( void ) const {
    return (this->_name);
}

unsigned int       ClapTrap::getHitPnt( void ) const {
    return (this->_hit_pnt);
}

unsigned int       ClapTrap::getEnergyPnt( void ) const {
    return (this->_energy_pnt);
}

unsigned int       ClapTrap::getAttackDmg( void ) const {
    return (this->_attack_damage);
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_energy_pnt <= 0 || this->_hit_pnt <= 0)
    {
        std::cout << "ClapTrap " << this->_name + " has no points to attack!" << std::endl;
    }
    this->_energy_pnt--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target 
    << " causing " << this->_attack_damage << " point of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount < 0)
    {
        std::cout << "Invalid amount of points" << std::endl;
        return ;
    }
    if (this->_hit_pnt == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
        return ;
    }
    if (this->_hit_pnt > amount)
        this->_hit_pnt -= amount;
    else
        this->_hit_pnt = 0;
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (amount < 0)
    {
        std::cout << "Invalid amount of points" << std::endl;
        return ;
    }
    if (this->_energy_pnt == 0 || this->_hit_pnt < 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy points to be repaired." << std::endl;
        return ;
    }
    if (this->_hit_pnt == 10)
    {
        std::cout << "ClapTrap " << this->_name << " has already full amount of points" << std::endl;
        return ;
    }
    this->_energy_pnt--;
    this->_hit_pnt += amount;
    std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " hit points!" << std::endl;
}

// Operator overload for <<
std::ostream &  operator<<( std::ostream & o, ClapTrap const & i )
{
    o << "\tClapTrap " << i.getName() 
    << " has:\n\tHit points: " << i.getHitPnt() 
    << " | Energy points: " << i.getEnergyPnt()
    << std::endl;

	return o;
}
