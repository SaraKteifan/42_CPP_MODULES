#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("UNKNOWN")
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal parameterized constructor called." << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor called." << std::endl;
	*this = other;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy assignment operator called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::setType(const std::string& type)
{
	this->type = type;
}
