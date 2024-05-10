/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:05:11 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/10 18:33:19 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:
    Fixed   ();
    Fixed   (Fixed& copyCostractor);
    Fixed& operator=(const Fixed&);
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