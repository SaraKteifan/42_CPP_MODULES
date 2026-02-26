#include "iter.hpp"
#include <string>

void	increment(int& element)
{
	element++;
}

int	main()
{
	int			array1[] = {1, 2, 3};
	std::string	array2[] = {"Sara", "Kteifan"};

	iter(array1, 3, increment);

	iter(array1, 3, printTemplate<int>);
	iter(array2, 2, printTemplate<std::string>);

	return 0;
}
