/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:05:11 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/12 15:49:55 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
public:
    Fixed   ();
    Fixed   (const int nbr);
    Fixed   (const float nbr);
    Fixed   (const Fixed& copyCostructor);
    Fixed& operator= (const Fixed& fixed);
    ~Fixed  ( void );

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    float   toFloat( void ) const;
    int     toInt( void ) const;

private:
    int                 _value;
    static const int    _fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif

/**
 * Add the following public constructors and public member functions to your class:
• A constructor that takes a constant integer as a parameter.
It converts it to the corresponding fixed-point value. The fractional bits value is
initialized to 8 like in exercise 00.
• A constructor that takes a constant floating-point number as a parameter.
It converts it to the corresponding fixed-point value. The fractional bits value is
initialized to 8 like in exercise 00.
• A member function float toFloat( void ) const;
that converts the fixed-point value to a floating-point value.
• A member function int toInt( void ) const;
that converts the fixed-point value to an integer value.
And add the following function to the Fixed class files:
• An overload of the insertion («) operator that inserts a floating-point representation
of the fixed-point number into the output stream object passed as parameter.
 */