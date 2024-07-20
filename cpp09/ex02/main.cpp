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
    clock_t startVec, startList;
    PmergeMe pm;

    if (ac == 1 || av[1] == '\0')
        return (std::cerr << "Usage: " << av[0] <<  " [. . . numbers]" << std::endl, 1);
    pm.setSize(ac - 1);
    try
    {
        inputVefication(ac - 1, av + 1);
        displayUnsortedSequence(ac - 1, (av + 1));
        startVec = clock();
        pm.fillVector(ac - 1, av + 1);
        pm.sortVector();
        startVec = clock() - startVec;
        pm.displayContainer(pm.getVector());
        startList = clock();
        pm.fillList(ac - 1, av + 1);
        // pm.sortList();
        startList = clock() - startList;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (-1);
    }
    double timeVec = (double)startVec * 10 / CLOCKS_PER_SEC;
    double timeList = (double)startList * 10 / CLOCKS_PER_SEC;
    pm.displaySortingTime("std::vector<unsigned int>", timeVec);
    pm.displaySortingTime("std::list<unsigned int>  ", timeList);
    return (0);
}