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
time_t now(void)
{
   struct timeval tv;
//    double retval=0;
   gettimeofday(&tv, NULL);
//    retval=tv.tv_usec;
//    retval+= (double)tv.tv_usec / 1000000.;
   return tv.tv_sec;
}

int main(int ac, char **av)
{
    std::clock_t startVec, endVec, startList;
    PmergeMe pm;
    std::list<unsigned int>      list;
    std::vector<unsigned int>    vec;
    int size = ac -1;

    if (ac == 1)
        return (std::cerr << "Usage: " << av[0] <<  " [. . . numbers]" << std::endl, 1);
    pm.setSize(size);
    std::ios_base::sync_with_stdio(false);
    try
    {
        inputVefication(size, av + 1);
        displayUnsortedSequence(size, (av + 1));
        startVec = std::clock();
        pm.fillContainer(vec, size, av + 1);
        pm.mergeInsertionSort(vec, 0, vec.size() - 1);
        endVec = std::clock();
        pm.printContainer(vec);
        startList = static_cast<double>(clock());
        pm.fillContainer(list, size, av + 1);
        pm.mergeInsertionSort(list, 0, list.size() - 1);
        startList = static_cast<double>(clock()) - startList;
        pm.printContainer(list);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (-1);
    }
    // double elapsed_time = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double timeVec = (static_cast<double>(startVec) - static_cast<double>(endVec)) / (CLOCKS_PER_SEC);
    double timeList = startList / static_cast<double>(CLOCKS_PER_SEC);
    double timeInMicroseconds = 1 / (timeVec * 1e6);
    pm.displaySortingTime("std::vector<unsigned int>", timeInMicroseconds);
    pm.displaySortingTime("std::list<unsigned int>  ", timeList);
    return (0);
}
