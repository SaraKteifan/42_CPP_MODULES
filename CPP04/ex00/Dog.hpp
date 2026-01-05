#ifndef DOG_H
# define DOG_H
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		~Dog();
};

#endif