/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:19:00 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/13 15:16:14 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);
// doesn't work
int main( void ) {
	Point a(15, 0);
	Point b(0, 15);
	Point c(0, 0);
	Point p1(2, 3);
	Point p2(1, 1);
	Point p3(17, 3);

	std::cout << "point a = " << a << std::endl;
	std::cout << "point b = " << b << std::endl;
	std::cout << "point c = " << c << std::endl;

	std::cout << "point p1 = " << p1 << std::endl;
	std::cout << "p1 in triangle:\t" << bsp(a,b,c,p1) << std::endl;

	std::cout << "point p2 = " << p2 << std::endl;
	std::cout << "p2 in triangle:\t" << bsp(a,b,c,p2) << std::endl;

	std::cout << "point p3 = " << p3 << std::endl;
	std::cout << "p3 in triangle:\t" << bsp(a,b,c,p3) << std::endl;

	
	return 0;
}

/**
 * Implement a function which indicates whether a point is inside of a triangle or not.
 */