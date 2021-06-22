#include <iostream>
#include <list>
#include <vector>
#include <cmath>

#include "list.h"
#include "utils.h"

# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define FUXIA "\033[35m"
# define BLUE "\033[36m"
# define RESET "\033[0m"

template< typename T >
void	print_cont(T &cont)
{
	typename T::iterator it = cont.begin();
	while (it != cont.end())
		std::cout << *it++ << "\t";
	std::cout << "\n";
}

template< typename T >
void	print_cont(const T &cont)
{
	std::cout << "const it:\n";
	typename T::const_iterator it = cont.begin();
	while (it != cont.end())
		std::cout << *it++ << "\t";
	std::cout << "\n\n";
}

template< typename T >
void	print_rev_cont(T &cont)
{
	typename T::reverse_iterator rbegin = cont.rbegin();
	typename T::reverse_iterator rend = cont.rend();
	while (rbegin != rend)
		std::cout << *rbegin++ << "\t";
	std::cout << "\n";
}

template< typename T >
void	print_rev_cont(const T &cont)
{
	std::cout << "const it:\n";
	typename T::const_reverse_iterator rbegin = cont.rbegin();
	typename T::const_reverse_iterator rend = cont.rend();
	while (rbegin != rend)
		std::cout << *rbegin++ << "\t";
	std::cout << "\n\n";
}


template< typename T >
void	print_cont_temp(T &cont)
{
	typename T::iterator begin = cont.begin();
	typename T::iterator end = cont.end();
	while (begin != end){
		std::cout << begin->a << " " << begin->str << std::endl;
		++begin;
	}
	std::cout << "\n";
}

template< typename T >
void	print_rev_cont_temp(T &cont)
{
	typename T::reverse_iterator rbegin = cont.rbegin();
	typename T::reverse_iterator rend = cont.rend();
	while (rbegin != rend){
		std::cout << rbegin->a << " " << rbegin->str << std::endl;
		++rbegin;
	}
	std::cout << "\n";
}




template< typename T >
void	print_cont_temp(T const &cont)
{
	std::cout << "const it:\n";
	typename T::const_iterator begin = cont.begin();
	typename T::const_iterator end = cont.end();
	while (begin != end){
		std::cout << begin->a << " " << begin->str << std::endl;
		++begin;
	}
	std::cout << "\n";
}

template< typename T >
void	print_rev_cont_temp(T const &cont)
{
	std::cout << "const it:\n";
	typename T::const_reverse_iterator rbegin = cont.rbegin();
	typename T::const_reverse_iterator rend = cont.rend();
	while (rbegin != rend){
		std::cout << rbegin->a << " " << rbegin->str << std::endl;
		++rbegin;
	}
	std::cout << "\n";
}

class temp
{
	// private:
	public:
		int a;
		std::string str;
		temp() {}
		temp(int A, std::string const & Str) : a(A), str(Str) {}
		temp(temp const & src) { a = src.a; str = src.str; }
		~temp() {}

	friend std::ostream & operator<<(std::ostream &out, const temp & obj)
	{
		out << "a: " << obj.a << " str: " << obj.str;
		return out;
	};
};

template < typename T >
void	fill_list(std::list<T> & list, int num)
{
	for (int i = 111; i < 111 + num; i++)
		list.push_back(i);
}

template < typename T >
void	fill_list(ft::list<T> & list, int num)
{
	for (int i = 111; i < 111 + num; i++)
		list.push_back(i);
}

void	fill_list(ft::list<temp> & list, int num)
{
	(void)num;
	temp array[] = {temp(1, "aaa"), temp(2, "bbb"), temp(3, "ccc")};
	for (int i = 0; i < 3; i++)
		list.push_back(array[i]);
}

void	fill_list(std::list<temp> & list, int num)
{
	(void)num;
	temp array[] = {temp(1, "aaa"), temp(2, "bbb"), temp(3, "ccc")};
	for (int i = 0; i < 3; i++)
		list.push_back(array[i]);
}

void	fill_list(ft::list<std::string> & list, int num)
{
	(void)num;
	std::string array[] = {"aaa", "bbb", "ccc"};
	for (int i = 0; i < 3; i++)
		list.push_back(array[i]);
}

void	fill_list(std::list<std::string> & list, int num)
{
	(void)num;
	std::string array[] = {"aaa", "bbb", "ccc"};
	for (int i = 0; i < 3; i++)
		list.push_back(array[i]);
}

void	print_test_name(std::string const & str, ft::int_type)
{	std::cout << GREEN << str << "INT\n" << RESET << std::endl; }

void	print_test_name(std::string const & str, ft::char_type)
{	std::cout << GREEN << str << "CHAR\n" << RESET << std::endl; }

void	print_test_name(std::string const & str, ft::string_type)
{	std::cout << GREEN << str << "STRING\n" << RESET << std::endl; }

void	print_test_name(std::string const & str, ft::long_type)
{	std::cout << GREEN << str << "LONG\n" << RESET << std::endl; }

void	print_test_name(std::string const & str, ft::undef_type)
{	std::cout << GREEN << str << " ***\n" << RESET << std::endl; }

template<typename T>
void	list_test_push_back(T & cont, ft::notstr_type)
{
	for (int i = 97; i < 105; ++i)
			cont.push_back(i);
	print_cont(cont);
}

