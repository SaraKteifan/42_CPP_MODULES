#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data	a;
	a.num = 42;
	a.str = "Sara";

	Data*	b = Serializer::deserialize(Serializer::serialize(&a));

	std::cout << "The original Data pointer address:      " << &a << std::endl;
	std::cout << "After using serialize then deserialize: " << b << std::endl;
	if (&a == b)
		std::cout << "The two pointers match ;)" << std::endl;
	else
		std::cout << "The two pointers do not match :(" << std::endl;

	std::cout << "Data number: " << b->num << std::endl;
	std::cout << "Data string: " << b->str << std::endl;

	return (0);
}