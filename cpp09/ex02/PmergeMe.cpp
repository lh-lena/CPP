
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

void    PmergeMe::displaySortingTime(const std::string& containerName, double takenTime)
{
    std::cout
    << "Time to process a range of "
    << this->getSize() 
    << " elements with " + containerName + " : "
    << takenTime 
    << " us"
    << std::endl;
}

template<typename T> void   PmergeMe::displaySortedSequence(T container)
{
    typename T::const_iterator it;
    it = container.begin();
    while (it != container.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
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

int PmergeMe::getSize( void )
{
    return (_size);
}

