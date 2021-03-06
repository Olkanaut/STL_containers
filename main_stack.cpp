#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include "stack.h"

template < typename T, typename Sourse>
void stack_constructor(Sourse vec)
{
	std::stack<T, Sourse > st_first;
	std::stack<T, Sourse > st_second(vec);
	std::cout << "st_first size(): " << st_first.size() << "\t";
	std::cout << "empty(): " << st_first.empty() << "  |  ";
	std::cout << "st_second size(): " << st_second.size() << "\t";
	std::cout << "empty(): " << st_second.empty() << "\n";

	ft::stack<T, Sourse > ft_first;
	ft::stack<T, Sourse > ft_second(vec);
	std::cout << "ft_first size(): " << ft_first.size() << "\t";
	std::cout << "empty(): " << ft_first.empty() << "  |  ";
	std::cout << "ft_second size(): " << ft_second.size() << "\t";
	std::cout << "empty(): " << ft_second.empty() << "\n\n";
}

void	test_constructors()
{
std::cout << YELLOW << "\n\n***--- STACK CONSTRUCTORS" << RESET << std::endl;
	std::vector<int> myvec(3, 200);
	stack_constructor<int, std::vector<int> >(myvec);

	std::list<int> mylist(4, 13);
	stack_constructor<int, std::list<int> >(mylist);

	std::deque<int> mydeque(5, 7);
	stack_constructor<int, std::deque<int> >(mydeque);
}

template < typename T >
void	test_push_pop_top_empty()
{
std::cout << YELLOW << "\n\n***--- STACK PUSH POP TOP EMPTY" << RESET << std::endl;
	T mystack;
	int sum (0);
	std::cout << sum;
	for (int i=1; i<=10; i++) mystack.push(i);
	while (!mystack.empty())
	{
		std::cout << " + " << mystack.top();
		sum += mystack.top();
		mystack.pop();
	}
	std::cout << " = " << sum << "\n";
}

void	test_relational_operators()
{
std::cout << YELLOW << "\n\n***--- STACK: relational operators" << RESET << std::endl;
	std::vector<size_t> vec_a(5, 10); std::stack<size_t, std::vector<size_t> > st_a(vec_a);
	std::vector<size_t> vec_b(vec_a); std::stack<size_t, std::vector<size_t> > st_b(vec_b);
	ft::stack<size_t, std::vector<size_t> > ft_a(vec_a);
	ft::stack<size_t, std::vector<size_t> > ft_b(vec_b);

	if (st_a == st_b) std::cout << GREEN << "a == b" << RESET << "\t";
	if (ft_a == ft_b) std::cout << BLUE << "a == b" << RESET << "\n";

	st_b.push(3); std::cout << st_b.top() << " " << st_b.size() << "\t";
	ft_b.push(3); std::cout << ft_b.top() << " " << ft_b.size() << "\n";

	if (st_b >= st_a)	std::cout << GREEN << "b >= a" << RESET << "\t";
	if (ft_b >= ft_a)	std::cout << BLUE << "b >= a" << RESET << "\n";
	if (st_b > st_a)	std::cout << GREEN << "b > a" << RESET << "\t";
	if (ft_b > ft_a)	std::cout << BLUE << "b > a" << RESET << "\n";
	if (st_b != st_a)	std::cout << GREEN << "b != a" << RESET << "\t";
	if (ft_b != ft_a)	std::cout << BLUE << "b != a" << RESET << "\n";

	if (st_a <= st_b)	std::cout << GREEN << "a <= b" << RESET << "\t";
	if (ft_a <= ft_b)	std::cout << BLUE << "a <= b" << RESET << "\n";
	if (st_a < st_b)	std::cout << GREEN << "a < b" << RESET << "\t";
	if (ft_a < ft_b)	std::cout << BLUE << "a < b" << RESET << "\n";
}

int main ()
{
	test_constructors();
	test_push_pop_top_empty<std::stack<int> >();
	test_push_pop_top_empty<ft::stack<int> >();
	test_relational_operators();
	return 0;
}