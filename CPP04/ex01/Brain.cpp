#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called." << std::endl;
	*this = other;
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called." << std::endl;
	if (this != &other)
		this->ideas = other.ideas;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}
