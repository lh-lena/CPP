/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:19:54 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/22 23:09:13 by ohladkov         ###   ########.fr       */
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
# include <cmath>
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

/*
To thoroughly test the functionality and error handling of the program based on the specifications given, we should consider various types of inputs that could potentially cause errors or edge cases. Here are some examples of inputs to test the program:

1. **Valid Inputs**:
   - `42.0f`
   - `-42.5f`
   - `0.0`
   - `-inf`
   - `+inff`
   - `nan`
   - `4.2`
   - `'*'` (char input)

2. **Invalid Inputs**:
   - `42.f` (invalid float literal format)
   - `42.` (invalid float literal format)
   - `abc` (non-numeric input)
   - `42` (missing suffix for float literal)
   - `*` (non-printable character for char)
   - `256` (out of range for char)
   - `2147483648` (out of range for int)
   - `1e100` (float value out of range)
   - `-nan` (invalid format for NaN)

3. **Edge Cases**:
   - `0.0f` (float literal with zero)
   - `-0.0` (negative zero double)
   - `-inf` and `+inf` (negative and positive infinity)
   - `nan` and `nanf` (NaN representation)

By testing these inputs, you can verify that the program correctly handles:
- Parsing valid float literals with and without 'f' suffix.
- Conversion to char, ensuring printable characters are correctly displayed and non-printable characters are handled with an asterisk '*'.
- Conversion to int, checking for overflow/underflow.
- Handling special floating-point literals like infinity (`inf`, `+inf`, `-inf`) and NaN (`nan`, `nanf`).
- Proper error handling and informative messages for invalid inputs or cases where conversion is not possible (e.g., non-numeric input, out of range values).

Testing these scenarios will help ensure that the program behaves as expected and handles a wide range of inputs effectively according to the given specifications.
*/