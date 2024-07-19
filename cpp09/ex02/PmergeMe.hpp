#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <iomanip>
# include <limits>
# include <cmath>
# include <iterator>
# include <vector>
# include <list>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    class PmergeMeException : public std::exception
    {
    public:
        PmergeMeException(const std::string& msg);
        const char *what() const throw();
        ~PmergeMeException() throw();
    private:
        std::string _msg;
    };

    void    setSize(int i);
    int     getSize( void );
    template<typename T> void   displaySortedSequence(T container);
    void    displaySortingTime(const std::string &containerName, double takenTime);

private:
    int        _size;
    std::vector<int>    _vector;
    std::list<int>      _list;
};

#endif