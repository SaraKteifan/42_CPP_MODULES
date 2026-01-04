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
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
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

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points > 0)
	{
		if (amount > (unsigned int)this->hit_points)
			this->hit_points = 0;
		else
			this->hit_points = this->hit_points - amount;
		std::cout << "ScavTrap " << this->name 
		<< " took damage with (" << amount << ") points!"
		<< " (HP: " << this->hit_points << ", EP: " << this->energy_points << ")"
		<< std::endl;
	}
	else
		std::cout << "ScavTrap " << this->name << " is dead!" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points > 0 && this->hit_points > 0)
	{
		this->energy_points--;
		this->hit_points = this->hit_points + amount;
		std::cout << "ScavTrap " << this->name 
		<< " repaired itself with (" << amount << ") points!"
		<< " (HP: " << this->hit_points << ", EP: " << this->energy_points << ")"
		<< std::endl;
	}
	else
	{
		if (this->hit_points <= 0)
			std::cout << "ScavTrap " << this->name << " is dead and cannot repair itself!" << std::endl;
		else if (this->energy_points <= 0)
			std::cout << "ScavTrap " << this->name << " has no energy points to repair itself!" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << " ScavTrap "<< this->name << " is now in Gate keeper mode." << std::endl;
}
