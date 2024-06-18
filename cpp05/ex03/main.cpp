/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:33:20 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/18 17:21:01 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern	junior;
	AForm	*form = NULL;

	try
	{
		form = junior.makeForm("DoYouKnowMe", "Hmmmm");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		form = junior.makeForm("RobotomyRequestForm", "World");
		if (form)
			std::cout << *form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat a("name", 1);
		if (form)
		{
			std::cout << *form << std::endl;
			form->beSigned(a);
		}
		else
			std::cout << "Form creation failed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	delete form;
    return 0;
}