template<typename T>
void	list_test_push_back(T & cont, ft::str_type)
{
	for (int i = 97; i < 105; ++i)
		cont.push_back(ft::to_string(i, 10));
	print_cont(cont);
}

template<typename T>
void	list_test_pop_front(T & cont)
{
	for (int i = 0; i < 3; ++i)
		cont.pop_front();
	print_cont(cont);
}

template<typename T>
void	list_test_pop_back(T & cont, int n)
{
	for (int i = 0; i < n; ++i)
		cont.pop_back();
	print_cont(cont);
}

template<typename T>
void	list_test_push_front(T & cont, int n, ft::notstr_type)
{
	for (int i = 110; i < 110 + n; ++i)
			cont.push_front(i);
	print_cont(cont);
}

template<typename T>
void	list_test_push_front(T & cont, int n, ft::str_type)
{
	for (int i = 110; i < 110 + n; ++i)
		cont.push_front(ft::to_string(i, 10));
	print_cont(cont);
}

template<typename T>
void	list_test_resize(T & cont, int n)
{
	cont.resize(n);
	print_cont(cont);
}

template < typename T >
void	list_push_pop_resize()
{
	typedef typename ft::what_type<T>::type what_type;
	print_test_name("\n\n---------------*** TEST: ", what_type());
	typedef typename ft::is_string<T>::type is_string;

	std::list<T> st_2;
	fill_list(st_2, 5);

	ft::list<T> ft_2;
	fill_list(ft_2, 5);

	print_cont(st_2);
	print_cont(ft_2);

	std::cout << "max_size:" << st_2.max_size() << "\n";
	std::cout << "max_size:" << ft_2.max_size() << "\n";

	std::cout << "\n--- push_back 1" << std::endl;
	list_test_push_back(st_2, is_string());
	list_test_push_back(ft_2, is_string());

	std::cout << "\n--- pop_front" << std::endl;
	list_test_pop_front(st_2);
	list_test_pop_front(ft_2);

	std::cout << "\n--- push_back 2" << std::endl;
	list_test_push_back(st_2, is_string());
	list_test_push_back(ft_2, is_string());

	std::cout << "\n--- pop_back" << std::endl;
	list_test_pop_back(st_2, 5);
	list_test_pop_back(ft_2, 5);

	std::cout << "\n--- push_front" << std::endl;
	list_test_push_front(st_2, 3, is_string());
	list_test_push_front(ft_2, 3, is_string());


	std::cout << "\n--- resize 4" << std::endl;
	list_test_resize(st_2, 4);
	list_test_resize(ft_2, 4);


	std::cout << "\n--- resize 17" << std::endl;
	list_test_resize(st_2, 17);
	list_test_resize(ft_2, 17);

std::cout << "\nfront: " << st_2.front() << "\n";
std::cout << "front: " << ft_2.front() << "\n";
std::cout << "back: " << st_2.back() << "\n";
std::cout << "back: " << ft_2.back() << "\n";

std::cout << "size: " << st_2.size() << "\n";
std::cout << "size: " << ft_2.size() << "\n";

	std::cout << "\n--- resize 0" << std::endl;
	list_test_resize(st_2, 0);
	list_test_resize(ft_2, 0);

std::cout << "empty: " << st_2.empty() << "\n";
std::cout << "empty: " << ft_2.empty() << "\n";

std::cout << "size: " << st_2.size() << "\n";
std::cout << "size: " << ft_2.size() << "\n";
}


std::string	define_type(ft::int_type){ return "INT";}
std::string	define_type(ft::char_type){ return "CHAR";}
std::string	define_type(ft::string_type){ return "STRING";}
std::string	define_type(ft::long_type){ return "LONG";}
std::string	define_type(ft::undef_type){ return "COMPLEX";}

template < typename T >
void	test_list_iterators_simple_obj()
{
	typedef typename ft::what_type<T>::type what_type;
std::cout << YELLOW << "\n\n***--- LIST ITERATORS. TYPE: " << define_type(what_type()) << RESET << std::endl;
	std::list<T> st;
	fill_list(st, 3);

	ft::list<T> ft;
	fill_list(ft, 3);

std::cout << BLUE << "\n***------------------------- 1 list <> iterator" << RESET << std::endl;
	print_cont(st);
	print_cont(ft);

std::cout << BLUE << "\n***------------------------- 2 list <> reverse_iterator" << RESET << std::endl;
	print_rev_cont(st);
	print_rev_cont(ft);

	std::list<T> const stconst(st);
	ft::list<T> const ftconst(ft);

std::cout << BLUE << "\n***------------------------- 3 list <> const_iterator" << RESET << std::endl;
	print_cont(stconst);
	print_cont(ftconst);

std::cout << BLUE << "\n***------------------------- 4 list <> const_reverse_iterator" << RESET << std::endl;
	print_rev_cont(stconst);
	print_rev_cont(ftconst);
}

