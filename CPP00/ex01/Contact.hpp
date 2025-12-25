#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
	public:
		Contact();
		Contact(std::string firstName, std::string lastName,
			std::string nickName, std::string phoneNumber, std::string darkestSecret);
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();
		void	setFirstName(std::string first_name);
		void	setLastName(std::string last_name);
		void	setNickName(std::string nick_name);
		void	setPhoneNumber(std::string phone_number);
		void	setDarkestSecret(std::string darkest_secret);
};

#endif
