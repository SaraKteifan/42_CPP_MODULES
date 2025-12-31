#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name)
{}

HumanB::~HumanB()
{}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	if (!weapon)
		std::cout << this->name << " has no weapon."<< std::endl;
	else
		std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}
