#include "ClapTrap.hpp"
#include <iostream>


ClapTrap::ClapTrap() : name("default"), hit_points(10) , energy_points(10) , attack_damage(0)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap parameterized constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name),
	hit_points(other.hit_points),
	energy_points(other.energy_points),
	attack_damage(other.attack_damage)
{
	std::cout << "ClapTrap copy constructor called." << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called." << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energy_points > 0 && this->hit_points > 0)
	{
		this->energy_points--;
		std::cout << "ClapTrap " << this->name 
		<< " attacks " << target << ", causing ("
		<< this->attack_damage << ") points of damage!"
		<< " (HP: " << this->hit_points << ", EP: " << this->energy_points << ")"
		<< std::endl;
	}
	else
	{
		if (this->hit_points <= 0)
			std::cout << "ClapTrap " << this->name << " is dead and cannot attack!" << std::endl;
		else if (this->energy_points <= 0)
			std::cout << "ClapTrap " << this->name << " has no energy points to attack!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points > 0)
	{
		if (amount > (unsigned int)this->hit_points)
			this->hit_points = 0;
		else
			this->hit_points = this->hit_points - amount;
		std::cout << "ClapTrap " << this->name 
		<< " took damage with (" << amount << ") points!"
		<< " (HP: " << this->hit_points << ", EP: " << this->energy_points << ")"
		<< std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points > 0 && this->hit_points > 0)
	{
		this->energy_points--;
		this->hit_points = this->hit_points + amount;
		std::cout << "ClapTrap " << this->name 
		<< " repaired itself with (" << amount << ") points!"
		<< " (HP: " << this->hit_points << ", EP: " << this->energy_points << ")"
		<< std::endl;
	}
	else
	{
		if (this->hit_points <= 0)
			std::cout << "ClapTrap " << this->name << " is dead and cannot repair itself!" << std::endl;
		else if (this->energy_points <= 0)
			std::cout << "ClapTrap " << this->name << " has no energy points to repair itself!" << std::endl;
	}
}
