/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:19:54 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/22 22:49:30 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cctype>
# include <string>
# include <sstream>
# include <iomanip>
# include <limits>
#include <cstdlib>
#include <cstring>

class ScalarConverter
{
public:
	static void convert(std::string& value);
private:
	ScalarConverter( void );
};

#endif