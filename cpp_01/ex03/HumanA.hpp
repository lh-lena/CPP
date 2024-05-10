/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:35:37 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/10 12:35:47 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA {
public:
	HumanA (const std::string& nm, Weapon& weaponA);
	~HumanA ( void );

	void	attack();
private:
	std::string _name;
	Weapon& _weapon;
};

#endif
