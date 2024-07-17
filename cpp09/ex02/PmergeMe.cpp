
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

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
