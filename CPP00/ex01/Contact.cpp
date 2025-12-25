#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string firstName, std::string lastName,
	std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName()
{
	return (this->firstName);
}

std::string	Contact::getLastName()
{
	return (this->lastName);
}

std::string	Contact::getNickName()
{
	return (this->nickName);
}

std::string	Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}

std::string	Contact::getDarkestSecret()
{
	return (this->darkestSecret);
}

void	Contact::setFirstName(std::string first_name)
{
	this->firstName = first_name;
}

void	Contact::setLastName(std::string last_name)
{
	this->lastName = last_name;
}

void	Contact::setNickName(std::string nick_name)
{
	this->nickName = nick_name;
}

void	Contact::setPhoneNumber(std::string phone_number)
{
	this->phoneNumber = phone_number;
}

void	Contact::setDarkestSecret(std::string darkest_secret)
{
	this->darkestSecret = darkest_secret;
}