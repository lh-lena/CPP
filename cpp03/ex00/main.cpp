
#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap    A("A");
    ClapTrap B("B");

    A.takeDamage(9);
    A.attack("B");
    B.takeDamage(10);
    A.beRepaired(2);
    std::cout << A << std::endl;
}