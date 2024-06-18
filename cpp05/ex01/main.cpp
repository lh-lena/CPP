#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat a("Ciro", 1);
		std::cout << a << std::endl;
		a.increaseGrade();
		std::cout << a << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat a("Vira", 150);
		std::cout << a << std::endl;
		a.decreaseGrade();
		std::cout << a << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat mr_id("MR_ID", 101);
		Form id_form("380 FORM", 100, 90);
		std::cout << id_form << std::endl;

		mr_id.signForm(id_form);
		std::cout << id_form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat mr_id("MR_ID", 0);
		Form id_form("380 FORM", 100, 90);
		std::cout << id_form << std::endl;

		mr_id.signForm(id_form);
		std::cout << id_form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}