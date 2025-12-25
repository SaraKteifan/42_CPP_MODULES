#include "PhoneBook.hpp"
#include <iostream>

int	main()
{
	PhoneBook phoneBook;
	std::string command;

	while (1)
	{
		std::cout << "Enter a command \"ADD\", \"SEARCH\", or \"EXIT\": ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD")
		{
			phoneBook.add_contact();
		}
		else if (command == "SEARCH")
		{
			phoneBook.search_contact();
		}
		else if (command == "EXIT")
			break ;
	}
	return (0);
}