void	test_list_iterators_complex()
{
std::cout << YELLOW << "\n\n***--- LIST ITERATORS. TYPE: COMPLEX" << RESET << std::endl;

	std::list<temp> st_11;
	fill_list(st_11, 3);
	ft::list<temp> ft_11;
	fill_list(ft_11, 3);

	std::list<temp> const st_1(st_11);
	ft::list<temp> const ft_1(ft_11);

std::cout << BLUE << "\n***------------------------- 1 list< COMPLEX > iterator + << overload" << RESET << std::endl;
	print_cont(st_11);
	print_cont(ft_11);

std::cout << BLUE << "\n***------------------------- 2 list< COMPLEX > iterator + << overload" << RESET << std::endl;
	print_cont(st_1);
	print_cont(ft_1);

std::cout << BLUE << "\n***------------------------- 3 list< COMPLEX > reverse_iterator + << overload" << RESET << std::endl;
	print_rev_cont(st_11);
	print_rev_cont(ft_11);

std::cout << BLUE << "\n***------------------------- 4 list< COMPLEX > reverse_iterator + << overload" << RESET << std::endl;
	print_rev_cont(st_1);
	print_rev_cont(ft_1);

std::cout << BLUE << "***------------------------- 5 list< COMPLEX > iterator + << overload" << RESET << std::endl;
	print_cont_temp(st_11);
	print_cont_temp(ft_11);

std::cout << BLUE << "***------------------------- 6 list< COMPLEX > iterator + << overload" << RESET << std::endl;
	print_cont_temp(st_1);
	print_cont_temp(ft_1);

std::cout << BLUE << "***------------------------- 7 list< COMPLEX > reverse_iterator + operator ->" << RESET << std::endl;
	print_rev_cont_temp(st_11);
	print_rev_cont_temp(ft_11);

std::cout << BLUE << "***------------------------- 8 list< COMPLEX > reverse_iterator + operator ->" << RESET << std::endl;
	print_rev_cont_temp(st_1);
	print_rev_cont_temp(ft_1);
}

void	test_list_iterators()
{
	test_list_iterators_simple_obj<int>();
	test_list_iterators_simple_obj<char>();
	test_list_iterators_simple_obj<std::string>();
	test_list_iterators_complex();
}

template < typename T >
void	test_list_constructors()
{
	typedef typename ft::what_type<T>::type what_type;

std::cout << YELLOW << "\n\n***--- LIST CONSTRUCTORS. TYPE: " << define_type(what_type()) << RESET << std::endl;

std::cout << BLUE << "***------------------------- 0 list: init with 0" << RESET << std::endl;
	std::list<T> as(5);		//print_cont(as);
	ft::list<T> af(5);		//print_cont(af);
	std::cout << "Size 1: " << as.size() << "\nSize 2: " << af.size() << std::endl;

std::cout << BLUE << "\n***------------------------- 1.1 list: Copy constructor" << RESET << std::endl;
	std::list<T> st;
	fill_list(st, 3);

	ft::list<T> ft;
	fill_list(ft, 3);

	std::list<T> st_cpy(st);
	print_cont(st_cpy);

	ft::list<T> ft_cpy(ft);
	print_cont(ft_cpy);

	print_rev_cont(st_cpy);
	print_rev_cont(ft_cpy);

std::cout << BLUE << "\n***------------------------- 1.2 list: Copy constructor const" << RESET << std::endl;
	std::list<T> const st_cpy_const(st);
	print_cont(st_cpy_const);

	ft::list<T> const ft_cpy_const(ft);
	print_cont(ft_cpy_const);

	print_rev_cont(st_cpy_const);
	print_rev_cont(ft_cpy_const);

std::cout << BLUE << "***------------------------- 2.1 list: Copy constructor" << RESET << std::endl;
	std::list<T> st_cpy1 = st;
	print_cont(st_cpy1);

	ft::list<T> ft_cpy1 = ft;
	print_cont(ft_cpy1);

	print_rev_cont(st_cpy1);
	print_rev_cont(ft_cpy1);

std::cout << BLUE << "\n***------------------------- 2.2 list: Copy constructor const" << RESET << std::endl;
	std::list<T> const st_cpy1_const = st;
	print_cont(st_cpy1_const);

	ft::list<T> const ft_cpy1_const = ft;
	print_cont(ft_cpy1_const);

	print_rev_cont(st_cpy1_const);
	print_rev_cont(ft_cpy1_const);

std::cout << BLUE << "***------------------------- 3 list: Assignment operator" << RESET << std::endl;
	std::list<T> st_ass;
	st_ass = st;
	print_cont(st_ass);

	ft::list<T> ft_ass;
	ft_ass = ft;
	print_cont(ft_ass);

	print_rev_cont(st_ass);
	print_rev_cont(ft_ass);

std::cout << BLUE << "\n***------------------------- 4 list: reassign" << RESET << std::endl;
	st_ass = st_cpy1;
	ft_ass = ft_cpy1;

	print_cont(st_ass);
	print_cont(ft_ass);
}

