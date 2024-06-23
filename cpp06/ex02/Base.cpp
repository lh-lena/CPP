/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:38:11 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/23 14:03:15 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base * generate(void)
{
    std::srand(std::time(0));
    int randomValue = std::rand() % 3;
    switch (randomValue)
    {
        case 0:
            std::cout << "Actual type: A" << std::endl; 
            return (new A());
        case 1:
            std::cout << "Actual type: B" << std::endl; 
            return (new B());
        case 2:
            std::cout << "Actual type: C" << std::endl; 
            return (new C());
    }
    return (NULL);    
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cerr << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (const std::exception&) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch (const std::exception&) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (const std::exception&) {}
}
