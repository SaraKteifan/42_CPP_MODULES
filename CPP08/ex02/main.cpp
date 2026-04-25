#include "MutantStack.hpp"
#include <iostream>

int main()
{
	std::cout << "======= MutantStack vs stack Test =======" << std::endl;
	MutantStack<int> m;
	std::stack<int> s;

	m.push(10);
	s.push(10);

	m.push(20);
	s.push(20);

	std::cout << m.top() << " " << s.top() << std::endl;

	std::cout << "======= Basic iteration Test =======" << std::endl;
	MutantStack<int> mutant;
	
	mutant.push(1);
	mutant.push(2);
	mutant.push(3);

	for (MutantStack<int>::iterator it = mutant.begin(); it != mutant.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "======= Copy constructor Test =======" << std::endl;
	MutantStack<int> a;
	a.push(10);
	a.push(20);

	MutantStack<int> b(a);
	b.push(30);
	std::cout << a.top() << std::endl;
	std::cout << b.top() << std::endl;
	
	std::cout << "======= MutantStack of strings Test =======" << std::endl;
	MutantStack<std::string> c;

	c.push("Hello");
	c.push("42");

	for (MutantStack<std::string>::iterator it = c.begin(); it != c.end(); ++it)
		std::cout << *it << std::endl;

	
	return (0);
}

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }

