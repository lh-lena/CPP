/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:33:20 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/18 12:25:25 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib> // for srand and rand
#include <ctime> // for time

int main(void)
{
	std::srand(time(NULL));

	ShrubberyCreationForm shrubbery("Home");
	RobotomyRequestForm robotomy("Morty");
	PresidentialPardonForm pardon("Rick Sanchez");
	Bureaucrat a("A", 146);
	Bureaucrat b("B", 120);
	Bureaucrat c("C", 3);
	ShrubberyCreationForm Shrubby_form("Hello");
	RobotomyRequestForm Robo_form("I am a robo form");
	PresidentialPardonForm President_form("Pardon form");

	std::cout << "\n ----------1---------- \n\n";

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << Shrubby_form << std::endl;
	std::cout << Robo_form << std::endl;
	std::cout << President_form << std::endl;

	std::cout << "\n ----------2---------- \n\n";
	a.signForm(Shrubby_form);
	b.signForm(Robo_form);
	c.signForm(President_form);
	std::cout << "\n";
	std::cout << Shrubby_form << std::endl;
	std::cout << Robo_form << std::endl;
	std::cout << President_form << std::endl;

	std::cout << "\n ----------3---------- \n\n";

	a.executeForm(Shrubby_form);
	b.executeForm(Robo_form);
	c.executeForm(President_form);

	std::cout << "\n ----------4---------- \n\n";

	c.signForm(Shrubby_form);
	c.signForm(Robo_form);
	c.signForm(President_form);
	std::cout << "\n";

	a.executeForm(Shrubby_form);
	b.executeForm(Robo_form);
	c.executeForm(President_form);
	
	std::cout << "\n ----------5---------- \n\n";
	for (int i = 0; i < 9; i++)
		a.increaseGrade();
	std::cout << a << std::endl;
	a.executeForm(Shrubby_form);
	Bureaucrat d("D", 44);
	d.executeForm(Robo_form);
	c.executeForm(President_form);

	return (0);
}