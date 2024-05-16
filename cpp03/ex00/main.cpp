/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:58:14 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/16 10:58:17 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap    A("A");
    ClapTrap B("B");

    A.takeDamage(9);
    A.attack("B");
    B.takeDamage(10);
    A.beRepaired(2);
    std::cout << A << std::endl;
}
