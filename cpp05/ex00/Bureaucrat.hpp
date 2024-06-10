/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:05:10 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/10 19:18:01 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <string>
# include <iostream>


class Bureaucrat {
public:

	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat();

	void		increaseGrade( void );
	void		decreaseGrade( void );
	std::string	getName( void ) const ;
	int			getGrade( void ) const ;

private:
	int						_grade;
	const std::string		_name;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src);

#endif