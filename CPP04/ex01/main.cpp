#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	// std::cout << "======== Tests in the subject ========" << std::endl;
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;//should not create a leak
	// delete i;

	// std::cout << "======== Tests requested by the subject ========" << std::endl;
	// Animal*	animals[8];
	// for (int i = 0; i < 4; i++)
	// 	animals[i] = new Dog();
	// for (int i = 4; i < 8; i++)
	// 	animals[i] = new Cat();
	
	// for (int i = 0; i < 8; i++)
	// 	delete animals[i];

	std::cout << "======== Test Deep Copy ========" << std::endl;
	Cat	cat1;
	Cat cat2(cat1);
	Cat	cat3 = cat2;
	cat1.printBrainAdress();
	cat2.printBrainAdress();
	cat3.printBrainAdress();
	
	return (0);
}
