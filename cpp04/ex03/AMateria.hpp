/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:25:50 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/22 12:44:57 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{

	public:

		AMateria();
		AMateria(std::string const & type);
		AMateria( AMateria const & src );
		virtual ~AMateria();

		AMateria &				operator=( AMateria const & rhs );

		std::string const & 	getType() const;
		virtual AMateria* 		clone() const = 0;
		virtual void 			use(ICharacter& target);

	protected:
		std::string		_type;

};

#endif /* ******************************************************** AMATERIA_H */