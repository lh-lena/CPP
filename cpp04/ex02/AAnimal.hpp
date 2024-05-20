/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:02:54 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/20 22:59:27 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>
# include <string>

class AAnimal
{

	public:

		AAnimal();
		AAnimal( AAnimal const & src );
		virtual ~AAnimal() = 0;

		AAnimal &		operator=( AAnimal const & rhs );
		virtual	void	makeSound() const = 0; //pure-specifie
		virtual std::string		getType() const;
		void			setType(std::string type);

	protected:
		std::string type;
};

std::ostream &			operator<<( std::ostream & o, AAnimal const & i );

/**
 * Use the virtual keyword in the base class to enable dynamic binding.
 * Override the virtual functions in derived classes.
 * Ensure that the base class destructor is virtual to handle proper cleanup.
 */

#endif /* ********************************************************** AAnimal_H */