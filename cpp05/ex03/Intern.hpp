#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();
	AForm	*makeForm(const std::string formName, const std::string target);
};

Intern::Intern(/* args */)
{
}

Intern::~Intern()
{
}

#endif //INTERN_HPP