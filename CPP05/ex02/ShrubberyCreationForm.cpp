#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", "UNKNOWN", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", target, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other)
{}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((this->getTarget() + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cerr << "Couldn't create file " << this->getTarget() + "_shrubbery" << std::endl;
		return ;
	}
	file <<
			"                 &&& &&  & &&\n"
			"             && &\\\\/&\\\\|& ()|/ @, &&\n"
			"             &\\\\/(/&/&||/& /_/)_&/_&\n"
			"          &() &\\\\/&|()|/&\\\\/ '%\" & ()\n"
			"         &_\\\\_&&_\\\\ |& |&&/&__%_/_& &&\n"
			"       &&   && & &| &| /& & % ()& /&&\n"
			"        ()&_---()&\\\\&\\\\|&&-&&--%---()~\n"
			"            &&     \\\\|||\n"
			"                    |||\n"
			"                    |||\n"
			"                    |||\n"
			"              , -=-~  .-^- _\n";

	file.close();
}
