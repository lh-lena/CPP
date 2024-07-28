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
#include <sys/time.h>
#include <ctime>

double now(void)
{
   struct timeval tv;
   double t;

   gettimeofday(&tv, 0);

   t = (double)tv.tv_sec + ((double)tv.tv_usec / 1E6);

   return t;
}

int main(int ac, char **av)
{
    clock_t startVec, endVec, startList, endList;
    PmergeMe pm;
    std::list<unsigned int>      list;
    std::vector<unsigned int>    vec;
    int size = ac -1;

    if (ac == 1)
        return (std::cerr << "Usage: " << av[0] <<  " [. . . numbers]" << std::endl, 1);
    pm.setSize(size);
    try
    {
        inputVefication(size, av + 1);
        displayUnsortedSequence(size, (av + 1));
        startVec = clock();
        pm.fillContainer(vec, size, av + 1);
        pm.mergeInsertionSort(vec, 0, vec.size() - 1);
        endVec = clock();
        pm.printContainer(vec);
        startList = clock();
        pm.fillContainer(list, size, av + 1);
        pm.mergeInsertionSort(list, 0, list.size() - 1);
        endList = clock();
        pm.printContainer(list);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (-1);
    }
    double timeVec = static_cast<double>(endVec - startVec) / (CLOCKS_PER_SEC / 100000.0);
    double timeList = static_cast<double>(endList - startList) / (CLOCKS_PER_SEC / 100000.0);
    pm.displaySortingTime("std::vector<unsigned int>", timeVec);
    pm.displaySortingTime("std::list<unsigned int>  ", timeList);
    return (0);
}
