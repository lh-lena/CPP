#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string.h>

class Warlock
{

public:
	// Warlock();
	Warlock( std::string name, std::string title );
	~Warlock();
	Warlock(const Warlock &src);
	Warlock &operator=(const Warlock &src);
	std::string const getName() const;
	std::string const getTitle() const;
	void setTitle(std::string const &title);
	void introduce() const;

private:
	std::string _name;
	std::string _title;	


};



#endif
