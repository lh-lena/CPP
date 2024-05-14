#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
public:
    ClapTrap ( std::string name );
    ClapTrap &		operator=( ClapTrap const & src );
    ClapTrap ( ClapTrap const & src );
    ~ClapTrap ( void );
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string     getName ( void );
    unsigned int    getHitPnt ( void );
    unsigned int    getEnergyPnt ( void );
    unsigned int    getAttackDmg ( void );

protected:
    std::string      _name;
    unsigned int    _hit_pnt;
    unsigned int    _energy_pnt;
    unsigned int    _attack_damage;
};

std::ostream &  operator<<( std::ostream & o, ClapTrap const & i );

#endif