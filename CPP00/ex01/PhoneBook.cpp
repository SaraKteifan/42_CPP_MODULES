#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>


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
			std::cout << "\033[31m!!\033[0m " << field << " cannot be empty." << std::endl;
			continue;
		}
		if (is_only_spaces(name))
		{
			std::cout << "\033[31m!!\033[0m " << field << " cannot contain spaces only." << std::endl;
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
			std::cout << "\033[31m!!\033[0m " << "Phone Number: cannot be empty." << std::endl;
			continue;
		}
		if (is_only_spaces(phone_number))
		{
			std::cout << "\033[31m!!\033[0m " << "Phone Number: cannot contain spaces only." << std::endl;
			continue;
		}
		if (!is_only_digits(phone_number))
		{
			std::cout << "\033[31m!!\033[0m " << "Phone Number: can contain digits only." << std::endl;
			continue;
		}
		if (!(phone_number.length() >= 8 && phone_number.length() <= 12))
		{
			std::cout << "\033[31m!!\033[0m " << "Phone Number: must be between 8-12 digits." << std::endl;
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
			std::cout << "\033[31m!!\033[0m " << "Darkest Secret: cannot be empty." << std::endl;
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

static void	display_col(std::string field)
{
	if (field.length() < 10)
	{
		for (size_t i = 0; i < (10 - field.length()); i++)
			std::cout << ' ';
		for (size_t j = 0; j < field.length(); j++)
			std::cout << field[j];
	}
	else
	{
		for (size_t j = 0; j < 9; j++)
			std::cout << field[j];
		std::cout << ".";
	}
}

static int get_valid_index()
{
	std::string	index;
	int			i;

	while (true)
	{
		std::cout << "Enter index of contact to display: ";
		std::getline(std::cin, index);
		if (index.empty())
		{
			std::cout << "\033[31m!!\033[0m " << "Index cannot be empty." << std::endl;
			continue;
		}
		if (is_only_spaces(index))
		{
			std::cout << "\033[31m!!\033[0m " << "Index cannot be empty." << std::endl;
			continue;
		}
		if (!is_only_digits(index))
		{
			std::cout << "\033[31m!!\033[0m " << "Invalid index." << std::endl;
			continue;
		}
		std::stringstream ss(index);
		ss >> i;
		if (ss.fail() || !ss.eof())
		{
			std::cout << "\033[31m!!\033[0m " << "Invalid index." << std::endl;
			continue;
		}
		return (i);
	}
}

static void	display_contact(Contact contact)
{
	std::cout << "First Name:     " << contact.getFirstName() << std::endl;
	std::cout << "Last Name:      " << contact.getLastName() << std::endl;
	std::cout << "Nick Name:      " << contact.getNickName() << std::endl;
	std::cout << "Phone Number:   " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

void	PhoneBook::search_contact()
{
	int	index;

	std::cout << "     index|first name| last name| nick name" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (contacts[i].getFirstName().empty())
			break;
		std::cout << "         " << i + 1;
		std::cout << "|";
		display_col(contacts[i].getFirstName());
		std::cout << "|";
		display_col(contacts[i].getLastName());
		std::cout << "|";
		display_col(contacts[i].getNickName());
		std::cout << std::endl;
	}

	while (true)
	{
		index = get_valid_index();
		if (index < 1 || index > 8)
		{
			std::cout << "\033[31m!!\033[0m " << "index out of range." << std::endl;
			continue;
		}
		if (contacts[index - 1].getFirstName().empty())
		{
			std::cout << "\033[31m!!\033[0m " << "Contact is empty." << std::endl;
			continue;
		}
		display_contact(contacts[index - 1]);
		break;
	}
}
