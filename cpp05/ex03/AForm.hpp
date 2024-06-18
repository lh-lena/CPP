/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:41:20 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/18 17:56:33 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration

class AForm
{
public:

	AForm(const std::string& name, const int toSign, const int toExecute);
	virtual ~AForm();
	AForm(AForm const & src);
	AForm& operator=(AForm const & src);

	std::string		getName( void ) const;
	bool			getIsSigned( void ) const;
	int				getGradeToSign( void ) const;
	int				getGradeToExecute( void ) const;
	void			beSigned(const Bureaucrat & src);
	void			execute(Bureaucrat const & executor) const;
	virtual void performAction() const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		const char *what() const throw();
	};

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	AForm(void); 						// Disallow default construction
};

std::ostream	&operator<<(std::ostream &os, const AForm& src);

#endif // AFORM_HPP