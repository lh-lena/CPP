/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:02:44 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/19 13:11:00 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Brain* id = new Brain();

    // std::cout << *id << std::endl;
    // delete id;
	// int n = 3;
	Animal ams;
	ams.makeSound();
	// for (int i = 0; i < n; i++)
	// {
	// 	if (i % 2 == 0)
	// 		ams[i] = new Dog();
	// 	else
	// 		ams[i] = new Cat();
	// }

	// for(int i = 0; i < n; i++)
	// {
	// 	ams[i]->makeSound();
	// }
	// for(int i = 0; i < n; i++)
	// {
	// 	delete ams[i];
	// }

	return 0;
}
