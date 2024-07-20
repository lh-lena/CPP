
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
    << " ms"
    << std::endl;
}

template<typename T> void   PmergeMe::displaySortedSequence(const T &container) const
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

void    PmergeMe::sortVector(int size, char **args)
{
    for (int i = 0; i < size; ++i)
    {
        this->_vector.push_back(ft_atouint(args[i]));
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

std::vector<unsigned int>   PmergeMe::getVector() const
{
    return(this->_vector);
}


unsigned int    ft_atouint(char *str)
{
    unsigned int num;
    std::stringstream ss(str);
    ss >> num;
    return (num);
}

template void PmergeMe::displaySortedSequence(const std::vector<unsigned int> &container) const;
