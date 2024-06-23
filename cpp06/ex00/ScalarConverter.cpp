/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:51:18 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/23 15:42:07 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

enum LiteralType { CHAR, INT, FLOAT, DOUBLE, INVALID };
LiteralType detectType(std::string& str);
bool isFloatLimits(const std::string& str);
bool isDoubleLimits(const std::string& str);
void handleFloatLimits(const std::string& str, float &f);
void handleDoubleLimits(const std::string& str, double &d);

void    ScalarConverter::convert(std::string& value)
{
    LiteralType type = detectType(value);
    std::stringstream ss(value);
    int n;

    float   f = 0.0;
    int     i = 0;
    char    c = 0;
    double  d = 0.0;
    if (value.find(".") > value.length())
        n = 1;
    else
        n = value.length() - 1 - value.find(".");
    switch (type)
    {
        case (CHAR):
        {
            ss >> c;
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            break ;
        }
        case (INT):
        {
            ss >> i;
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            break ;
        }
        case (FLOAT):
        {
            ss >> f;
            if (ss.fail())
                handleFloatLimits(value, f);
            i = static_cast<int>(f);
            c = static_cast<char>(f);
            d = static_cast<double>(f);
            break ;
        }
        case (DOUBLE):
        {
            ss >> d;
            if (ss.fail())
                handleDoubleLimits(value, d);
            i = static_cast<int>(d);
            c = static_cast<char>(d);
            f = static_cast<double>(d);
            break ;
        }
        case (INVALID):
            std::cout << "Invalid argument: \"" << value << "\"" << std::endl;
            break ;
    }
    if (type != INVALID)
    {
        if (isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else if (std::isinf(f) || std::isnan(f) || i < std::numeric_limits<char>::min() \
            || i > std::numeric_limits<char>::max())
            std::cout << "char: impossible" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
            std::cout << "int: " << i << std::endl;
        else
            std::cout << "int: " << "impossible" << std::endl;
        std::cout << std::fixed << std::setprecision(n);
        std::cout << "float: " << f  << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
}

// Function to detect the type of the literal
LiteralType detectType(std::string& str)
{
    std::stringstream   ss(str);
    std::size_t         pos;
    int                 intVal;

    ss >> intVal;
    if (ss.eof() && !ss.fail())
        return (INT);
    if (str.length() == 1 && std::isprint(str[0]))
        return (CHAR);
    pos = str.find(".");
    if ((pos < str.length()) && (pos != (str.length() - 1)) && ((pos + 1) != str.find("f")) && ((pos + 1) != str.find("F")))
    {
        if (str[str.length() - 1] == 'f' || str[str.length() - 1] == 'f')
        {
            str.erase(str.length() - 1);
            return (FLOAT);
        }
        else
            return (DOUBLE);
    }
    if (isFloatLimits(str) == true)
        return (FLOAT);
    if (isDoubleLimits(str) == true)
        return (DOUBLE);
    return (INVALID);
}

bool isFloatLimits(const std::string& str)
{
    if (str == "+inff" || str == "inff")
        return (true);
    if (str == "-inff")
        return (true);
    if (str == "nanf")
        return (true);
    return (false);
}

bool isDoubleLimits(const std::string& str)
{
    if (str == "+inf" || str == "inf")
        return (true);
    if (str == "-inf")
        return (true);
    if (str == "nan")
        return (true);
    return (false);
}

void handleFloatLimits(const std::string& str, float &f)
{
    if (str == "+inff" || str == "inff")
        f = std::numeric_limits<float>::infinity();
    else if (str == "-inff")
        f = -std::numeric_limits<float>::infinity();
    else if (str == "nanf")
        f = std::numeric_limits<float>::quiet_NaN();
}

void handleDoubleLimits(const std::string& str, double &d)
{
    if (str == "+inf" || str == "inf")
        d = std::numeric_limits<double>::infinity();
    else if (str == "-inf")
        d = -std::numeric_limits<double>::infinity();
    else if (str == "nan")
        d = std::numeric_limits<double>::quiet_NaN();
}
