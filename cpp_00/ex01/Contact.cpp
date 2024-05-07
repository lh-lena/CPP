/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:46:02 by ohladkov          #+#    #+#             */
/*   Updated: 2024/03/19 14:39:26 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact (void) {}

Contact::~Contact (void) {
	return ;
}

void Contact::setFirstName(std::string& firstName) {
	_firstName = firstName;
}

void Contact::setLastName(std::string& lastName) {
	_lastName = lastName;
}

void Contact::setNickname(std::string& nickname) {
	_nickname = nickname;
}

void Contact::setPhoneNumber(std::string& phoneNumber) {
	_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string& darkestSecret) {
	_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName(void) const {
	return (_firstName);
}

std::string Contact::getLastName(void) const {
	return (_lastName);
}

std::string Contact::getNickname(void) const {
	return (_nickname);
}

std::string Contact::getPhoneNbr(void) const {
	return (_phoneNumber);
}

std::string Contact::getSecret(void) const {
	return (_darkestSecret);
}
