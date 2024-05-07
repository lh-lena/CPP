/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomeChump.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:46:48 by ohladkov          #+#    #+#             */
/*   Updated: 2024/03/21 08:46:51 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie newZombie(name);
    newZombie.announce();
}

