/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:02:44 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/22 11:48:12 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	/**
	 * An abstract class type object cannot be created. 
	 * To abstract class types, however, you can use pointers 
	 * and references.
	*/

	// AAnimal ams;
	// ams.makeSound();
	// AAnimal* meta = new AAnimal(); // This will now give a compilation error because AAnimal is abstract

	int n = 3;
	AAnimal* ams[n];
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			ams[i] = new Dog();
		else
			ams[i] = new Cat();
	}

	for(int i = 0; i < n; i++)
	{
		ams[i]->makeSound();
	}
	for(int i = 0; i < n; i++)
	{
		delete ams[i];
	}

    return 0;
}

