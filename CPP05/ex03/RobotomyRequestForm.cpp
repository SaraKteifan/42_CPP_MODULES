#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("RobotomyRequestForm", "UNKNOWN", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", target, 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other)
{}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void	RobotomyRequestForm::executeAction() const
{
	std::cout << "**ZZZZZZZZ**" << std::endl;
	int random_num = rand() % 2;
	if (random_num)
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << this->getTarget() << " robotomy failed :(" << std::endl;
}
