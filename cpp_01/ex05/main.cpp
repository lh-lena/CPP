
#include "Harl.hpp"

int main()
{
    Harl harl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");

    return 0;
}

/**
 * https://www.ibm.com/docs/en/i/7.4?topic=only-pointers-members-c
*/