template < typename T >
void	test_insert_2args_reg()
{
	typedef typename ft::what_type<T>::type what_type;
std::cout << YELLOW << "\n\n***--- LIST INSERT. TYPE: " << define_type(what_type()) << RESET << std::endl;

std::cout << "\n***------------------------- 0 list: original containers" << std::endl;
	std::list<T> std_1;
	fill_list(std_1, 5);
	print_cont(std_1);

	ft::list<T> ft_1;
	fill_list(ft_1, 5);
	print_cont(ft_1);

std::cout << "\n***------------------------- 1.1 list: INSERT at second pos" << std::endl;
	typename std::list<T>::iterator std_it1 = std_1.begin();
	std_it1++; std_it1++;
	std_1.insert(std_it1, 63);
	print_cont(std_1);

	typename ft::list<T>::iterator ft_it1 = ft_1.begin();
	ft_it1++; ft_it1++;
	ft_1.insert(ft_it1, 63);
	print_cont(ft_1);

std::cout << "\n***------------------------- 1.2 list: INSERT at begin pos" << std::endl;
	typename std::list<T>::iterator std_it0 = std_1.begin();
	std_1.insert(std_it0, 35);
	print_cont(std_1);

	typename ft::list<T>::iterator ft_it0 = ft_1.begin();
	ft_1.insert(ft_it0, 35);
	print_cont(ft_1);

// std::cout << "\n***------------------------- 1.1 list: INSERT at begin-- pos" << std::endl;
// 	typename std::list<T>::iterator std_it00 = std_1.begin();
// 	for (int i = 0; i < 11 ; i++)
// 		std_it00--;
// 	std_1.insert(std_it00, -5);
// 	print_cont(std_1);

// 	typename ft::list<T>::iterator ft_it00 = ft_1.begin();
// 	for (int i = 0; i < 11 ; i++)
// 		std_it00--;
// 	ft_1.insert(ft_it00, -5);
// 	print_cont(ft_1);

std::cout << "\n***------------------------- 1.3 list: INSERT at end pos" << std::endl;
	typename std::list<T>::iterator std_it_end = std_1.end();
	std_1.insert(std_it_end, 39);
	print_cont(std_1);

	typename ft::list<T>::iterator ft_it_end = ft_1.end();
	ft_1.insert(ft_it_end, 39);
	print_cont(ft_1);

// // std::cout << "\n***------------------------- 1.1 list: INSERT at end++ pos" << std::endl;
// // 	std_it_end++;
// // 	ft_it_end++;
// // 	std_1.insert(std_it_end, 9);
// // 	print_cont(std_1);
// // 	ft_1.insert(ft_it_end, 9);
// // 	print_cont(ft_1);
// 	// std::list<T> std_11;
// 	// fill_list(std_11, 3);
// 	// ft::list<T> ft_11;
// 	// fill_list(ft_11, 3);
// 	// typename std::list<T>::iterator std_it_end1 = std_11.end();
// 	// typename ft::list<T>::iterator ft_it_end1 = ft_11.end();
// 	// // std_it_end1++;
// 	// // ft_it_end1++;
// 	// std_11.insert(std_it_end1, 9);
// 	// print_cont(std_11);
// 	// ft_11.insert(ft_it_end1, 9);
// 	// print_cont(ft_11);
}

template < typename T, typename Type >
void	list_insert_range(int srcSize, int dstSize)
{
	T source;
	fill_list<Type>(source, srcSize);
	std::cout << "src \t|"; print_cont(source);

	T dest1(dstSize, '.');
	std::cout << "dest \t|"; print_cont(dest1);

	typename T::iterator pos = dest1.begin();
	if (dest1.size()) ++pos;
	typename T::iterator range_start = source.begin();
	if (source.size()) range_start++;
	typename T::iterator range_end = source.end();
	if (source.size()) range_end--;

	dest1.insert(pos, range_start, range_end);
	std::cout << "res \t|"; print_cont(dest1);
	std::cout << "\n";
}

template < typename T >
void	listlistTest_insert_range2args()
{
	typedef typename ft::what_type<T>::type what_type;
std::cout << YELLOW << "\n\n***--- LIST RANGE 2 ITERS. TYPE: " << define_type(what_type()) << RESET << std::endl;

	std::cout << "\n***------------------------- valid range in source and in dest" << std::endl;
	list_insert_range<std::list<T>, T>(5, 3);
	list_insert_range<ft::list<T>, T>(5, 3);

	std::cout << "\n***------------------------- range in sourse is empty" << std::endl;
	list_insert_range<std::list<T>, T>(2, 5);
	list_insert_range<ft::list<T>, T>(2, 5);

	std::cout << "\n***------------------------- one elem in dest" << std::endl;
	list_insert_range<std::list<T>, T>(5, 1);
	list_insert_range<ft::list<T>, T>(5, 1);//

	std::cout << "\n***------------------------- source is empty" << std::endl;
	list_insert_range<std::list<T>, T>(0, 4);
	list_insert_range<ft::list<T>, T>(0, 4);

	std::cout << "\n***------------------------- dest is empty, insert 1 node" << std::endl;
	list_insert_range<std::list<T>, T>(3, 0);//
	list_insert_range<ft::list<T>, T>(3, 0);//differs

	std::cout << "\n***------------------------- dest is empty, insert >1 nodes" << std::endl;
	list_insert_range<std::list<T>, T>(5, 0);//
	list_insert_range<ft::list<T>, T>(5, 0);//
}

template < typename T >
void	list_insert_range_3args(int contSize, int n, int val)
{
	T cont(contSize, 33);
	std::cout << "src \t|"; print_cont(cont);
	typename T::iterator ft_pos = cont.begin();
	if (cont.size()) ++ft_pos;
	cont.insert(ft_pos, n, val);
	std::cout << "res \t|"; print_cont(cont);
	std::cout << "\n";
}

template <typename T, typename Type>
void	list_test_insert_itself()
{
	T mylist;
	typename T::iterator it1,it2;

	for (int i=97; i<106; ++i) mylist.push_back(i);
	print_cont(mylist);
	it1 = it2 = mylist.begin();
	for (int i=0; i<5; i++) it2++;
	++it1;
	std::cout << "it1: " << *it1 << " it2: " << *it2 << std::endl;
	mylist.insert(it1, it1, it2);
	print_cont(mylist);
	std::cout << "\n";
}

