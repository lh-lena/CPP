/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:54:34 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/16 10:54:35 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{

	public:

		FragTrap();
		FragTrap( std::string name);
		FragTrap( FragTrap const & src );
		~FragTrap();

		FragTrap &		operator=( FragTrap const & src );
		void highFivesGuys(void);

};

std::ostream &			operator<<( std::ostream & o, FragTrap const & i );

#endif 