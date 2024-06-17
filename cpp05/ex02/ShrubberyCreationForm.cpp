/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:01:33 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/17 22:38:42 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::performAction() const
{
	std::ofstream outFile((_target + std::string("_shrubbery")).c_str());

	if (!outFile.is_open())
		throw ShrubberyCreationForm::OpenFileExeption();
	outFile <<	"       _-_\n"
				"    /~~   ~~\\\n"
				" /~~         ~~\\\n"
				"{               }\n"
				" \\  _-     -_  /\n"
				"   ~  \\\\ //  ~\n"
				"_- -   | | _- _\n"
				"  _ -  | |   -_\n"
				"      // \\\\" << std::endl;
	outFile.close();
}

const char *ShrubberyCreationForm::OpenFileExeption::what() const throw()
{
	return ("Could not open and write the file!");
}
