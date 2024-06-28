#ifndef ARRAY_HPP
# define ARRAY_HPP

template< typename T >class Array
{
public:
    Array( void );
    Array( unsigned int n );
    Array(Array const & src);
    ~Array();

    Array&  operator=(Array const & src);
    T&  operator[](int idx);
    const T&  operator[](int idx) const;

    unsigned int  size() const;

private:
    T*              _arr;
    unsigned int    _size;
};

#include "Array.tpp"

#endif