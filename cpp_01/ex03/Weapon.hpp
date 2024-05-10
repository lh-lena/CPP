/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:37:09 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/10 12:37:11 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon {
public:
	Weapon( void );
	Weapon (const std::string& str);
	~Weapon( void );

	const std::string& getType();
	void setType(const std::string& newType);
private:
	std::string type;
};

#endif