template < typename T >
void listTest_insert_range3args()
{
	typedef typename ft::what_type<T>::type what_type;
std::cout << YELLOW << "\n\n***--- LIST RANGE 3 ARGS. TYPE: " << define_type(what_type()) << RESET << std::endl;

	std::cout << "\n***------------------------- normal case 1" << std::endl;
	list_insert_range_3args<std::list<T> >(5, 3, 111);
	list_insert_range_3args<ft::list<T> >(5, 3, 111);

	std::cout << "\n***------------------------- normal case 2: insert 1 elem" << std::endl;
	list_insert_range_3args<std::list<T> >(4, 1, 111);
	list_insert_range_3args<ft::list<T> >(4, 1, 111);

	std::cout << "\n***------------------------- normal case 3" << std::endl;
	list_insert_range_3args<std::list<T> >(1, 3, 111);
	list_insert_range_3args<ft::list<T> >(1, 3, 111);

	std::cout << "\n***------------------------- insert 0 elems" << std::endl;
	list_insert_range_3args<std::list<T> >(5, 0, 111);
	list_insert_range_3args<ft::list<T> >(5, 0, 111);

	std::cout << "\n***------------------------- insert to empty container" << std::endl;
	list_insert_range_3args<std::list<T> >(0, 3, 111);
	list_insert_range_3args<ft::list<T> >(0, 3, 111);

	std::cout << "\n***------------------------- insert from itself" << std::endl;
	list_test_insert_itself<ft::list<T>, T >();
	list_test_insert_itself<std::list<T>, T >();
}

void list_test_insert()
{
std::cout << GREEN << "\n\n***--- LIST INSERT" << RESET << std::endl;

	test_insert_2args_reg<int>();
	test_insert_2args_reg<char>();

	listlistTest_insert_range2args<int>();
	listlistTest_insert_range2args<char>();

	listTest_insert_range3args<int>();
	listTest_insert_range3args<char>();
}

template < typename T>
void	test_erase_(int delta)
{
	T mylist;
	typename T::iterator it1,it2;
	for (int i=97; i<107; ++i) mylist.push_back(i);
	print_cont(mylist);

	it1 = it2 = mylist.begin();
	std::advance (it2,delta);// for (int i=0; i<delta; i++) it2++;
	++it1;

	std::cout << "before: " << "it1: " << *it1 << "\tit2: " << *it2 << std::endl;
	it1 = mylist.erase (it1);
	it2 = mylist.erase (it2);
	std::cout << "after:  it1: " << *it1 << "\tit2: " << *it2 << std::endl;
	print_cont(mylist);

	++it1;
	--it2;

	std::cout << "before: " << "it1: " << *it1 << "\tit2: " << *it2 << std::endl;
	mylist.erase (it1,it2);
	std::cout << "after:  it1: " << *it1 << "\tit2: " << *it2 << std::endl;
	print_cont(mylist);
	std::cout << "\n";
}

template <typename T>
void	test_erase()
{
	typedef typename ft::what_type<T>::type what_type;
std::cout << YELLOW << "\n\n***--- LIST ERASE 1 ITER. TYPE: " << define_type(what_type()) << RESET << std::endl;

	// std::cout << "\n***------------------------- normal range" << std::endl;
	std::list<T> stl;
	ft::list<T> ftl;
	test_erase_<std::list<T> >(7);
	test_erase_<ft::list<T> >(7);

	// std::cout << "\n***------------------------- strange range" << std::endl;
	// test_erase_<std::list<T> >(15);
	// test_erase_<ft::list<T> >(15);
}

