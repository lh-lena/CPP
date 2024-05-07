#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <cstring>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
public:

	HumanB(const std::string& humanName);
	~HumanB ( void );
	void	attack();
	void 	setWeapon(Weapon& newWeapon);
private:
	std::string _name;
	Weapon* _weapon;
};

#endif 