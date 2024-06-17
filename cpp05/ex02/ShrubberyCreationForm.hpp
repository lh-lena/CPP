
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	class OpenFileExeption : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

private:
	ShrubberyCreationForm();
	std::string 	_target;
	virtual void	performAction() const;
};

#endif //SHRUBBERYCREATIONFORM_HPP