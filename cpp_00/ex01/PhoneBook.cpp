/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:46:02 by ohladkov          #+#    #+#             */
/*   Updated: 2024/03/28 11:11:36 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook (void) {
	PhoneBook::idx = 0;
}

PhoneBook::~PhoneBook (void) {
	return ;
}

void PhoneBook::setContact(Contact& contact)
{
	if (this->idx < 8)
	{
		_contacts[this->idx] = contact;
		this->idx++;
	}
	else
	{
		this->idx = 0;
		setContact(contact);
	}
}

Contact PhoneBook::getContact(int i) const {
	return (_contacts[i]);
}

std::string PhoneBook::truncateString(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

void PhoneBook::displayContacts(void)
{
	std::cout << std::setw(10) << std::right << "Index" << " | "
	<< std::setw(10) << std::right << "First Name" << " | "
	<< std::setw(10) << std::right << "Last Name" << " | "
	<< std::setw(10) << std::right << "Nickname" << "\n";
	for (int i = 0; i < 8; i++) {
		std::cout << std::setw(10) << std::right << i + 1 << " | "
		<< std::setw(10) << std::right << this->truncateString(this->getContact(i).getFirstName()) << " | "
		<< std::setw(10) << std::right << this->truncateString(this->getContact(i).getLastName()) << " | "
		<< std::setw(10) << std::right << this->truncateString(this->getContact(i).getNickname()) << "\n";
	}
}

void	PhoneBook::searchContact(std::string str)
{
	int idx;
	std::stringstream ss(str);
	ss >> idx;
	if (ss.fail() || idx > 9 || idx < 1)
	{
		std::cout << "Error: invalid index" << "\n";
		return ;
	}
	if (idx - 1 > this->idx)
	{
		std::cout << "INFORMATION NOT FOUND. Use ADD to create a new contact" << "\n";
		return ;
	}
	std::cout << "First name: " << this->getContact(idx - 1).getFirstName() << "\n"
		<< "Last name: " << this->getContact(idx - 1).getLastName() << "\n"
		<< "Nickname: " << this->getContact(idx - 1).getNickname() << "\n"
		<< "Phone number: " << this->getContact(idx - 1).getPhoneNbr() << "\n"
		<< "The derties secret: " << this->getContact(idx - 1).getSecret() << "\n";
}
