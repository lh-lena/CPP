
#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap    instance("A");

    instance.takeDamage(11);
    instance.attack("B");
    instance.beRepaired(2);
}