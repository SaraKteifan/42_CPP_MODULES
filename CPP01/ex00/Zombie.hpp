#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie
{
	private:
		std::string	_name;
	public:
		Zombie();
		Zombie(std::string name);
		std::string	getName( void );
		void	setName(std::string name);
		void	announce( void );
};

#endif
