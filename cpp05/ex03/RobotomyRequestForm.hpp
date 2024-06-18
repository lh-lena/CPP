/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:39:59 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/18 18:06:49 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>
#include <cstdlib> // for srand and rand
#include <ctime> // for time

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

private:
	RobotomyRequestForm();
	std::string _target;
	void	performAction() const;
};

#endif // ROBOTOMYREQUESTFORM_HPP
