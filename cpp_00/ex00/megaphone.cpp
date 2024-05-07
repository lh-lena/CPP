/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:45:46 by ohladkov          #+#    #+#             */
/*   Updated: 2024/03/29 09:49:25 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
		return (1);
	}
	for (int i = 1; i < ac; i++)
	{
		std::string str = av[i];
		size_t len = str.length();
		for (size_t j = 0; j < len; j++)
		{
			str[j] = std::toupper(av[i][j]);
		}
		std::cout << str;
	}
	std::cout << "\n";
	return (0);
}
