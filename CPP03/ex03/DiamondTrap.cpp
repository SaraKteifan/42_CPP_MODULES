#include "DiamondTrap.hpp"
#include <iostream>


DiamondTrap::DiamondTrap() : ClapTrap()
{
	this->name = "default";
	ClapTrap::name = this->name + "_clap_name";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 30;
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 30;
	std::cout << "DiamondTrap parameterized constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), name(other.name)
{
	std::cout << "DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy assignment operator called." << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->name = other.name;
	}	
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << this->name << " has another ClapTrap name " << ClapTrap::name << "!" << std::endl;
}