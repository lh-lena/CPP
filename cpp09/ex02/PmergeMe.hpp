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
        virtual ~PmergeMeException() throw();
        virtual const char *what() const throw();
    private:
        std::string _msg;
    };

    void                        setSize(int i);
    int                         getSize( void ) const;
    template<typename T> void   displayContainer(const T &container) const;
    void                        displaySortingTime(const std::string &containerName, double takenTime) const;
    void                        fillVector(int size, char **args);
    void                        fillList(int size, char **args);
    void                        sortVector();
    void                        sortList();
    std::vector<unsigned int>   getVector() const;
    std::list<unsigned int>     getList() const;

private:
    int                          _size;
    std::vector<unsigned int>    _vector;
    std::list<unsigned int>      _list;
};

unsigned int    ft_stouint(char *str);

#endif