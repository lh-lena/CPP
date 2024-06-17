#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(const std::string& name, const int toSign, const int toExecute) : 
_name(name), _isSigned(false), _gradeToSign(toSign), _gradeToExecute(toExecute) {
	if (toSign < 1)
		throw Form::GradeTooHighException();
	if (toSign > 150)
		throw Form::GradeTooLowException();
	if (toExecute < 1)
		throw Form::GradeTooHighException();
	if (toExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & src) : 
_name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign),
_gradeToExecute(src._gradeToExecute) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form&	Form::operator=(Form const & src)
{
	if (this != &src)
	{
		_isSigned = src._isSigned;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Form& src)
{
	os	<< "Form name: " << src.getName() << "\n"
		<< "Signed: " << (src.getIsSigned() ? "Yes" : "No") << "\n"
		<< "Sign Grade " << src.getGradeToSign() << "\n"
		<< "Execution Grade: " << src.getGradeToExecute();
	return (os);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

void	Form::beSigned(const Bureaucrat & src)
{
	if (src.getGrade() > _gradeToSign) {
		throw Form::GradeTooLowException();
	}
	_isSigned = true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Form::getName( void ) const {
	return (_name);
}

bool	Form::getIsSigned( void ) const {
	return (_isSigned);
}

int	Form::getGradeToSign( void ) const {
	return (_gradeToSign);
}

int	Form::getGradeToExecute( void ) const {
	return (_gradeToExecute);
}
