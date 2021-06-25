#include <iostream>
#include <iomanip>
#include <map>
#include "map.h"
#include "utils.h"

template< typename T >
void	print_map(T & cont)
{
	typename T::iterator begin = cont.begin();
	typename T::iterator end = cont.end();
	while (begin != end){
		std::cout << begin->first << " -> " << begin->second << std::endl;
		++begin;
	}
	std::cout << "\n";
}

template< typename T >
void	print_rev_map(T & cont)
{
	typename T::reverse_iterator rbegin = cont.rbegin();
	typename T::reverse_iterator rend = cont.rend();
	while (rbegin != rend){
		std::cout << rbegin->first << " -> " << rbegin->second << std::endl;
		++rbegin;
	}
	std::cout << "\n";
}

template< typename T >
void	print_const_map(T const & cont)
{
	std::cout << "const it:\n";
	typename T::const_iterator begin = cont.begin();
	typename T::const_iterator end = cont.end();
	while (begin != end){
		std::cout << begin->first << " -> " << begin->second << std::endl;
		++begin;
	}
	std::cout << "\n";
}

template< typename T >
void	print_const_rev_map(T const & cont)
{
	std::cout << "const it:\n";
	typename T::const_reverse_iterator rbegin = cont.rbegin();
	typename T::const_reverse_iterator rend = cont.rend();
	while (rbegin != rend){
		std::cout << rbegin->first << " -> " << rbegin->second << std::endl;
		++rbegin;
	}
	std::cout << "\n";
}


void	test_map_constructors_and_iterators()
{
	std::map<char, int> mymap;
	ft::map<char, int> ftmap;

	mymap['d'] = 80; ftmap['d'] = 80;
	mymap['c'] = 60; ftmap['c'] = 60;
	mymap['a'] = 20; ftmap['a'] = 20;
	mymap['b'] = 40; ftmap['b'] = 40;

std::cout << BLUE << "***------- map: default constructor" << RESET << std::endl;
	std::map<char, int>::iterator it, ite;
	it = mymap.begin(); ++it;	ite = mymap.end(); --ite;
	print_map(mymap);
	print_map(ftmap);

std::cout << BLUE << "***------- map: range constructor" << RESET << std::endl;
	std::map<char, int> mymap_it(it, ite);
	ft::map<char, int> ftmap_it(it, ite);
	print_map(mymap_it);
	print_map(ftmap_it);

std::cout << BLUE << "***------- map: range constructor with const" << RESET << std::endl;
	std::map<char, int> const mymap_it_const(it, ite);
	ft::map<char, int> const ftmap_it_const(it, ite);
	print_const_map(mymap_it_const);
	print_const_map(ftmap_it_const);

std::cout << BLUE << "***------- map: copy constructor" << RESET << std::endl;
	std::map<char, int> mymap_cp(mymap);
	ft::map<char, int> ftmap_cp(ftmap);
	print_map(mymap_cp);
	print_map(ftmap_cp);

std::cout << BLUE << "***------- map: const copy constructor" << RESET << std::endl;
	std::map<char, int> const mymap_cp_const(mymap);
	ft::map<char, int> const ftmap_cp_const(ftmap);
	print_const_map(mymap_cp_const);
	print_const_map(ftmap_cp_const);

std::cout << BLUE << "***------- map: reverse iterator" << RESET << std::endl;
	print_rev_map(mymap_it);
	print_rev_map(ftmap_it);

std::cout << BLUE << "***------- map: reverse const iterator" << RESET << std::endl;
	print_const_rev_map(mymap_cp);
	print_const_rev_map(mymap_cp_const);
	print_const_rev_map(ftmap_cp);
	print_const_rev_map(ftmap_cp_const);
}

template <typename T>
void	test_insert()
{
	T mymap;

	std::cout << BLUE << "\n***------- first insert function version (single parameter)" << RESET << std::endl;
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('z',200) );

	std::pair<typename T::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('z',500) );
	if (ret.second == false)
		std::cout << "element 'z' already existed with a value of " << ret.first->second << '\n';

	std::cout << BLUE << "\n***------- second insert function version (with hint position)" << RESET << std::endl;
	typename T::iterator it = mymap.begin();
	mymap.insert (it, std::pair<char,int>('b',300)); // max efficiency inserting
	mymap.insert (it, std::pair<char,int>('c',400)); // no max efficiency inserting
	std::cout << "mymap contains:\n";
	print_map(mymap);

	std::cout << BLUE << "***------- third insert function version (range insertion)" << RESET << std::endl;
	T anothermap;
	anothermap.insert(mymap.begin(), mymap.find('c'));

	std::cout << "anothermap contains:\n";
	print_map(anothermap);
}

