#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base::~Base()
{
}

Base * generate(void)
{
	Base*	res = NULL;
	int		random_num = rand() % 3;
	switch (random_num)
	{
	case 0:
		res = new A;
		std::cout << "\"generate\" function generated an A object" << std::endl;
		break;
	case 1:
		res = new B;
		std::cout << "\"generate\" function generated a B object" << std::endl;
		break;
	case 2:
		res = new C;
		std::cout << "\"generate\" function generated a C object" << std::endl;
		break;
	default:
		break;
	}
	return (res);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
		return ;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
		return ;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
		return ;
	}
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
}
