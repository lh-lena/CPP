/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:03:05 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/18 13:17:19 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{

	public:

		Dog();
		Dog( Dog const & src );
		~Dog();

		Dog &		operator=( Dog const & rhs );
		void	makeSound() const;

	private:
		Brain* 	_brain;
};

std::ostream &			operator<<( std::ostream & o, Dog const & i );

#endif /* ************************************************************* DOG_H */