template <typename T>
void test_contents()
{
	std::cout << BLUE << "***------- clear:" << RESET << std::endl;
	T mymap;
	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;
	std::cout << "mymap contains:\n";	print_map(mymap);

	std::cout << "max_size: " << mymap.max_size() << " size: " << mymap.size() << "\tempty: " << mymap.empty() << std::endl;
	mymap.clear();
	std::cout << "max_size: " << mymap.max_size() << " size: " << mymap.size() << "\tempty: " << mymap.empty() << std::endl;

	mymap['a']=1101;
	mymap['b']=2202;
	print_map(mymap);

	std::cout << BLUE << "***------- count:" << RESET << std::endl;
	for (char c='a'; c<'e'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
		else
			std::cout << " is not an element of mymap.\n";
	}

	std::cout << BLUE << "\n***------- equal_range:" << RESET << std::endl;
	std::pair<typename T::iterator, typename T::iterator> ret;
	ret = mymap.equal_range('b');
	std::cout << "lower bound points to: " << ret.first->first << " => " << ret.first->second << '\n';
	std::cout << "upper bound points to: " << ret.second->first << " => " << ret.second->second << '\n';
	std::cout << "\n\n";
}

template <typename T>
void test_contents_find_erase()
{
	T mymap;
	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;
	std::cout << BLUE << "--- mymap contains:" << RESET << std::endl;	print_map(mymap);

	std::cout << BLUE << "***------- find 'b', erase:" << RESET << std::endl;
	typename T::iterator it;
	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);
	print_map(mymap);

	std::cout << BLUE << "***------- empty, erase:" << RESET << std::endl;
	while (!mymap.empty())
	{
		std::cout << "erasing: " << mymap.begin()->first << " => " << mymap.begin()->second << "...\t";
		mymap.erase(mymap.begin());
	}
	if (mymap.empty())
		std::cout << GREEN << "map is empty\n" << RESET;

	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << "\n\n\n";
}

template <typename T>
void	test_lower_upper_bonds()
{
	T mymap;
	typename T::iterator itlow, itup;
	mymap['d'] = 80;
	mymap['e'] = 100;
	mymap['a'] = 20;
	mymap['c'] = 60;
	mymap['b'] = 40;
	mymap['f'] = 120;

	itlow = mymap.lower_bound ('b');
	itup = mymap.upper_bound ('d');
	mymap.erase(itlow, itup);	// erases [itlow,itup)
	print_map(mymap);
}

void	test_key_compare()
{
	std::map<std::string, std::string>	smap;
	ft::map<std::string, std::string>	fmap;

	std::cout <<
	smap.key_comp()("key1", "key2") <<
	fmap.key_comp()("key1", "key2") <<
	smap.value_comp()(std::make_pair("key3", "val"), std::make_pair("key2", "val")) <<
	fmap.value_comp()(std::make_pair("key3", "val"), std::make_pair("key2", "val")) <<
	std::endl;
}

template <typename T>
void	test_swap()
{
	T foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:\n"; print_map(foo);
	std::cout << "bar contains:\n"; print_map(bar);
}

template <typename T>
void	test_relational_operators()
{
	T foo,bar;
	foo['a']=100;
	foo['b']=200;
	bar['a']=10;
	bar['z']=1000;
	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
	if (foo == bar) std::cout << "foo and bar are equal\n";
	if (foo != bar) std::cout << "foo and bar are not equal\n";
	if (foo <  bar) std::cout << "foo is less than bar\n";
	if (foo >  bar) std::cout << "foo is greater than bar\n";
	if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
	if (foo >= bar) std::cout << "foo is greater than or equal to bar\n\n";
}

int main()
{
std::cout << YELLOW << "\n\n***--- MAP: constructors" << RESET << std::endl;
	test_map_constructors_and_iterators();

std::cout << YELLOW << "\n\n***--- MAP: insert" << RESET << std::endl;
	test_insert<std::map<char, int> >();
	test_insert<ft::map<char, int> >();

std::cout << YELLOW << "\n\n***--- MAP: content management" << RESET << std::endl;
	test_contents<std::map<char, int> >();
	test_contents<ft::map<char, int> >();

std::cout << YELLOW << "\n\n***--- MAP: content: find, erase" << RESET << std::endl;
	test_contents_find_erase<std::map<char, int> >();
	test_contents_find_erase<ft::map<char, int> >();

std::cout << YELLOW << "\n***--- MAP: lower and upper bonds" << RESET << std::endl;
	test_lower_upper_bonds<std::map<char, int> >();
	test_lower_upper_bonds<ft::map<char, int> >();

std::cout << YELLOW << "\n***--- MAP: key_compare" << RESET << std::endl;
	test_key_compare();
	test_key_compare();

std::cout << YELLOW << "\n\n***--- MAP: swap" << RESET << std::endl;
	test_swap<std::map<char, int> >();
	test_swap<ft::map<char, int> >();

std::cout << YELLOW << "\n***--- MAP: relational operators" << RESET << std::endl;
	test_relational_operators<std::map<char, int> >();
	test_relational_operators<ft::map<char, int> >();
}