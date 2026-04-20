#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
#include <cstddef>

template <typename T, typename F>
void	iter(T* array, const std::size_t size, F func)
{
	for (std::size_t i = 0; i < size; i++)
		func(array[i]);
}

template <typename T>
void	printTemplate(const T& element)
{
	std::cout << element << std::endl;
}

#endif
