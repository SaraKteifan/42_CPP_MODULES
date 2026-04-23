#include "span.hpp"

Span::Span() : N(0)
{}

Span::Span(unsigned int _N) : N(_N)
{}


Span::Span(const Span& other)
{
	*this = other;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		N = other.N;
		arr = other.arr;
	}
	return (*this);
}

Span::~Span()
{}

void	Span::addNumber(int num)
{
	if (arr.size() == N)
		throw std::runtime_error("Array is full!!!");
	arr.push_back(num);
}

int		Span::shortestSpan()
{
	if (arr.size() < 2)
		throw std::runtime_error("Not enough elements!!!");
	std::vector<int> tmp = arr;
	std::sort(tmp.begin(), tmp.end());
	int	shortest = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size() - 1; ++i)
	{
		if (tmp[i + 1] - tmp[i]  < shortest)
			shortest = tmp[i + 1] - tmp[i];
	}
	return (shortest);
}

int		Span::longestSpan()
{
	if (arr.size() < 2)
		throw std::runtime_error("Not enough elements!!!");
	int min = *std::min_element(arr.begin(), arr.end());
	int max = *std::max_element(arr.begin(), arr.end());
	return (max - min);
}
