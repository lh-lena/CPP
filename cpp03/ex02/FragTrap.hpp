#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

	public:

		FragTrap();
		FragTrap( std::string name);
		FragTrap( FragTrap const & src );
		~FragTrap(); //virtual ??

		FragTrap &		operator=( FragTrap const & src );
		void highFivesGuys(void);

};

std::ostream &			operator<<( std::ostream & o, FragTrap const & i );

#endif 