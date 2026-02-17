#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main()
{
	srand(time(0));

	for (int i = 0; i < 5; i++)
	{
		Base* obj = generate();
		std::cout << "First \"identify\" function result:  ";
		identify(obj);
		std::cout << "Second \"identify\" function result: ";
		identify(*obj);
		std::cout << std::endl;
		delete obj;
	}
	
	return (0);
}
