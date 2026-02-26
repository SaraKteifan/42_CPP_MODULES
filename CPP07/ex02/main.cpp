#include "Array.hpp"
#include <iostream>
#include <string>

int	main()
{
	Array<std::string> a;
	Array<int> b(3);
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;

	std::cout << "======= Valid Test =======" << std::endl;
	try
	{
		std::cout << b[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "======= Out of bounds Test =======" << std::endl;
	try
	{
		std::cout << b[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "======= Deep Copy Test =======" << std::endl;
	Array<int> c(b);
	Array<int> d;
	d = c;
	try
	{
		std::cout << b[0] << ", " << &b[0] << std::endl;
		std::cout << c[0] << ", " << &c[0] << std::endl;
		std::cout << d[0] << ", " << &d[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "======= Another Deep Copy Tests =======" << std::endl;
	try
	{
		b[0] = 42;
		std::cout << b[0] << std::endl;
		std::cout << c[0] << std::endl;
		std::cout << d[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
