#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat a("Ciro", 1);
		std::cout << a << std::endl;
		a.increaseGrade();
		std::cout << a << std::endl;
	}
	catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat a("Vira", 150);
		std::cout << a << std::endl;
		a.decreaseGrade();
		std::cout << a << std::endl;
	}
	catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
