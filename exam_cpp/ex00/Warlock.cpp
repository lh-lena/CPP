#include "Warlock.hpp"

// Warlock::Warlock( void ) {

// }

Warlock::Warlock( std::string name, std::string title ) : _name(name), _title(title)
{
	std::cout << name << ": this looks like another boring day." << std::endl; 
}

Warlock::~Warlock( void  ) {
	std::cout << getName() << ": My job here is done" << std::endl;
}

Warlock::Warlock(const Warlock &src)
{
	*this = src;
}

Warlock &Warlock::operator=(const Warlock &src)
{
	this->_name = src._name;
	this->_title = src._title;
	return (*this);
}

void	Warlock::setTitle(std::string const &title)
{
	this->_title = title;
}

 std::string const Warlock::getName()  const
{
	return (this->_name);
}

 std::string const Warlock::getTitle()  const
{
	return (this->_title);
}

void	Warlock::introduce () const
{
	std::cout << this->_name  << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}
