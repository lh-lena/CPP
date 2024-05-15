#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
public:
    ClapTrap ();
    ClapTrap ( std::string name );
    ClapTrap &  operator=( ClapTrap const & src );
    ClapTrap ( ClapTrap const & src );
    ~ClapTrap ( void );
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string     getName ( void ) const;
    unsigned int    getHitPnt ( void ) const;
    unsigned int    getEnergyPnt ( void ) const;
    unsigned int    getAttackDmg ( void ) const;

protected:
    std::string      _name;
    unsigned int    _hit_pnt;
    unsigned int    _energy_pnt;
    unsigned int    _attack_damage;
};

std::ostream &  operator<<( std::ostream & o, ClapTrap const & i );

#endif