/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:30:41 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/10 12:30:42 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
public:
    Zombie();
	~Zombie ( void );
	void announce( void );
    void setName( std::string name);

private:
    std::string _name;
};

Zombie* zombieHorde( int N, std::string name );
#endif