template <typename T>
void	test_swap_()
{
	T first (3,33);	 // three ints with a value of 100
	T second (5,111);	// five ints with a value of 200

	first.swap(second);

	std::cout << "first contains: \t";
	for (typename T::iterator it=first.begin(); it!=first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "second contains:\t";
	for (typename T::iterator it=second.begin(); it!=second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

template <typename T>
void	test_swap()
{
	typedef typename ft::what_type<T>::type what_type;
std::cout << YELLOW << "\n\n***--- LIST SWAP 1 ITER. TYPE: " << define_type(what_type()) << RESET << std::endl;

	std::list<T> stl;
	ft::list<T> ftl;
	test_swap_<std::list<T> >();
	test_swap_<ft::list<T> >();
}

template <typename T>
void	test_splice_()
{
	T mylist1, mylist2;
	typename T::iterator it;

	for (int i=1; i<=4; ++i)
		 mylist1.push_back(i);      // mylist1: 1 2 3 4
	for (int i=1; i<=3; ++i)
		 mylist2.push_back(i*10);   // mylist2: 10 20 30
	it = mylist1.begin();
	++it;                           // points to 2

	mylist1.splice(it, mylist2);    // mylist1: 1 10 20 30 2 3 4
                                    // mylist2 (empty)
                                    // "it" still points to 2 (the 5th element)
	mylist2.splice(mylist2.begin(), mylist1, it);
                                // mylist1: 1 10 20 30 3 4
                                // mylist2: 2
                                // "it" is now invalid.
	it = mylist1.begin();
	std::advance(it,3);           // "it" points now to 30

	mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
                                // mylist1: 30 3 4 1 10 20

	std::cout << "mylist1 contains:\t";
	print_cont(mylist1);
	std::cout << "mylist2 contains:\t";
	print_cont(mylist2);
	std::cout << "\n";
}

template <typename T>
void	test_splice()
{
	typedef typename ft::what_type<T>::type what_type;
std::cout << YELLOW << "\n\n***--- LIST SPLICE 1 ITER. TYPE: " << define_type(what_type()) << RESET << std::endl;

	std::list<T> stl;
	ft::list<T> ftl;
	test_splice_<std::list<T> >();
	test_splice_<ft::list<T> >();
}

template < typename T >
bool	predicate(T const & obj)
{
	T copy(obj);
	return copy == obj;
}

// a predicate implemented as a function:
bool single_digit (const int & value) { return (value < 10); }

// a predicate implemented as a class:
struct is_odd {
	bool operator() (const int & value) { return (value % 2) == 1; }
};

template < typename T >
void test_remove_()
{
	int myints[]= {17,89,7,14, 89, 89};
	T mylist(myints, myints + 6);
	mylist.remove(89);
	print_cont(mylist);
	std::cout << '\n';
}

template < typename T >
void test_remove_if()
{
	int myints[]= {15,36,7,17,20,39,4,1};
	T mylist (myints,myints+8);
	std::cout << "before:\t"; print_cont(mylist);
	mylist.remove_if (single_digit);
	std::cout << "> 10:\t"; print_cont(mylist);
	mylist.remove_if (is_odd());
	std::cout << "even:\t"; print_cont(mylist);
	std::cout << '\n';
}

template < typename T >
void test_remove()
{
	typedef typename ft::what_type<T>::type what_type;
std::cout << YELLOW << "\n\n***--- LIST REMOVE, REMOVE IF. TYPE: " << define_type(what_type()) << RESET << std::endl;

	std::cout << "\n***------------------------- remove" << std::endl;
	test_remove_<std::list<T> >();
	test_remove_<ft::list<T> >();

	std::cout << "\n***------------------------- remove if" << std::endl;
	test_remove_if<std::list<T> >();
	test_remove_if<ft::list<T> >();
}

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

template < typename T >
void	test_unique_()
{
	double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
	                     12.77, 73.35, 72.25, 15.3,  72.25, 16.1};
	// double mydoubles[]={ 2.72, 3.14, 12.15, 12.77, 12.77, 15.3, 16.1, 72.25, 72.25, 73, 73.35 };
	T mylist(mydoubles, mydoubles+11);

	// mylist.sort();
	print_cont(mylist);

	mylist.unique();
	print_cont(mylist);

	mylist.unique (same_integral_part);
	print_cont(mylist);

	mylist.unique (is_near());
	print_cont(mylist);
	std::cout << '\n';
}

void	test_unique()
{
std::cout << YELLOW << "\n\n***--- LIST UNIQUE" << RESET << std::endl;
	test_unique_<std::list<double> >();
	test_unique_<ft::list<double> >();
}

template < typename T >
void	test_reverse_()
{
	T mylist;
	for (int i=1; i<10; ++i) mylist.push_back(i);
	mylist.reverse();
	print_cont(mylist);
}

void	test_reverse()
{
std::cout << YELLOW << "\n\n***--- LIST REVERSE" << RESET << std::endl;
	test_reverse_<std::list<int> >();
	test_reverse_<ft::list<int> >();
}

// compare only integral part:
bool mycomparison_integral (double first, double second)
{ return ( int(first) < int(second) ); }

template < typename T >
void	test_merge_()
{
	T first, second;

	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.5);

	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);

	first.sort();
	second.sort();

	print_cont(first);
	print_cont(second);
	std::cout << "\n";

	first.merge(second);
	print_cont(first);
	print_cont(second);

	second.push_back (2.1);
	first.merge(second, mycomparison_integral);
	print_cont(first);
	print_cont(second);

	std::cout << "merging to empty container:\n";
	T third;
	third.merge(second);
	print_cont(first);
	print_cont(second);
	print_cont(third);
}

void	test_merge()
{
std::cout << YELLOW << "\n\n***--- LIST MERGE" << RESET << std::endl;
	test_merge_<std::list<double> >();
	test_merge_<ft::list<double> >();
}

