/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:59:53 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/23 13:19:37 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    Base* basePtr = generate();

    std::cout << "Identify by pointer: ";
    identify(basePtr);

    std::cout << "Identify by reference: ";
    identify(*basePtr);

    delete basePtr;
    return 0;
}