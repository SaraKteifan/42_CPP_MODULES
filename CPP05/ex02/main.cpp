#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main()
{
	srand(time(0));
	std::cout << "======= Execution Tests =======" << std::endl;
	try
	{
		ShrubberyCreationForm f1("House garden");
		RobotomyRequestForm f2("Washing dishes");
		PresidentialPardonForm f3("Batman");
		Bureaucrat b1("Messi", 5);
		Bureaucrat b2("Ronaldo", 80);
		std::cout << "------ Signing Forms ------" << std::endl;
		b2.signForm(f1);
		b1.signForm(f2);
		b1.signForm(f3);
		std::cout << std::endl;
		std::cout << "------ Bureaucrat Messi ------" << std::endl;
		b1.executeForm(f1);
		std::cout << "---" << std::endl;
		b1.executeForm(f2);
		std::cout << "---" << std::endl;
		b1.executeForm(f3);
		std::cout << std::endl;
		std::cout << "------ Bureaucrat Ronaldo ------" << std::endl;
		b2.executeForm(f1);
		std::cout << "---" << std::endl;
		b2.executeForm(f2);
		std::cout << "---" << std::endl;
		b2.executeForm(f3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
