/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:05:26 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/13 00:40:29 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed () {
    // std::cout << "Default constractor called" << std::endl;
    this->_value = 0;
}

// It converts it to the corresponding fixed-point value
Fixed::Fixed (const int nbr) {
    // std::cout << "Int constractor called" << std::endl;
    setRawBits(nbr << this->_fractional_bits);
}

// It converts it to the corresponding fixed-point value
Fixed::Fixed (const float nbr) {
    // std::cout << "Float constractor called" << std::endl;
    this->_value = roundf((nbr * (1 << this->_fractional_bits)));
}

Fixed::Fixed (const Fixed& copyConstructor) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = copyConstructor;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->_value = fixed.getRawBits();
    return (*this);
}

Fixed::~Fixed ( void ) {
    // std::cout << "Destructor called" << std::endl;
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
    return (this->_value >> this->_fractional_bits);
}

//  comparison operators: >, <, >=, <=, == and !=
bool	Fixed::operator> (Fixed const& fixed) const
{
	return (this->_value > fixed._value);
}

bool	Fixed::operator< (Fixed const& fixed) const
{
	return (this->_value < fixed._value);
}

bool	Fixed::operator>= (Fixed const& fixed) const
{
	return (this->_value >= fixed._value);
}

bool	Fixed::operator<= (Fixed const& fixed) const
{
	return (this->_value <= fixed._value);
}

bool	Fixed::operator==(Fixed const& fixed) const
{
	return (this->_value == fixed._value);
}

bool	Fixed::operator!= (Fixed const& fixed) const
{
	return (this->_value != fixed._value);
}

// arithmetic operators + - / *
Fixed Fixed::operator+ (const Fixed& fixed) const
{
    Fixed result = *this;
    result.setRawBits(result._value + fixed._value);
    return (result);
}

Fixed Fixed::operator- (const Fixed& fixed) const
{
    Fixed result = *this;
    result.setRawBits(result._value - fixed._value);
    return (result);
}

Fixed Fixed::operator* (const Fixed& fixed) const
{
    Fixed result = *this;
    result.setRawBits((result._value * fixed._value) >> this->_fractional_bits);
    return (result);
}

Fixed Fixed::operator/ (const Fixed& fixed) const
{
    Fixed result = *this;
    result.setRawBits((result._value << this->_fractional_bits) / fixed._value);
    return (result);
}

// prefix increment
Fixed& Fixed::operator++ ()
{
    this->_value++;
    return (*this);
}

// postfix increment
Fixed Fixed::operator++ (int)
{
    Fixed old(*this);
    this->_value++;
    return (old);
}
// prefix decrement
Fixed& Fixed::operator-- ()
{
    this->_value--;
    return (*this);
}

// postfix decrement
Fixed Fixed::operator-- (int)
{
    Fixed old(*this);
    this->_value--;
    return (old);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

// Operator overload for <<
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat(); // Output as float
    return os;
}

/**
 * https://medium.com/@oumaimafisaoui/floating-and-fixed-point-representation-in-c-what-is-going-on-b71af54718a5
 * https://en.cppreference.com/w/cpp/language/operators
 * http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html
 <a nonstatic member reference must be relative to a specific object> -> static
 int main() {
    Fixed::toFloat(); // Error: Non-static member reference must be relative to a specific object
    return 0;
}
int main() {
    Fixed f;
    float floatValue = f.toFloat(); // Now it's called on an instance of Fixed
    return 0;
}

 */