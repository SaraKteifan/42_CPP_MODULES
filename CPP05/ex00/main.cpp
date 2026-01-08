#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	std::cout << "======= Valid Bureaucrat Creation Tests =======" << std::endl;
	try
	{
		Bureaucrat b1;
		std::cout << b1 << std::endl;
		Bureaucrat b2("Sara", 1);
		std::cout << b2 << std::endl;
		Bureaucrat b3("Maha", 150);
		std::cout << b3 << std::endl;
		Bureaucrat b4("Omar", 70);
		std::cout << b4 << std::endl;
		Bureaucrat b5(b1);
		std::cout << b5 << std::endl;
		Bureaucrat b6("Othman", 3);
		b6 = b4;
		std::cout << b6 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "======= Invalid Bureaucrat Creation Tests =======" << std::endl;
	try
	{
		Bureaucrat b("Ali", 170);
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat b("Ahmad", 0);
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}