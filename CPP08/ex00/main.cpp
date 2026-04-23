#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int	main()
{
	std::cout << "======= Tests with vector =======" << std::endl;

	std::vector<int> v;

	v.push_back(3);
	v.push_back(7);
	v.push_back(42);
	v.push_back(7);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 7);
		std::cout << *it << std::endl;
		std::cout << "Index: " << (it - v.begin()) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::vector<int>::iterator it = easyfind(v, 9);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "======= Tests with list =======" << std::endl;

	std::list<int> l;

	l.push_back(4);
	l.push_back(12);
	l.push_back(26);

	try
	{
		std::list<int>::iterator it = easyfind(l, 12);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::list<int>::iterator it = easyfind(l, 80);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
	std::cout << "======= Tests with deque =======" << std::endl;

	std::deque<int> d;

	d.push_back(700);
	d.push_back(850);
	d.push_back(1000);

	try
	{
		std::deque<int>::iterator it = easyfind(d, 1000);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::deque<int>::iterator it = easyfind(d, 1);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}
