/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:02:54 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/18 23:02:05 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

	public:

		Animal();
		Animal( Animal const & src );
		virtual ~Animal();

		Animal &		operator=( Animal const & rhs );
		virtual	void	makeSound() const;
		std::string		getType() const;
		void			setType(std::string type);

	protected:
		std::string type;
};

std::ostream &			operator<<( std::ostream & o, Animal const & i );

/**
 * Use the virtual keyword in the base class to enable dynamic binding.
 * Override the virtual functions in derived classes.
 * Ensure that the base class destructor is virtual to handle proper cleanup.
 */

#endif /* ********************************************************** ANIMAL_H */