/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:46:02 by ohladkov          #+#    #+#             */
/*   Updated: 2024/03/28 11:06:47 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>

class Contact
{
public:
	Contact( void );
	~Contact( void );

	void setFirstName(std::string& firstName);
	void setLastName(std::string& lastName);
	void setNickname(std::string& nickname);
	void setPhoneNumber(std::string& phoneNumber);
	void setDarkestSecret(std::string& darkestSecret);

	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
	std::string getPhoneNbr(void) const;
	std::string getSecret(void) const;

	static int getInfo(Contact& contact);

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

bool strDigits(const std::string& str);
int	strTrim(std::string& str);
#endif
