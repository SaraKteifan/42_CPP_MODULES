#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap diamond_trap("Sara");

	diamond_trap.whoAmI();
	diamond_trap.attack("Enemy");
	diamond_trap.takeDamage(30);
	diamond_trap.beRepaired(50);
	diamond_trap.takeDamage(60);
	diamond_trap.guardGate();
	diamond_trap.highFivesGuys();
	diamond_trap.takeDamage(90);
	diamond_trap.attack("Another enemy");
	diamond_trap.beRepaired(20);
	return (0);
}
