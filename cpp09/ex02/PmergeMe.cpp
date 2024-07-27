
#include "PmergeMe.hpp"

template void PmergeMe::printContainer(const std::vector<unsigned int> &container) const;
template void PmergeMe::printContainer(const std::list<unsigned int> &container) const;
template void PmergeMe::fillContainer(std::vector<unsigned int> &container, int size, char **args);
template void PmergeMe::fillContainer(std::list<unsigned int> &container, int size, char **args);
template void PmergeMe::mergeInsertionSort(std::list<unsigned int> &container, int start, int end);
template void PmergeMe::mergeInsertionSort(std::vector<unsigned int> &container, int start, int end);

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
    << " µs"
    << std::endl;
}

template<typename T> void   PmergeMe::printContainer(const T &container) const
{
    typename T::const_iterator it;
    unsigned int size = container.size();
    it = container.begin();
    std::cout << "After:   ";
    if (size < 15)
    {
        for (; it != container.end(); ++it)
            std::cout << *it << " ";
    }
    else
    {
        for (int i = 0 ; i < 5; ++i, ++it)
            std::cout << *it << " ";
        std::cout << "[...] ";
        std::advance(it, size - 10);
        for (int i = 0 ; i < 4; i++, it++)
            std::cout << *it << " ";
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
    std::list<unsigned int>::iterator itLow = container.begin();
    std::list<unsigned int>::iterator itHigh = container.begin();
    unsigned int val;
    std::list<unsigned int>::iterator it;
    std::list<unsigned int>::iterator tmp;
    std::list<unsigned int>::iterator tmpPrev;

    std::advance(itLow, low);
    std::advance(itHigh, high + 1);
    for (it = itLow; it != itHigh; it++)
    {
        val = *it;
        tmp = it;
        tmpPrev = tmp;
        if (tmp != itLow)
            tmpPrev--;
        while (tmp != itLow && *tmpPrev > val)
        {
            *tmp = *tmpPrev;
            tmp = tmpPrev;
            tmpPrev = tmp;
            if (tmp != itLow)
                tmpPrev--;
        }
        *tmp = val;
    }
}


void   PmergeMe::insertionSort(std::vector<unsigned int> &container, int low, int high)
{
    std::vector<unsigned int>::value_type val;
    int t;

    for (int i = low + 1; i <= high; i++)
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

void    PmergeMe::merge(std::list<unsigned int> &list, int const left, int const mid, int const right)
{
    std::list<unsigned int>::iterator itRightArr;
    std::list<unsigned int>::iterator itLeftArr;
    std::list<unsigned int>::iterator itLeft;
    std::list<unsigned int>::iterator itRight;
    std::list<unsigned int>::iterator itList;
    std::list<unsigned int> leftArr;
    std::list<unsigned int> rightArr;

    itList = list.begin();
    std::advance(itList, left);
    int leftMaxSize = mid - left + 1;
    int rightMaxSize = right - mid;
    itLeft = itList;
    for(int i = 0; i < leftMaxSize; i++, itLeft++)
        leftArr.push_back(*itLeft);
    itRight = itLeft;
    for(int i = 0; i < rightMaxSize; i++, itRight++)
        rightArr.push_back(*itRight);
    itLeftArr = leftArr.begin();
    itRightArr = rightArr.begin();
    while (itLeftArr != leftArr.end() && itRightArr != rightArr.end())
    {
        if (*itLeftArr <= *itRightArr)
        {
            *itList = *itLeftArr;
            itLeftArr++;
        }
        else
        {
            *itList = *itRightArr;
            itRightArr++;
        }
        itList++;
    }
    for (; itLeftArr != leftArr.end(); itList++, itLeftArr++)
        *itList = *itLeftArr;
    for (; itRightArr != rightArr.end(); itList++, itRightArr++)
        *itList = *itRightArr;
}

void    PmergeMe::merge(std::vector<unsigned int> &arr, int const left, int const mid, int const right)
{
    int subArrLeft = mid - left + 1;
    int subArrRight = right - mid;

    std::vector<unsigned int> leftArr(subArrLeft);
    std::vector<unsigned int> rightArr(subArrRight);
    for(int i = 0; i < subArrLeft; i++)
        leftArr[i] = arr[left + i];
    for(int j = 0; j < subArrRight; j++)
        rightArr[j] = arr[mid + 1 + j];
    int i = 0;
    int j = 0;
    int l = left;
    while (i < subArrLeft && j < subArrRight)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[l] = leftArr[i];
            i++;
        }
        else
        {
            arr[l] = rightArr[j];
            j++;
        }
        l++;
    }
    for (; i < subArrLeft; i++, l++)
        arr[l] = leftArr[i];
    for (; j < subArrRight; l++, j++)
        arr[l] = rightArr[j];
}

template<typename T> void   PmergeMe::mergeInsertionSort(T &container, int begin, int end)
{
    const int threshold = 16;
    int size = container.size();
    int mid;

    if (begin < 0 || end >= size || size == 0)
        throw PmergeMe::PmergeMeException("Error\nIndex out of bounds or no elements");
    if (begin < end)
    {
        if (end - begin + 1 < threshold)
        {
            insertionSort(container, begin, end);
        }
        else
        {
            mid = begin + (end - begin) / 2;
            mergeInsertionSort(container, begin, mid);
            mergeInsertionSort(container, mid + 1, end);
            merge(container, begin, mid, end);
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
