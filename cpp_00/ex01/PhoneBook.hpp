/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:46:07 by ohladkov          #+#    #+#             */
/*   Updated: 2024/03/28 11:03:12 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include "Contact.hpp"

class PhoneBook
{
public:

	PhoneBook( void );
	~PhoneBook( void );

	void 		setContact(Contact& contact);
	Contact 	getContact(int i) const;
	void		searchContact(std::string str);
	void		displayContacts(void);
	std::string truncateString(const std::string& str);

private:
	Contact _contacts[8];
	int	idx;
};
#endif
