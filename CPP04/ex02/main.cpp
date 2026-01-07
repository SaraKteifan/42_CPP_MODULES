#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	// std::cout << "======== Tests that will not work ========" << std::endl;
	// Animal	a;
	// Animal* b = new Animal();
	// delete b;

	std::cout << "======== Tests that will work ========" << std::endl;
	const Animal* c = new Dog();
	const Animal* d = new Cat();
	delete c;
	delete d;
	
	return (0);
}
