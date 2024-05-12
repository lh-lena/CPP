/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:05:26 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/12 23:56:03 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed () {
    std::cout << "Default constractor called" << std::endl;
    this->_value = 0;
}

// It converts it to the corresponding fixed-point value
Fixed::Fixed (const int nbr) {
    std::cout << "Int constractor called" << std::endl;
    setRawBits(nbr << this->_fractional_bits);
}

// It converts it to the corresponding fixed-point value
Fixed::Fixed (const float nbr) {
    std::cout << "Float constractor called" << std::endl;
    this->_value = roundf((nbr * (1 << this->_fractional_bits)));
}

Fixed::Fixed (const Fixed& copyConstructor) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copyConstructor;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->_value = fixed.getRawBits();
    return (*this);
}

Fixed::~Fixed ( void ) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    return (this->_value);
}

void Fixed::setRawBits( int const raw ) {
    this->_value = raw;
}

// that converts the fixed-point value to a floating-point value
float Fixed::toFloat( void ) const {
    return (static_cast<float>(this->_value) / static_cast<float>(1 << this->_fractional_bits));
}

// that converts the fixed-point value to an integer value
int Fixed::toInt( void ) const {
    return (this->_value >> this->_fractional_bits); // roundf(this->_value / (1 << this << __fractional_bits))
}

// Operator overload for <<
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat(); // Output as float
    return os;
}

/**
 * https://medium.com/@oumaimafisaoui/floating-and-fixed-point-representation-in-c-what-is-going-on-b71af54718a5
 * https://en.cppreference.com/w/cpp/language/operators
 */