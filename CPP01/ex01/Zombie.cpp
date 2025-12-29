#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(std::string name): name(name)
{}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " destructed." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
