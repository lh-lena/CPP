/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:02:54 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/20 17:12:39 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{

	public:

		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		virtual ~WrongAnimal();

		WrongAnimal &		operator=( WrongAnimal const & rhs );
		void	makeSound() const;
		std::string		getType() const;
		void			setType(std::string type);

	protected:
		std::string type;
};

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i );

/**
 * Use the virtual keyword in the base class to enable dynamic binding.
 * Override the virtual functions in derived classes.
 * Ensure that the base class destructor is virtual to handle proper cleanup.
 */

#endif /* ********************************************************** ANIMAL_H */