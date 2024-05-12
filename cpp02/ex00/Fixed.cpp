/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:05:26 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/12 15:49:55 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed () : _value(1) {
    std::cout << "Default constractor called" << std::endl;
    Fixed::setRawBits(_value);
}

Fixed::Fixed (const Fixed& copyConstructor) {
    std::cout << "Copy constructor called" << std::endl;
    // *this = copyConstructor;
    this->_value = copyConstructor.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _value = fixed. getRawBits();
    return (*this);
}

Fixed::~Fixed ( void ) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits( int const raw ) {
    this->_value = raw;
}
