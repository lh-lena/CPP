/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:51:18 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/22 22:48:02 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

enum LiteralType { CHAR, INT, FLOAT, DOUBLE, INVALID };

// Function to detect the type of the literal
LiteralType detectType(std::string& str)
{
    std::istringstream ss(str);

    int intVal;
    std::size_t pos;
    // for (unsigned long i = 0; i < str.length() - 1; i++)
    // {
    //     if (isprint(str[i])) {
    //         std::cerr << "1Not printable" << std::endl;
    //         return (INVALID);
    //     }
    // }
    ss >> intVal;
    pos = str.find(".");
    if (ss.eof() && !ss.fail() && pos == std::string::npos) {
        return (INT);
    }
    else
        std::cerr << "int fail" << std::endl;
    if (str.length() == 1 && std::isalpha(str[0]))
        return (CHAR);
    if (str.find(".") != str.npos)
    {
        if (!str.empty() && (str.back() == 'f' || str.back() == 'F')) {
            str.pop_back();
            return (FLOAT);
        }
        else
            return (DOUBLE);
    }
    return (INVALID);
}

void    ScalarConverter::convert(std::string& value)
{
    LiteralType type = detectType(value);
    std::istringstream ss(value);

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
            std::cerr << " int " << std::endl;
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
            std::cout << " float " << std::endl;
            i = static_cast<int>(f);
            c = static_cast<char>(f);
            d = static_cast<double>(f);
            break ;
        }
        case (DOUBLE):
        {
            ss >> d;
            if (ss.fail()) {
                std::cerr << "Invalid double literal" << std::endl;
            }
            std::cout << " double " << std::endl;
            i = static_cast<int>(d);
            c = static_cast<char>(d);
            f = static_cast<double>(d);
            break ;
        }
        case (INVALID):
            std::cout << "Invalid argument: " << value << std::endl;
            break ;
    }
    if (type != INVALID)
    {
        if (isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << i << std::endl;
        // Set precision for float and double outputs
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f  << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
}
