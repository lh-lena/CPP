/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:57:21 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/16 10:57:21 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main(void)
{
	ClapTrap	bob = ClapTrap("Bob");
	FragTrap	bib = FragTrap("Bib");

	bob.attack("a worm");
	bob.takeDamage(9);


	bib.attack("a human");
	bib.highFivesGuys();
	bib.beRepaired(5);
}
