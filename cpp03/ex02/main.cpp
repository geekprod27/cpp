#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main ( void )
{
	ClapTrap a("a");

	a.attack("b");
	a.takeDamage(9);
	a.attack("b");
	a.beRepaired(1);
	a.takeDamage(9);
	a.takeDamage(9);
	a.attack("d");
	a.beRepaired(100);

	FragTrap b("d");
	b.highFivesGuys();
}