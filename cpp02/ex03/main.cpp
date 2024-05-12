/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:19:00 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/13 01:24:38 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a(15, 0);
	Point b(0, 15);
	Point c(0, 0);
	Point p1(2, 3);
	Point p2(2, 3);
	Point p3(2, 3);

	
	// std::cout << "point a = " << a << std::endl;
	// std::cout << "point b = " << b << std::endl;
	// std::cout << "point c = " << c << std::endl;

	// std::cout << "point p1 = " << p1 << std::endl;
	// std::cout << "p1 in triangle:\t\t" << bsp(a,b,c,p1) << std::endl;

	
	return 0;
}

/**
 * Implement a function which indicates whether a point is inside of a triangle or not.
 */