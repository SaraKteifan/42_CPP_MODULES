#include "Span.hpp"
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	std::cout << "======= Test =======" << std::endl;
	Span sp(7);
	try
	{
		sp.addNumber(1);
		sp.addNumber(88);
		sp.addNumber(12);
		sp.addNumber(101);
		sp.addNumber(62);
		sp.addNumber(5);
		sp.addNumber(27);
		sp.addNumber(1000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "======= Not enough elements test =======" << std::endl;
	Span ssp(1);
	try
	{
		ssp.addNumber(3);
		std::cout << ssp.shortestSpan() << std::endl;
		// std::cout << ssp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "======= 10,000 numbers test =======" << std::endl;
	std::list<int> l;
	for (size_t i = 0; i < 10000; i++)
		l.push_back(rand() % 1000000);
	Span bsp(10000);
	try
	{
		bsp.addNumber(l.begin(), l.end());
		std::cout << bsp.shortestSpan() << std::endl;
		std::cout << bsp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }
