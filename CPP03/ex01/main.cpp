#include "ClapTrap.hpp"

int	main()
{
	ClapTrap clap_trap("Sara");

	clap_trap.attack("Enemy");
	clap_trap.takeDamage(3);
	clap_trap.beRepaired(5);
	clap_trap.takeDamage(6);
	clap_trap.takeDamage(9);
	clap_trap.attack("Another enemy");
	clap_trap.beRepaired(2);
	return (0);
}
