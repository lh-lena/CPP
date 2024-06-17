#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(const std::string& name, const int toSign, const int toExecute) : 
_name(name), _isSigned(false), _gradeToSign(toSign), _gradeToExecute(toExecute) {
	if (toSign < 1)
		throw AForm::GradeTooHighException();
	if (toSign > 150)
		throw AForm::GradeTooLowException();
	if (toExecute < 1)
		throw AForm::GradeTooHighException();
	if (toExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & src) : 
_name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign),
_gradeToExecute(src._gradeToExecute) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm&	AForm::operator=(AForm const & src)
{
	if (this != &src)
	{
		_isSigned = src._isSigned;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const AForm& src)
{
	os	<< "AForm name: " << src.getName() << "\n"
		<< "Signed: " << (src.getIsSigned() ? "Yes" : "No") << "\n"
		<< "Sign Grade " << src.getGradeToSign() << "\n"
		<< "Execution Grade: " << src.getGradeToExecute();
	return (os);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	AForm::beSigned(const Bureaucrat & src)
{
	if (src.getGrade() > _gradeToSign) {
		throw AForm::GradeTooLowException();
	}
	_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	performAction();
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ("Form not signed");
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	AForm::getName( void ) const {
	return (_name);
}

bool	AForm::getIsSigned( void ) const {
	return (_isSigned);
}

int	AForm::getGradeToSign( void ) const {
	return (_gradeToSign);
}

int	AForm::getGradeToExecute( void ) const {
	return (_gradeToExecute);
}
