/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:18:31 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/21 19:37:36 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{

	public:

		Character();
		Character( std::string const & name );
		Character( Character const & src );
		~Character();

		Character &			operator=( Character const & rhs );
		std::string const & getName() const;
		void 				equip(AMateria* m);
		void 				unequip(int idx);
		void 				use(int idx, ICharacter& target);

	private:
		AMateria 		*inventory[4];
		std::string		_name;
};

#endif /* ******************************************************* CHARACTER_H */