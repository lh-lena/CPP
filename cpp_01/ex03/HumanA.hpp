#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <cstring>
# include <iostream>
# include "Weapon.hpp"

class HumanA {
public:
	HumanA (const std::string& nm, Weapon& weaponA);
	~HumanA ( void );

	void	attack();
private:
	std::string _name;
	Weapon& _weapon;
};

#endif