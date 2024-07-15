#include <iostream>
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:29:35 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/10 12:29:48 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << &string << "\n";
	std::cout << stringPTR << "\n";
	std::cout << &stringREF << "\n";

	std::cout << string << "\n";
	std::cout << *stringPTR << "\n";
	std::cout << stringREF << "\n";
}

/*
	- reference must be initialized with an existing object and cannot be null
	- once initialized, a reference cannot be changed to refer to a different object
*/