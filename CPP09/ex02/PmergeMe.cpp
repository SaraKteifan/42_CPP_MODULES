#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <cerrno>
#include <limits>
#include <sys/time.h>

PmergeMe::PmergeMe() : _vectorTime(0.0), _dequeTime(0.0)
{}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
		_vectorTime = other._vectorTime;
		_dequeTime = other._dequeTime;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{}

std::vector<int>	PmergeMe::parseArguments(int argc, char** argv)
{
	std::vector<int>	input;

	for (int i = 1; i < argc; i++)
	{
		char*	end = NULL;
		errno = 0;
		long	num = strtol(argv[i], &end, 10);
		if (errno == ERANGE
			|| num > std::numeric_limits<int>::max()
			|| num < 0)
			throw std::runtime_error("Out of range.");
		if (end == argv[i] || *end != '\0')
			throw std::runtime_error("Invalid input.");
		input.push_back(static_cast<int>(num));
	}
	
	return (input);
}


void	PmergeMe::printSequenceBefore(const std::vector<int>& input) const
{
	std::cout << "Before:";
	for (std::vector<int>::const_iterator it = input.begin(); it != input.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void	PmergeMe::printSequenceAfter() const
{
	std::cout << "After:";
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void	PmergeMe::printTimings() const
{
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " 
			<< _vectorTime << " us" << std::endl;

	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : "
			<< _dequeTime << " us" << std::endl;
}

void	PmergeMe::binaryInsertVector(std::vector<Element>& chain, const Element& element, size_t rightBound)
{
	size_t	left = 0;
	size_t	right = rightBound;

	while (left < right)
	{
		size_t	middle = left + (right - left) / 2;
		if (chain[middle].value < element.value)
			left = middle + 1;
		else
			right = middle;
	}
	
	chain.insert(chain.begin() + left, element);
}

void	PmergeMe::insertPendingVector(std::vector<Element>& mainChain, const std::vector<ElementPair>& sortedPairs,
										bool hasStraggler, const Element& straggler)
{
	size_t	pendingCount = sortedPairs.size();

	if (hasStraggler)
		++pendingCount;

	size_t	previousJacobsthal = 1;
	size_t	currentJacobsthal = 3;

	while (previousJacobsthal < pendingCount)
	{
		size_t	upper = currentJacobsthal;

		if (upper > pendingCount)
			upper = pendingCount;

		for (size_t pairIndex = upper; pairIndex > previousJacobsthal; --pairIndex)
		{
			if (pairIndex <= sortedPairs.size())
			{
				Element	pending = sortedPairs[pairIndex - 1].loser;
				Element	partner = sortedPairs[pairIndex - 1].winner;

				size_t	partnerPos = 0;

				while (partnerPos < mainChain.size() && mainChain[partnerPos].id != partner.id)
				{
					++partnerPos;
				}

				if (partnerPos == mainChain.size())
					throw std::runtime_error("Internal error: partner not found.");

				binaryInsertVector(mainChain, pending, partnerPos);
			}
			else
			{
				binaryInsertVector(mainChain, straggler, mainChain.size());
			}
		}

		if (currentJacobsthal >= pendingCount)
			break;

		size_t	nextJacobsthal = currentJacobsthal + 2 * previousJacobsthal;

		previousJacobsthal = currentJacobsthal;
		currentJacobsthal = nextJacobsthal;
	}
}

void	PmergeMe::fordJohnsonVector(std::vector<Element>& sequence)
{
	if (sequence.size() <= 1)
		return ;

	std::vector<ElementPair>	pairs;
	
	bool	hasStraggler = false;
	Element	straggler;

	for (size_t i = 0; i + 1 < sequence.size(); i += 2)
	{
		ElementPair	pair;

		if (sequence[i].value <= sequence[i + 1].value)
		{
			pair.loser = sequence[i];
			pair.winner = sequence[i + 1];
		}
		else
		{
			pair.loser = sequence[i + 1];
			pair.winner = sequence[i];
		}

		pairs.push_back(pair);
	}

	if (sequence.size() % 2 != 0)
	{
		hasStraggler = true;
		straggler = sequence[sequence.size() - 1];
	}

	std::vector<Element>	winners;
	
	for (size_t i = 0; i < pairs.size(); i++)
	{
		winners.push_back(pairs[i].winner);
	}

	fordJohnsonVector(winners);

	std::vector<ElementPair>	sortedPairs;

	for (size_t i = 0; i < winners.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (winners[i].id == pairs[j].winner.id)
			{
				sortedPairs.push_back(pairs[j]);
				break ;
			}
		}
	}

	std::vector<Element>	mainChain;
	mainChain.push_back(sortedPairs[0].loser);
	for (size_t i = 0; i < sortedPairs.size(); i++)
	{
		mainChain.push_back(sortedPairs[i].winner);
	}

	insertPendingVector(mainChain, sortedPairs, hasStraggler, straggler);

	sequence = mainChain;
}

void	PmergeMe::fordJohnsonDeque()
{}

void	PmergeMe::sortVector(const std::vector<int>& input)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);

	_vector.clear();

	std::vector<Element>	sequence;

	for (size_t i = 0; i < input.size(); i++)
	{
		Element element;

		element.value = input[i];
		element.id = i;

		sequence.push_back(element);
	}

	fordJohnsonVector(sequence);
	
	for (size_t i = 0; i < sequence.size(); i++)
		_vector.push_back(sequence[i].value);

	gettimeofday(&end, NULL);

	_vectorTime = static_cast<double>(end.tv_sec - start.tv_sec) * 1000000.0
				+ static_cast<double>(end.tv_usec - start.tv_usec);
}

void	PmergeMe::sortDeque(const std::vector<int>& input)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);

	_deque.clear();

	for (std::vector<int>::const_iterator it = input.begin(); it != input.end(); ++it)
	{
		_deque.push_back(*it);
	}

	fordJohnsonDeque();

	gettimeofday(&end, NULL);

	_dequeTime = static_cast<double>(end.tv_sec - start.tv_sec) * 1000000.0
				+ static_cast<double>(end.tv_usec - start.tv_usec);
}

void	PmergeMe::run(int argc, char** argv)
{
	std::vector<int>	input = parseArguments(argc, argv);

	printSequenceBefore(input);

	sortVector(input);
	sortDeque(input);

	printSequenceAfter();

	printTimings();
}
