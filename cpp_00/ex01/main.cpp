
#include "PhoneBook.hpp"
#include "Contact.hpp"

bool strDigits(const std::string& str)
{
	size_t i = 0;
	if (str[0] == '+')
		i++;
	while (i < str.length())
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
		i++;
	}
	return true;
}

int	strTrim(std::string& str)
{
	std::string s = str;
	size_t start = str.find_first_not_of(" \t\n\r");
	if (start == std::string::npos)
	{
		str = "";
		return 1;
	}
	size_t end = str.find_last_not_of(" \t\n\r");
	str = s.substr(start, end - start + 1);
	return 0;
}

int	Contact::getInfo(Contact& contact)
{
	std::string firstName, lastName, nickname, phoneNbr, secret;

	std::cout << "Fill out following fields to save a new contact: " << "\n";
	while (firstName.empty())
	{
		std::cout << "First name: ";
		std::getline(std::cin, firstName);
		strTrim(firstName);
		if (std::cin.eof())
		{
			firstName.clear();
			return (2);
		}
		contact.setFirstName(firstName);
	}
	while (lastName.empty())
	{
		std::cout << "Last name: ";
		std::getline(std::cin, lastName);
		strTrim(lastName);
		if (std::cin.eof())
		{
			lastName.clear();
			return (2);
		}
		contact.setLastName(lastName);
	}
	while (nickname.empty())
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, nickname);
		strTrim(nickname);
		if (std::cin.eof())
		{
			nickname.clear();
			return (2);
		}
		contact.setNickname(nickname);
	}
	while (phoneNbr.empty())
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, phoneNbr);
		strTrim(phoneNbr);
		if (std::cin.eof())
		{
			phoneNbr.clear();
			return (2);
		}
		if (!strDigits(phoneNbr))
		{
			std::cout << "Error: numbers required" << "\n";
			phoneNbr.clear();
		}
		contact.setPhoneNumber(phoneNbr);
	}
	while (secret.empty())
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, secret);
		strTrim(secret);
		if (std::cin.eof())
		{
			secret.clear();
			return (2);
		}
		contact.setDarkestSecret(secret);
	}
	return (0);
}

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
		return (1);
	std::string	str;
	Contact		contact;
	PhoneBook	phoneBook;
	std::cout << "\t" << "Welcome to the 80s and their unbelievable technology!" << "\n";
	while (1)
	{
		std::cout << "Available options: ADD, SEARCH, EXIT" << "\n";
		std::getline(std::cin, str);
		if (std::cin.eof())
			return -1;
		if (!str.empty())
		{
			strTrim(str);
			if (str.compare("ADD") == 0)
			{
				if (contact.getInfo(contact) != 0)
					return -1;
				phoneBook.setContact(contact);
			}
			else if (str.compare("SEARCH") == 0)
			{
				phoneBook.displayContacts();
				str.clear();
				std::cout << "Select the index to get contact details: ";
				std::getline(std::cin, str);
				if (std::cin.eof())
					return -1;
				phoneBook.searchContact(str);
			}
			else if (str.compare("EXIT") == 0)
			{
				std::cout << "Your contacts are lost!" << "\n";
				return 0;
			}
			else
				std::cout << "Error. Invalid input" << "\n";
		}
	}
	return 0;
}
