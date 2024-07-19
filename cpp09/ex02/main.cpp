#include "PmergeMe.hpp"

void    displayUnsortedSequence(int ac, char **av)
{
    std::cout << "Before:  ";
    for (int i = 0; i < ac; ++i)
    {
        std::cout << av[i] << " ";
    }
    std::cout << std::endl;
}

void    processInput(int ac, char **av)
{
    int num;
    for (int i = 0; i < ac; i++)
    {
        std::istringstream iss(av[i]);
        iss >> num;
        if (iss.fail() || num < 0)
            throw PmergeMe::PmergeMeException("Error");
        // std::cout << num << " ";
    }
}

int main(int ac, char **av)
{
    time_t start, end;

    if (ac <= 1 || av[1] == '\0')
        return (std::cerr << "Error" << std::endl, -1);
    PmergeMe pm;
    time(&start);
    // unsync the I/O of C and C++. 
    // std::ios_base::sync_with_stdio(false); 
    pm.setSize(ac - 1);
    displayUnsortedSequence(ac - 1, (av + 1));
    try
    {
        processInput(ac - 1, av + 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    time(&end);
    double time_taken = double(end - start);
    std::cout << "Time taken by program is : " << std::fixed 
        << time_taken << std::setprecision(5); 
    std::cout << " sec " << std::endl; 
    return (0);
}