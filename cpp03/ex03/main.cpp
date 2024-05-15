
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main(void)
{
	DiamondTrap dt("Diamond");

	dt.attack("A");
    dt.whoAmI();           // Output: I am Diamond!
    dt.highFivesGuys();    // Output: Diamond: Positive high fives request!
    dt.guardGate();        // Output: Diamond: I am the gate guardian!
}