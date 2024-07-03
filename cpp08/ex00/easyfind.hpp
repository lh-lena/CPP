#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>

class NotFoundException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "Element not found!";
    }
};

template <typename T>
typename T::iterator easyfind(T &container, int i);

#include "easyfind.tpp"

#endif