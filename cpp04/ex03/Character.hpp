#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>

class Character
{

	public:

		Character();
		Character(std::string const & type);
		Character( Character const & src );
		~Character();

		Character &		operator=( Character const & rhs );
		
};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */