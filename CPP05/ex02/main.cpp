#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main()
{
	std::cout << "======= Valid Form Creation Tests =======" << std::endl;
	try
	{
		Form f1;
		std::cout << f1 << std::endl;
		Form f2("ID renwal form", 50, 30);
		std::cout << f2 << std::endl;
		Form f3(f2);
		std::cout << f3 << std::endl;
		Form f4("ID creation form", 20, 5);
		f4 = f1;
		std::cout << f4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "======= Invalid Form Creation Tests =======" << std::endl;
	try
	{
		Form f1("ID creation form", 1, 0);
		std::cout << f1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form f2("ID renwal form", 170, 150);
		std::cout << f2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "======= Successful signing Tests =======" << std::endl;
	try
	{
		Form f1("ID renwal form", 50, 30);
		Form f2("ID creation form", 20, 5);
		Bureaucrat b1("Messi", 1);
		Bureaucrat b2("Ronaldo", 50);
		b2.signForm(f1);
		b1.signForm(f2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "======= Failed signing Tests =======" << std::endl;
	try
	{
		Form f1("ID creation form", 20, 5);
		Bureaucrat b1("Ronaldo", 50);
		b1.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
