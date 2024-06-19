/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:19:54 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/19 15:37:49 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cctype>
# include <string>
# include <sstream>

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