#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main()
{
	std::cout << "======= Intern form cretaion tests =======" << std::endl;
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
		std::cout << *rrf << std::endl;
	
	AForm* scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "42Amman backyard");
	if (scf)
		std::cout << *scf << std::endl;

	AForm* ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "Batman");
	if (ppf)
		std::cout << *ppf << std::endl;

	AForm* bla;
	bla = someRandomIntern.makeForm("bla bla bla", "random target");
	if (bla)
		std::cout << *bla << std::endl;

	delete rrf;
	delete scf;
	delete ppf;
	delete bla;

	return (0);
}
