
#include "PmergeMe.hpp"

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
        this->_list = other._list;
        this->_vector = other._vector;
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
    std::cout
    << "Time to process a range of "
    << this->getSize() 
    << " elements with " + containerName + " : "
    << takenTime 
    << " us"
    << std::endl;
}

template<typename T> void   PmergeMe::displayContainer(const T &container) const
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

void    PmergeMe::fillVector(int size, char **args)
{
    for (int i = 0; i < size; ++i)
    {
        this->_vector.push_back(ft_stouint(args[i]));
    }
}

void    PmergeMe::fillList(int size, char **args)
{
    for (int i = 0; i < size; ++i)
    {
        this->_list.push_back(ft_stouint(args[i]));
    }
}

void    PmergeMe::sortVector()
{
    
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

std::vector<unsigned int>   PmergeMe::getVector() const
{
    return(this->_vector);
}

std::list<unsigned int>   PmergeMe::getList() const
{
    return(this->_list);
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

template void PmergeMe::displayContainer(const std::vector<unsigned int> &container) const;
template void PmergeMe::displayContainer(const std::list<unsigned int> &container) const;
