#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac <= 1 || av[1] == '\0')
        return (std::cerr << "Error" << std::endl, -1);
    int num;

    for (int i = 1; i < ac; i++)
    {
        std::istringstream iss(av[i]);
        iss >> num;
        if (iss.fail() || num < 0)
            throw PmergeMe::PmergeMeException("Error");
        
    }
    return (0);
}