/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:05:04 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/10 20:00:35 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(const std::string& name, int grade) {
	// this->_name = name;
	// try (grade)
	// {

	// }
	// catch ()
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName( void ) const {
	return (this->_name);
}

int	Bureaucrat::getGrade( void )  const {
	return (this->_grade);
}

void	Bureaucrat::increaseGrade( void )
{
	this->_grade--;
}

void	Bureaucrat::decreaseGrade( void )
{
	this->_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
}