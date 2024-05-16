/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:57:52 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/16 10:57:52 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

	public:

		ScavTrap();
		ScavTrap( std::string name);
		ScavTrap( ScavTrap const & src );
		~ScavTrap();
		ScavTrap&	operator=( ScavTrap const & src );
		void guardGate();
		
	private:

};

std::ostream &  operator<<( std::ostream & o, ScavTrap const & i );

#endif

/**
 * https://www.ibm.com/docs/en/zos/2.4.0?topic=reference-inheritance-c-only
 * Inheritance lets you include the names and definitions of another class's members as part of a new class. 
 * The class whose members you want to include in your new class is called a base class. 
 * Your new class is derived from the base class. 
 * The new class contains a subobject of the type of the base class.
 */