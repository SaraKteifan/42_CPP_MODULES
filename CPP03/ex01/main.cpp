#include "ScavTrap.hpp"

int	main()
{
	ScavTrap scav_trap("Sara");

	scav_trap.attack("Enemy");
	scav_trap.takeDamage(30);
	scav_trap.beRepaired(50);
	scav_trap.takeDamage(60);
	scav_trap.guardGate();
	scav_trap.takeDamage(90);
	scav_trap.attack("Another enemy");
	scav_trap.beRepaired(20);
	return (0);
}
