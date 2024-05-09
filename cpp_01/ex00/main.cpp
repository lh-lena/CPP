/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:45:05 by ohladkov          #+#    #+#             */
/*   Updated: 2024/03/21 11:09:55 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* zombie = newZombie("Bob");
    zombie->announce();
    randomChump("Jim");
    
    delete zombie;
    return (0);
}
