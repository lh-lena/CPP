#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration

class Form
{
public:

	Form(const std::string& name, const int toSign, const int toExecute);
	~Form();
	Form(Form const & src);
	Form& operator=(Form const & src);

	std::string		getName( void ) const;
	bool			getIsSigned( void ) const;
	int				getGradeToSign( void ) const;
	int				getGradeToExecute( void ) const;

	void			beSigned(const Bureaucrat & src);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	Form(void); 						// Disallow default construction
};

std::ostream	&operator<<(std::ostream &os, const Form& src);

#endif