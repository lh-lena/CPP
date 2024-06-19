/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:17:38 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/19 15:17:39 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return ((std::cerr << "Invalid input" << std::endl), -1);
    std::string input = av[1];
    ScalarConverter::convert(input);
    return (0);
}
