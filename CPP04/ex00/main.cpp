#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << "========== Correct Animal Tests ==========" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << "========== Wrong Animal Tests ==========" << std::endl;
	const WrongAnimal* k = new WrongCat();
	WrongCat	l;
	std::cout << k->getType() << " " << std::endl;
	k->makeSound(); 
	l.makeSound(); 
	delete k;
	return (0);
}
