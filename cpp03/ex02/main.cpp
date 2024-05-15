
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main(void)
{
	ClapTrap	bob = ClapTrap("Bob");
	FragTrap	bib = FragTrap("Bib");

	bob.attack("a worm");
	bob.takeDamage(9);


	bib.attack("a human");
	bib.highFivesGuys();
	bib.beRepaired(5);
}
