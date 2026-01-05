#include "FragTrap.hpp"

int	main()
{
	FragTrap frag_trap("Sara");

	frag_trap.attack("Enemy");
	frag_trap.takeDamage(30);
	frag_trap.beRepaired(50);
	frag_trap.takeDamage(60);
	frag_trap.highFivesGuys();
	frag_trap.takeDamage(90);
	frag_trap.attack("Another enemy");
	frag_trap.beRepaired(20);
	return (0);
}
