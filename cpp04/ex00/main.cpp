/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:02:44 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/16 19:37:21 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound();
//     j->makeSound();
//     meta->makeSound();
//     delete meta;
//     delete j;
//     delete i;
//     return 0;
// }

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void testCopyConstructor() {
    Dog original;
    Dog copy(original);  // Using copy constructor

    std::cout << "Original Dog: ";
    original.makeSound();
    std::cout << "Copied Dog: ";
    copy.makeSound();
}

void testAssignmentOperator() {
    Cat original;
    Cat assigned;
    assigned = original;  // Using assignment operator

    std::cout << "Original Cat: ";
    original.makeSound();
    std::cout << "Assigned Cat: ";
    assigned.makeSound();
}

void testPolymorphism() {
    Animal* animals[3];
    animals[0] = new Animal();
    animals[1] = new Dog();
    animals[2] = new Cat();

    for (int i = 0; i < 3; ++i) {
        animals[i]->makeSound();
        delete animals[i];
    }
}

void    testWrongCat() {
    const WrongAnimal* i = new WrongCat();
    std::cout << "Type: " << i->getType() << " " << std::endl;
    i->makeSound();
    delete i;
}

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    // std::cout << "\n\tTesting Copy Constructor:" << std::endl;
    // testCopyConstructor();

    // std::cout << "\n\tTesting Assignment Operator:" << std::endl;
    // testAssignmentOperator();

    // std::cout << "\n\tTesting Polymorphism:" << std::endl;
    // testPolymorphism();

    // std::cout << "\n\tTesting WrongCat class:" << std::endl;
    // testWrongCat();

    return 0;
}
