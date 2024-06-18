/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:06:00 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/18 13:29:32 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return (*this);
}

Intern::~Intern() {}

const char *Intern::NoFormExceprion::what() const throw() {
	return ("Invalid form name");
}

AForm	*Intern::makeForm(const std::string formName, const std::string target)
{
	int i;
	std::string	name[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm",
	};

	for (i = 0; i < 3; i++)
	{
		if (formName.compare(name[i]) == 0)
			break ;
	}
	switch (i)
	{
		case (0) :
			std::cout << "Intern creates " << formName << std::endl;
			return (new ShrubberyCreationForm(target));
		case (1) :
			std::cout << "Intern creates " << formName << std::endl;
			return (new RobotomyRequestForm(target));
		case (2) :
			std::cout << "Intern creates " << formName << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			throw Intern::NoFormExceprion();
	}
}
