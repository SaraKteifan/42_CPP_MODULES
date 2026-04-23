#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	arr;
	public:
		Span();
		Span(unsigned int _N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void	addNumber(int num);
		template <typename IT>
		void	addNumber(IT begin, IT end);
		int		shortestSpan();
		int		longestSpan();
};

template <typename IT>
void	Span::addNumber(IT begin, IT end)
{
	if (arr.size() + static_cast<size_t>(std::distance(begin, end)) > N)
		throw std::runtime_error("Not enough space!!!");
	for (IT it = begin; it != end; ++it)
		addNumber(*it);
}

#endif