// comparison, not case sensitive.
bool	compare_nocase(const std::string & first, const std::string & second)
{
	unsigned int i = 0;
	while ((i < first.length()) && (i < second.length()))
	{
		if (tolower(first[i]) < tolower(second[i])) return true;
		else if (tolower(first[i]) > tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

template < typename T >
void	test_sort_(std::string)
{
	std::list<std::string> mylist;
	std::list<std::string>::iterator it;
	mylist.push_back ("one");
	mylist.push_back ("two");
	mylist.push_back ("Three");
	mylist.push_back ("Threeee");

	mylist.sort();
	print_cont(mylist);

	mylist.sort(compare_nocase);
	print_cont(mylist);
	std::cout << "\n";
}

template < typename T >
void	test_sort_()
{
	int myints[] = { 10, 3, 6, 8, 5, 2, 1, 4, 7, 9 };
	T list(myints, myints + 10);
	print_cont(list);
	list.sort();
	print_cont(list);
	std::cout << "\n";
}

void	test_sort()
{
std::cout << YELLOW << "\n\n***--- LIST SORT" << RESET << std::endl;
	test_sort_<std::list<int> >();
	test_sort_<ft::list<int> >();

	std::string str;
	test_sort_<std::list<std::string> >(str);
	test_sort_<ft::list<std::string> >(str);
}

template < typename T>
void	test_assign_()
{
	T first;
	T second;

	std::cout << "\n***------------------------- assign 2 args" << std::endl;
	first.assign (7,100);
	print_cont(first);

	std::cout << "\n***------------------------- assign iterators" << std::endl;
	int myints[]={1776,7,15, 104};
	first.assign (myints, myints+4);
	print_cont(first);
	second.assign (first.begin(), --first.end());
	print_cont(second);

	std::cout << "\nsize of first:   " << int (first.size()) << '\t';
	std::cout << "size of second:  " << int (second.size()) << '\n';
	std::cout << "front() first:   " << first.front() << '\t';
	std::cout << "back() first:    " << first.back() << '\n';

	first.pop_back();
	first.pop_front();
	print_cont(first);
	std::cout << "size of first:   " << int (first.size()) << '\t';
	std::cout << "front() first:   " << first.front() << '\t';
	std::cout << "back() first:    " << first.back() << '\n';
	std::cout << '\n';

}

template < typename T>
void	test_sizes()
{
	int myints[]={1776, 70, 46, 55, 65};
	T first(myints, myints + 5);
	print_cont(first);

	std::cout << "size of first: " << int (first.size()) << '\n';
	std::cout << "empty() first: " << first.empty() << '\n';
	first.clear();
	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "empty() first: " << first.empty() << '\n';
	std::cout << '\n';
}

void	test_contents()
{
std::cout << YELLOW << "\n\n***--- LIST: ASSIGN SIZE POPS" << RESET << std::endl;
	test_assign_<std::list<int> >();
	test_assign_<ft::list<int> >();

std::cout << YELLOW << "\n\n***--- LIST: SIZE CLEAR EMPTY" << RESET << std::endl;
	test_sizes<std::list<int> >();
	test_sizes<ft::list<int> >();
}

void	test_non_member()
{
std::cout << YELLOW << "\n\n***--- LIST: NON_MEMBER" << RESET << std::endl;
	std::list<size_t> st_a(5, 10);
	std::list<size_t> st_b(st_a);

	ft::list<size_t> ft_a(5, 10);
	ft::list<size_t> ft_b(ft_a);

	if (st_a == st_b) std::cout << GREEN << "a == b" << RESET << "\t";
	if (ft_a == ft_b) std::cout << BLUE << "a == b" << RESET << "\n";

	st_b.push_back(3);
	ft_b.push_back(3);

	print_cont(st_a);
	print_cont(ft_a);
	print_cont(st_b);
	print_cont(ft_b);

	if (st_b >= st_a)	std::cout << GREEN << "b >= a" << RESET << "\t";
	if (ft_b >= ft_a)	std::cout << BLUE << "b >= a" << RESET << "\n";
	if (st_b > st_a)	std::cout << GREEN << "b > a" << RESET << "\t";
	if (ft_b > ft_a)	std::cout << BLUE << "b > a" << RESET << "\n";
	if (st_b != st_a)	std::cout << GREEN << "b != a" << RESET << "\t";
	if (ft_b != ft_a)	std::cout << BLUE << "b != a" << RESET << "\n";

	st_a.pop_back(); print_cont(st_a);
	ft_a.pop_back(); print_cont(ft_a);
	st_b.pop_back(); print_cont(st_b);
	ft_b.pop_back(); print_cont(ft_b);
	if (st_a <= st_b)	std::cout << GREEN << "a <= b" << RESET << "\t";
	if (ft_a <= ft_b)	std::cout << BLUE << "a <= b" << RESET << "\n";
	if (st_a < st_b)	std::cout << GREEN << "a < b" << RESET << "\t";
	if (ft_a < ft_b)	std::cout << BLUE << "a < b" << RESET << "\n";

}
void	test_all_kinds_of_iters()
{
std::cout << YELLOW << "\n\n***--- LIST: ALL KIND OF ITERS" << RESET << std::endl;
	std::cout << BLUE << "\n***------------------------- iters on normal obj" << RESET << std::endl;

	ft::list<size_t> ft_list_s(5, 21);
	std::list<size_t> std_list_s(5, 21);

	ft::list<size_t>::iterator ft_it = ft_list_s.begin();
	std::list<size_t>::iterator st_it = std_list_s.begin();

	ft::list<size_t>::const_iterator ft_it_const = ft_list_s.begin();
	std::list<size_t>::const_iterator st_it_const = std_list_s.begin();

	ft::list<size_t>::reverse_iterator ft_it_r = ft_list_s.rbegin();
	std::list<size_t>::reverse_iterator st_it_r = std_list_s.rbegin();

	ft::list<size_t>::const_reverse_iterator ft_it_const_r = ft_list_s.rbegin();
	std::list<size_t>::const_reverse_iterator st_it_const_r = std_list_s.rbegin();

	*++ft_it = 5;
	*++st_it = 5;

	// *++ft_it_const = 5;// should not work
	// *++st_it_const = 5;// should not work

	std::cout << "ft_it_r: " << *ft_it_r << "\n";
	std::cout << "st_it_r: " << *st_it_r << "\n---\n";
	*++ft_it_r = 7;
	*++st_it_r = 7;
	std::cout << "ft_it_r: " << *ft_it_r << "\n";
	std::cout << "st_it_r: " << *st_it_r << "\n---\n";
	// *ft_it_const_r = 5;// should not work
	// *st_it_const_r = 5;// should not work
	std::cout << "ft_it_const_r: " << *ft_it_const_r << "\n";
	std::cout << "st_it_const_r: " << *st_it_const_r << "\n---\n";
	std::cout << "ft_it_const_r: " << *++ft_it_const_r << "\n";
	std::cout << "st_it_const_r: " << *++st_it_const_r << "\n";
	print_cont(ft_list_s);
	print_cont(std_list_s);

	std::cout << BLUE << "\n***------------------------- COPY constructors of iters on normal obj" << RESET << std::endl;

	ft::list<size_t>::iterator ft_it_cpy(ft_it);
	std::list<size_t>::iterator st_it_cpy(st_it);

	ft::list<size_t>::const_iterator ft_it_const_cpy(ft_it_const);
	std::list<size_t>::const_iterator st_it_const_cpy(st_it_const);

	ft::list<size_t>::reverse_iterator ft_it_r_cpy(ft_it_r);
	std::list<size_t>::reverse_iterator st_it_r_cpy(st_it_r);

	ft::list<size_t>::const_reverse_iterator ft_it_const_r_cpy(ft_it_const_r);
	std::list<size_t>::const_reverse_iterator st_it_const_r_cpy(st_it_const_r);

	std::cout << *ft_it_cpy << "\t" << *st_it_cpy << "\n";
	std::cout << *ft_it_const_cpy << "\t" << *st_it_const_cpy << "\n";
	std::cout << *ft_it_r_cpy << "\t" << *st_it_r_cpy << "\n";
	std::cout << *ft_it_const_r_cpy << "\t" << *st_it_const_r_cpy << "\n";


	std::cout << BLUE << "\n***------------------------- iters on CONST obj" << RESET << std::endl;

	ft::list<size_t> const ft_const_X(ft_list_s);
	std::list<size_t> const std_const_X(std_list_s);

	// ft::list<size_t>::iterator ft_it_X = ft_const_X.begin();// should not work
	// std::list<size_t>::iterator st_it_X = std_const_X.begin();// should not work

	ft::list<size_t>::const_iterator ft_it_const_X = ft_const_X.begin();
	std::list<size_t>::const_iterator st_it_const_X = std_const_X.begin();

	// ft::list<size_t>::reverse_iterator ft_it_X_r = ft_const_X.rbegin();// same as std: should not work
	// std::list<size_t>::reverse_iterator st_it_X_r = std_const_X.rbegin();// same as std: should not work

	ft::list<size_t>::const_reverse_iterator ft_it_const_X_r = ft_const_X.rbegin();
	std::list<size_t>::const_reverse_iterator st_it_const_X_r = std_const_X.rbegin();

	// // *++ft_it_X = 5;// should not work
	// // *++st_it_X = 5;// should not work

	// // *++ft_it_const_X = 5;// should not work
	// // *++st_it_const_X = 5;// should not work

	std::cout << "ft_it_const_X: " << *ft_it_const_X << "\n";
	std::cout << "st_it_const_X: " << *st_it_const_X << "\n---\n";
	std::cout << "ft_it_const_X: " << *++ft_it_const_X << "\n";
	std::cout << "st_it_const_X: " << *++st_it_const_X << "\n---\n";

	// *++ft_it_X_r = 8;// same as std: should not work
	// *++st_it_X_r = 8;// same as std: should not work

	// // *++ft_it_const_X_r = 5;// should not work
	// // *++st_it_const_X_r = 5;// should not work
	std::cout << "ft_it_const_X_r: " << *ft_it_const_X_r << "\n";
	std::cout << "st_it_const_X_r: " << *st_it_const_X_r << "\n---\n";
	std::cout << "ft_it_const_X_r: " << *++ft_it_const_X_r << "\n";
	std::cout << "st_it_const_X_r: " << *++st_it_const_X_r << "\n---\n";
	print_cont(ft_const_X);
	print_cont(std_const_X);

	std::cout << BLUE << "\n***------------------------- COPY constructors of iters on const obj" << RESET << std::endl;

	ft::list<size_t>::const_iterator ft_it_const_X_cpy(ft_it_const_X);
	std::list<size_t>::const_iterator st_it_const_X_cpy(st_it_const_X);

	ft::list<size_t>::const_reverse_iterator ft_it_const_X_r_cpy(ft_it_const_X_r);
	std::list<size_t>::const_reverse_iterator st_it_const_X_r_cpy(st_it_const_X_r);

	std::cout << *ft_it_const_X_cpy << " " << *ft_it_const_X_r_cpy << "\n";
	std::cout << *st_it_const_X_cpy << " " << *st_it_const_X_r_cpy << "\n";
}

int main()
{
std::cout << GREEN << "\n\n***--- LIST CONSTRUCTORS" << RESET << std::endl;
	test_list_constructors<int>();
	test_list_constructors<char>();
	test_list_constructors<std::string>();
	test_list_constructors<temp>();

std::cout << GREEN << "\n\n***--- LIST ITERATORS" << RESET << std::endl;
	test_list_iterators();
	test_all_kinds_of_iters();

	test_contents();

	list_push_pop_resize<int>();
	list_push_pop_resize<char>();
	list_push_pop_resize<std::string>();

	list_test_insert();

	test_erase<int>();
	test_erase<char>();

	test_swap<int>();
	test_swap<char>();

	test_splice<int>();

	test_remove<int>();

	test_unique();

	test_reverse();

	test_merge();

	test_sort();

	test_non_member();
}
