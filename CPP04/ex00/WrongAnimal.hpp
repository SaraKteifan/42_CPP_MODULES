#ifndef WrongANIMAL_H
# define WRONGANIMAL_H
# include <string>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal&	operator=(const WrongAnimal& other);
		~WrongAnimal();
		std::string		getType() const;
		void			setType(const std::string& type);
		void	makeSound() const;
};

#endif
