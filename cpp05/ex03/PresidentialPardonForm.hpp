/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:41:29 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/18 18:06:51 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALFORM_HPP
# define PRESIDENTIALFORM_HPP

# include <fstream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

private:
	PresidentialPardonForm();
	std::string		_target;
	void	performAction() const;
};

#endif // PRESIDENTIALPARDONFORM_HPP