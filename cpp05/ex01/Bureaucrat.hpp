/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:05:10 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/17 17:30:28 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Form; // Forward declaration

class Bureaucrat {
public:

	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat();

	Bureaucrat(Bureaucrat const & src);
	Bureaucrat&	operator=(Bureaucrat const & src);

	void		increaseGrade( void );
	void		decreaseGrade( void );
	std::string	getName( void ) const ;
	int			getGrade( void ) const ;
	void		signForm(Form &form);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char * what () const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char * what () const throw();
	};

private:
	int							_grade;
	const std::string			_name;
	Bureaucrat(void);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src);

/*
	https://rollbar.com/blog/cpp-custom-exceptions/
	
*/
#endif // BUREAUCRAT_HPP