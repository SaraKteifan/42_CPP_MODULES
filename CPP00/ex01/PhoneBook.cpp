#include "PhoneBook.hpp"
#include <iostream>


PhoneBook::PhoneBook()
{
	this->next_index = 0;
}

static bool	is_only_spaces(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (false);
	}
	return (true);
}

static bool	is_only_digits(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
	}
	return (true);
}

static std::string	get_valid_name(std::string field)
{
	std::string	name;

	while (true)
	{
		std::cout << field;
		std::getline(std::cin, name);
		if (name.empty())
		{
			std::cout << "!! " << field << "field cannot be empty." << std::endl;
			continue;
		}
		if (is_only_spaces(name))
		{
			std::cout << "!! " << field << "field cannot contain spaces only." << std::endl;
			continue;
		}
		return (name);
	}
}

static std::string	get_valid_phone_number()
{
	std::string	phone_number;

	while (true)
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, phone_number);
		if (phone_number.empty())
		{
			std::cout << "!! " << "Phone Number: field cannot be empty." << std::endl;
			continue;
		}
		if (is_only_spaces(phone_number))
		{
			std::cout << "!! " << "Phone Number: field cannot contain spaces only." << std::endl;
			continue;
		}
		if (!is_only_digits(phone_number))
		{
			std::cout << "!! " << "Phone Number: field can contain digits only." << std::endl;
			continue;
		}
		return (phone_number);
	}
}

static std::string	get_valid_darkest_secret()
{
	std::string	secret;

	while (true)
	{
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, secret);
		if (secret.empty())
		{
			std::cout << "!! " << "Darkest Secret: field cannot be empty." << std::endl;
			continue;
		}
		return (secret);
	}
}

void	PhoneBook::add_contact()
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;

	first_name = get_valid_name("First Name: ");
	last_name = get_valid_name("Last Name: ");
	nick_name = get_valid_name("Nick Name: ");
	phone_number = get_valid_phone_number();
	darkest_secret = get_valid_darkest_secret();

	contacts[this->next_index].setFirstName(first_name);
	contacts[this->next_index].setLastName(last_name);
	contacts[this->next_index].setNickName(nick_name);
	contacts[this->next_index].setPhoneNumber(phone_number);
	contacts[this->next_index].setDarkestSecret(darkest_secret);

	// Circular index
	this->next_index = (this->next_index + 1) % MAX_CONTACTS;

}

void	PhoneBook::search_contact()
{
	std::cout << "index | first name | last name | nickname" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (contacts[i].getFirstName().empty())
			break;
		std::cout << i + 1 << " | " << contacts[i].getFirstName() << " | " << contacts[i].getLastName()
			<< " | " << contacts[i].getNickName() << std::endl;
	}
}