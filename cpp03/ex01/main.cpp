/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:57:58 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/16 10:57:59 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main(void)
{
    ClapTrap	bob = ClapTrap("Bob");
    ScavTrap	bib = ScavTrap("Bib");

    bob.attack("a worm");
    bob.takeDamage(9);

    bib.attack("a human");
    bib.guardGate();
    bib.beRepaired(5);
}
