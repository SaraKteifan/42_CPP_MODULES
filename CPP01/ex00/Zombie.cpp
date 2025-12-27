#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name): name(name)
{
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " destructed." << std::endl;
}

void	Zombie::announce( void ) const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
