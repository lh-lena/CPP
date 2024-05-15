
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main(void)
{
    ClapTrap	bob = ClapTrap("Bob");
    ScavTrap	bib = ScavTrap("Bib");

    bob.attack("a worm");
    bob.takeDamage(9);

    bib.attack("a human");
    bib.guardGate();
    bib.beRepaired(5);
}