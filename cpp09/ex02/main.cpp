#include "PmergeMe.hpp"

void    displayUnsortedSequence(int size, char **args)
{
    std::cout << "Before:  ";
    if (size > 10)
    {
        for (int i = 0; i < 5; ++i)
            std::cout << args[i] << " ";
        std::cout << "[...]";
    }
    else
    {
        for (int i = 0; i < size; ++i)
            std::cout << args[i] << " ";
    }
    std::cout << std::endl;
}

void    inputVefication(int size, char **arg)
{
    int num;
    for (int i = 0; i < size; i++)
    {
        std::istringstream iss(arg[i]);
        iss >> num;
        if (iss.fail() || num < 0)
            throw PmergeMe::PmergeMeException("Error");
    }
}

int main(int ac, char **av)
{
    clock_t startVec, endVec;
    PmergeMe pm;

    if (ac == 1 || av[1] == '\0')
        return (std::cerr << "Usage: " << av[0] <<  " [. . . numbers]" << std::endl, 1);
    pm.setSize(ac - 1);
    try
    {
        inputVefication(ac - 1, av + 1);
        displayUnsortedSequence(ac - 1, (av + 1));
        startVec = clock();
        pm.sortVector(ac - 1, av + 1);
        endVec = clock();
        pm.displaySortedSequence(pm.getVector());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (-1);
    }
    double time_taken = double(endVec - startVec) * 10 / CLOCKS_PER_SEC;
    pm.displaySortingTime("std::vector<unsigned int>", time_taken);
    pm.displaySortingTime("std::list<unsigned int>  ", time_taken);
    return (0);
}