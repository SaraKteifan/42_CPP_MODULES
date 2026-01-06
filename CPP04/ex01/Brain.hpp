#ifndef BRAIN_H
# define BRAIN_H
# include "Animal.hpp"

class Brain : public Animal
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const Brain& other);
		Brain&	operator=(const Brain& other);
		~Brain();
};

#endif
