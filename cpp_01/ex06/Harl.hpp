/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:44:03 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/10 12:44:04 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl
{
public:
	Harl ();
	~Harl ();
	void complain( std::string level );

private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};

#endif
