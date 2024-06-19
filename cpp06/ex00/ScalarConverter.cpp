/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:51:18 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/19 16:32:27 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

enum LiteralType { CHAR, INT, FLOAT, DOUBLE, INVALID };

// Function to detect the type of the literal
LiteralType detectType(const std::string& literal)
{
    std::stringstream ss(literal);

    int i = 0;
    // for (unsigned long i = 0; i < literal.length(); i++)
    // {
    //     if (isprint(literal[i]))
    //         return (INVALID);
    // }
    ss >> i;
    if (ss.fail()) {
        std::cerr << "Invalid int literal" << std::endl;
        return (INVALID);
    }
    // if (isprint(i) == 0)
    //    return (INVALID);
    if (literal.length() == 1 && std::isalpha(literal[0]))
        return (CHAR);

    return (INT);
}

void    ScalarConverter::convert(std::string& value)
{
    LiteralType type = detectType(value);
    std::stringstream ss(value);

    float   f = 0.0;
    int     i = 0;
    char    c = 0;
    double  d = 0.0;

    switch (type)
    {
        case (CHAR):
        {
            ss >> c;
            if (ss.fail()) {
                std::cerr << "Invalid char literal" << std::endl;
            }
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            break ;
        }
        case (INT):
        {
            ss >> i;
            if (ss.fail()) {
                std::cerr << "Invalid int literal" << std::endl;
            }
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            break ;
        }        
        case (FLOAT):
        {
            ss >> f;
            if (ss.fail()) {
                std::cerr << "Invalid float literal" << std::endl;
            }
            i = static_cast<int>(f);
            c = static_cast<char>(f);
            d = static_cast<double>(f);
        }
        case (DOUBLE):
            break ;

        case (INVALID):
            std::cout << "Invalid argument: " << value << std::endl;
            break ;
    }
    if (type != INVALID)
    {
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << std::endl;
        std::cout << "double: " << d << std::endl;
    }
}
