#include "ScavTrap.hpp"
#include <iostream>


ScavTrap::ScavTrap() : ClapTrap()
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap parameterized constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called." << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->energy_points > 0 && this->hit_points > 0)
	{
		this->energy_points--;
		std::cout << "ScavTrap " << this->name 
		<< " attacks " << target << ", causing ("
		<< this->attack_damage << ") points of damage!"
		<< " (HP: " << this->hit_points << ", EP: " << this->energy_points << ")"
		<< std::endl;
	}
	else
	{
		if (this->hit_points <= 0)
			std::cout << "ScavTrap " << this->name << " is dead and cannot attack!" << std::endl;
		else if (this->energy_points <= 0)
			std::cout << "ScavTrap " << this->name << " has no energy points to attack!" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap "<< this->name << " is now in Gate keeper mode." << std::endl;
}
