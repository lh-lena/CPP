/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:05:11 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/10 20:48:17 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:
    Fixed   ();
    Fixed   (const Fixed& copyCostructor);
    Fixed& operator= (const Fixed& fixed);
    ~Fixed  ( void );
    

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );

private:
    int                 _nbr;
    static const int    _bits = 8;
};

#endif

/**
 * A member function int getRawBits( void ) const;
that returns the raw value of the fixed-point value.
 * ◦ A member function void setRawBits( int const raw );
that sets the raw value of the fixed-point number.
 */