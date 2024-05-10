/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:05:26 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/10 18:33:13 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed () : _nbr(1) {
    std::cout << "Default constractor called" << std::endl;
    Fixed::setRawBits(_nbr);
}

Fixed::Fixed (Fixed& copyConstractor) {
    std::cout << "Copy constructor called" << std::endl;
    this->_nbr = copyConstractor._nbr;
}

Fixed& operator=(const Fixed&)
{
    
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Fixed::~Fixed ( void ) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_nbr);
}

void Fixed::setRawBits( int const raw ) {
    this->_nbr = raw;    
}
