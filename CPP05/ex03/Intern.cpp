#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>


Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{}

static AForm*	makeShrubberyCreationForm(const std::string& formTarget)
{
	return new ShrubberyCreationForm(formTarget);
}

static AForm*	makeRobotomyRequestForm(const std::string& formTarget)
{
	return new RobotomyRequestForm(formTarget);
}

static AForm*	makePresidentialPardonForm(const std::string& formTarget)
{
	return new PresidentialPardonForm(formTarget);
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	std::string	names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* form;
	AForm*	(*methods[3])(const std::string&) = {makeShrubberyCreationForm, makeRobotomyRequestForm, makePresidentialPardonForm};
	for(size_t i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{		
			form = methods[i](formTarget);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	std::cout << "Error: unknown form name." << std::endl;
	return (NULL);
}