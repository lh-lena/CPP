/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:29:56 by ohladkov          #+#    #+#             */
/*   Updated: 2024/07/11 21:16:09 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    std::srand (( std::time(0)));
    Span sp = Span(5);

    sp.addNumber(17);
    sp.addNumber(3);
    sp.addNumber(9);
    sp.addNumber(6);
    sp.addNumber(11);
    try
    {
        sp.addNumber(11);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << std::endl;

    sp.print();
    return (0);
}