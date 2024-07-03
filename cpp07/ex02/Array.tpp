/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:42:39 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/30 13:36:37 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template <typename T>
Array<T>::Array(void) : _arr(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    _arr = new T[n];
}

template <typename T>
Array<T>::Array(Array const &src) : _arr(NULL), _size(src._size)
{
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

template <typename T>
Array<T>::~Array()
{
    delete[] _arr;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

template <typename T>
Array<T> &Array<T>::operator=(Array const &src)
{
    if (this != &src)
    {
        // std::cout << "Overloat operator = called" << std::endl;
        delete[] _arr;
        _size = src._size;
        if (src._arr)
        {
            _arr = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _arr[i] = src._arr[i];
        }
        else
            _arr = NULL;
    }
    return (*this);
}

template <typename T>
const T &Array<T>::operator[](int idx) const
{
    if (idx < 0 || static_cast<unsigned int>(idx) >= _size)
        throw std::out_of_range("Index out of bounds");
    return (_arr[idx]);
}

template <typename T>
T &Array<T>::operator[](int idx)
{
    if (idx < 0 || static_cast<unsigned int>(idx) >= _size)
        throw std::out_of_range("Index out of bounds");
    return (_arr[idx]);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}
