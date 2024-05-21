/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:02:44 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/21 17:18:46 by ohladkov         ###   ########.fr       */
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
	// Animal* ams[n];
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

	int n = 2;
	Animal* animals[n];
	std::cout << std::endl;

    // Create 5 Dog objects and 5 Cat objects
    for (int i = 0; i < (n / 2); ++i) {
        animals[i] = new Dog();
        animals[i + (n / 2)] = new Cat();
    }
	std::cout << std::endl;

    // Call makeSound() for each Animal
    for (int i = 0; i < n; ++i) {
        animals[i]->makeSound();
    }
	std::cout << std::endl;

    // Delete all Animal objects
    for (int i = 0; i < n; ++i) {
        delete animals[i];
    }
	std::cout << std::endl;

    // Test deep copy
    Dog dog1;
    dog1.setIdea(0, "Fetch the ball");
	std::cout << std::endl;
    Dog dog2 = dog1; // Copy constructor
    dog2.setIdea(0, "Chase the cat");

	std::cout << std::endl;

    std::cout << "Dog1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getIdea(0) << std::endl;

	std::string dog1addr = dog1.getIdea(0);
	std::string dog2addr = dog2.getIdea(0);
	std::cout << std::endl;

    std::cout << "Dog1 ADDR idea: " << &dog1addr << std::endl;
    std::cout << "Dog2 ADDR idea: " << &dog2addr << std::endl;
	std::cout << std::endl;


	return 0;
}