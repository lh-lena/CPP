/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:47:00 by ohladkov          #+#    #+#             */
/*   Updated: 2024/03/21 09:15:02 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <cstring>
# include <iostream>

class Zombie
{
public:

	Zombie ( std::string name );
	~Zombie ( void );
	void announce( void );

private:
		std::string _name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
#endif
