#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <cstring>
# include <iostream>

class Weapon {
public:
	// Weapon( void );

	Weapon (const std::string& str);
	~Weapon( void );

	const std::string& getType();
	void setType(const std::string& newType);
private:
	std::string type;
};

#endif