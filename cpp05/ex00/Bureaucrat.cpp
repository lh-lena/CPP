/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:05:04 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/18 16:23:13 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name) {
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName( void ) const {
	return (this->_name);
}


Bureaucrat::Bureaucrat(Bureaucrat const & src) : _grade(src._grade), _name(src._name) {}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & src)
{
	if (this != &src)
	{
		_grade = src._grade;
	}
	return (*this);
}

int	Bureaucrat::getGrade( void )  const {
	return (this->_grade);
}

void	Bureaucrat::increaseGrade( void )
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decreaseGrade( void )
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what () const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what () const throw()
{
	return ("Grade too low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (os);
}
