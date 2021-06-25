#include <iostream>
#include <queue>
#include <list>
#include "queue.h"

template < typename T, typename Sourse>
void queue_constructor(Sourse vec)
{
	std::queue<T, Sourse > st_first;
	std::queue<T, Sourse > st_second(vec);
	std::cout << "st_first size(): " << st_first.size() << "\t";
	std::cout << "empty(): " << st_first.empty() << "  |  ";
	std::cout << "st_second size(): " << st_second.size() << "\t";
	std::cout << "empty(): " << st_second.empty() << "\n";

	ft::queue<T, Sourse > ft_first;
	ft::queue<T, Sourse > ft_second(vec);
	std::cout << "ft_first size(): " << ft_first.size() << "\t";
	std::cout << "empty(): " << ft_first.empty() << "  |  ";
	std::cout << "ft_second size(): " << ft_second.size() << "\t";
	std::cout << "empty(): " << ft_second.empty() << "\n\n";
}

void	test_constructors()
{
std::cout << YELLOW << "\n***--- queue CONSTRUCTORS" << RESET << std::endl;
	std::list<int> mylist(4, 13);
	queue_constructor<int, std::list<int> >(mylist);

	std::deque<int> mydeque(5, 7);
	queue_constructor<int, std::deque<int> >(mydeque);
}

template < typename T >
void	test_push_pop_front_empty_back()
{
std::cout << YELLOW << "\n***--- queue PUSH POP FRONT EMPTY" << RESET << std::endl;
	T myqueue;
	int sum (0);
	std::cout << sum;
	for (int i=1; i<=10; i++) myqueue.push(i);
	while (!myqueue.empty())
	{
		std::cout << " + " << myqueue.front();
		sum += myqueue.front();
		myqueue.pop();
	}
	std::cout << " = " << sum << '\n';

	myqueue.push(12);
	myqueue.push(75);
	myqueue.back() -= myqueue.front();
	std::cout << "myqueue.back() is now " << myqueue.back() << '\n';
}

void	test_relational_operators()
{
std::cout << YELLOW << "\n\n***--- queue: relational operators" << RESET << std::endl;
	std::vector<size_t> vec_a(5, 10); std::queue<size_t, std::vector<size_t> > st_a(vec_a);
	std::vector<size_t> vec_b(vec_a); std::queue<size_t, std::vector<size_t> > st_b(vec_b);
	ft::queue<size_t, std::vector<size_t> > ft_a(vec_a);
	ft::queue<size_t, std::vector<size_t> > ft_b(vec_b);

	if (st_a == st_b) std::cout << GREEN << "a == b" << RESET << "\t";
	if (ft_a == ft_b) std::cout << BLUE << "a == b" << RESET << "\n";

	st_b.push(3); std::cout << st_b.back() << " " << st_b.size() << "\t";
	ft_b.push(3); std::cout << ft_b.back() << " " << ft_b.size() << "\n";

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
	test_push_pop_front_empty_back<std::queue<int> >();
	test_push_pop_front_empty_back<ft::queue<int> >();
	test_relational_operators();
	return 0;
}