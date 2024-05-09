#include "Harl.hpp"

int main(int av, char **ac)
{
    if (av != 2)
        return (std::cout << "use DEBUG, INFO, WARNING or ERROR as parameter" << std::endl, 1);
    Harl harl;

    harl.complain(ac[1]);
    
    return 0;
}
/*
There is some stuff that can be improved, the ex06 is implemented in a way that doesn't use the full potential of the switch statement, and sadly the weapons in ex03 do not return a const reference. Also, be careful with HumanB attacking without a weapon because it may sigsegv. Congrats!*/
