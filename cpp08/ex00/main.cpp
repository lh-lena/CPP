
#include "easyfind.hpp"
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector
#include <deque>        // std::deque
#include <list>         // std::list

// Sequence Containers (vector, deque, list) -  
// store objects of the same type in a linear arrangement

int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 5; i++)
        vec.push_back(i * 2);
    vec.push_back(3);
    try
    {
        std::vector<int>::iterator res = easyfind(vec, 4);
        std::cout << "Found element: " << *res << std::endl;
    }
    catch (NotFoundException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::deque<int> d;
    for (int i = 0; i < 5; i++)
        d.push_back(i * 5);

    try
    {
        std::deque<int>::iterator res = easyfind(d, 5);
        std::cout << "Found element: " << *res << std::endl;
    }
    catch (NotFoundException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::list<int> l;
    for (int i = 0; i < 5; i++)
        l.push_back(i * 3);
    try
    {
        std::list<int>::iterator res = easyfind(l, 9);
        std::cout << "Found element: " << *res << std::endl;
    }
    catch (NotFoundException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}