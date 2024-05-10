/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:36:23 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/10 12:36:28 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
public:

	HumanB(const std::string& humanName);
	~HumanB ( void );
	void	attack();
	void 	setWeapon(Weapon& newWeapon);
private:
	std::string _name;
	Weapon* _weapon;
};

#endif 
