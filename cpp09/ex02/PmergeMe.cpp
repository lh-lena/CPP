
#include "PmergeMe.hpp"

template void PmergeMe::printContainer(const std::vector<unsigned int> &container) const;
template void PmergeMe::printContainer(const std::list<unsigned int> &container) const;
template void PmergeMe::fillContainer(std::vector<unsigned int> &container, int size, char **args);
template void PmergeMe::fillContainer(std::list<unsigned int> &container, int size, char **args);
template void PmergeMe::mergeInsertionSort(std::list<unsigned int> &container, int start, int end);
template void PmergeMe::mergeInsertionSort(std::vector<unsigned int> &container, int start, int end);
// template void PmergeMe::insertionSort(std::list<unsigned int> &container, int low, int high);
// template void PmergeMe::insertionSort(std::vector<unsigned int> &container, int low, int high);

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->_size = other._size;
    }
    return (*this);
}

/*
** --------------------------------- EXCEPTION -------------------------------
*/

PmergeMe::PmergeMeException::PmergeMeException(const std::string &msg) : _msg(msg) {}

PmergeMe::PmergeMeException::~PmergeMeException() throw() {}

const char *PmergeMe::PmergeMeException::what() const throw()
{
    return (_msg.c_str());
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void    PmergeMe::displaySortingTime(const std::string& containerName, double takenTime) const
{
    int s = this->getSize();
    std::string element;
    element = (s == 1) ? "element" : "elements";
    std::cout
    << "Time to process a range of "
    << s << " " << element
    << " with " + containerName + " : "
    << std::fixed
    << takenTime 
    << std::setprecision(5)
    << " us"
    << std::endl;
}

template<typename T> void   PmergeMe::printContainer(const T &container) const
{
    typename T::const_iterator it;
    unsigned int size = container.size();
    it = container.begin();
    std::cout << "After:   ";
    if (size < 10)
    {
        for (; it != container.end(); ++it)
            std::cout << *it << " ";
    }
    else
    {
        for (int i = 0 ; i < 5; ++i, ++it)
            std::cout << *it << " ";
        std::cout << "[...] ";
    }
    std::cout << std::endl;
}

template<typename T> void    PmergeMe::fillContainer(T &container, int size, char **args)
{
    for (int i = 0; i < size; ++i)
    {
        container.push_back(ft_stouint(args[i]));
    }
}

void   PmergeMe::insertionSort(std::list<unsigned int> &container, int low, int high)
{
    std::list<unsigned int>::iterator itLow;
    std::list<unsigned int>::iterator itHigh;

    itLow = container.begin();
    itHigh = container.begin();
    std::advance(itLow, low);
    std::advance(itHigh, high);

    std::list<unsigned int>::iterator it;
    for (it = itLow; it != itHigh; ++it)
    {
        std::list<unsigned int>::value_type val = *it;
        std::list<unsigned int>::iterator t = it;
        while (t != itLow && *std::prev(t) > val)
        {
            *t = *(std::prev(t));
            --t;
        }
        *t = val;
    }
}


void   PmergeMe::insertionSort(std::vector<unsigned int> &container, int low, int high)
{
    std::vector<unsigned int>::value_type val;
    int t;

    for (int i = low + 1; i < high; i++)
    {
        val = container[i];
        t = i - 1;
        while (t >= low && container[t] > val)
        {
            container[t + 1] = container[t];
            --t;
        }
        container[t + 1] = val;
    }
}

template<typename T> void   PmergeMe::mergeInsertionSort(T &container, int begin, int end)
{
    const int threshold = 16;
    int size = container.size();
    if (begin < 0 || end > size || size == 0)
        throw PmergeMe::PmergeMeException("Error\nIndex out of bounds or no elements");
    if (begin < end)
    {
        if (end - begin + 1 <= threshold)
        {
            insertionSort(container, begin, end);
        }
        else
        {
            int mid = begin + (end - begin) / 2;

            mergeInsertionSort(container, begin, mid);
            mergeInsertionSort(container, mid + 1, end);

            // merge(container, low, mid, end);
            // std::cout << "here2 " << mid << std::endl;
        }
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void    PmergeMe::setSize(int i)
{
    _size = i;
    if (i < 0)
        throw PmergeMe::PmergeMeException("Error: invalid size");
}

int PmergeMe::getSize( void ) const
{
    return (_size);
}

/*
** --------------------------------- UTILITIES ---------------------------------
*/

unsigned int    ft_stouint(char *str)
{
    unsigned int num;
    std::stringstream ss(str);
    ss >> num;
    return (num);
}
