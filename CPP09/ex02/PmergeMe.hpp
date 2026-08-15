#ifndef	PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>

#include <cstddef>

class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		double	_vectorTime;
		double	_dequeTime;

		struct Element
		{
			int		value;
			size_t	id;
		};

		struct ElementPair
		{
			Element	loser;
			Element	winner;
		};

		void	sortVector(const std::vector<int>& input);
		void	sortDeque(const std::vector<int>& input);

		void	fordJohnsonVector(std::vector<Element>& sequence);
		void	fordJohnsonDeque(std::deque<Element>& sequence);

		void	insertPendingVector(std::vector<Element>& mainChain, const std::vector<ElementPair>& sortedPairs,
									bool hasStraggler, const Element& straggler);
		void	insertPendingDeque(std::deque<Element>& mainChain, const std::deque<ElementPair>& sortedPairs,
									bool hasStraggler, const Element& straggler);

		void	binaryInsertVector(std::vector<Element>& chain, const Element& element, size_t rightBound);
		void	binaryInsertDeque(std::deque<Element>& chain, const Element& element, size_t rightBound);

		std::vector<int>	parseArguments(int argc, char** argv);

		void	printSequenceBefore(const std::vector<int>& input) const;
		void	printSequenceAfter() const;
		void	printTimings() const;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe();

		void	run(int argc, char** argv);
};

#endif
