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
    void                        displaySortingTime(const std::string &containerName, double takenTime) const;
    template<typename T> void   printContainer(const T &container) const;
    template<typename T> void   fillContainer(T &container, int size, char **args);
    template<typename T> void   mergeInsertionSort(T &container, int low, int high);
    void   insertionSort(std::vector<unsigned int> &container, int low, int high);
    void   insertionSort(std::list<unsigned int> &container, int low, int high);

private:
    int  _size;
};

unsigned int    ft_stouint(char *str);

#endif