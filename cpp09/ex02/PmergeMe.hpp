#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>
# include <sstream>
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

private:
    unsigned int        _size;
    std::vector<int>    _vector;
    std::list<int>      _list;
};

#endif