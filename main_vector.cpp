#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

#include "vector.h"

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
void	fill_vector(std::vector<T> & vector, int num)
{
	for (int i = 111; i < 111 + num; i++)
		vector.push_back(i);
}

template < typename T >
void	fill_vector(ft::vector<T> & vector, int num)
{
	for (int i = 111; i < 111 + num; i++)
		vector.push_back(i);
}

void	fill_vector(ft::vector<temp> & vector, int num)
{
	temp array[] = {temp(1, "aaa"), temp(2, "bbb"), temp(3, "ccc")};
	for (int i = 0; i < num; i++)
		vector.push_back(array[i]);
}

void	fill_vector(std::vector<temp> & vector, int num)
{
	temp array[] = {temp(1, "aaa"), temp(2, "bbb"), temp(3, "ccc")};
	for (int i = 0; i < num; i++)
		vector.push_back(array[i]);
}

void	fill_vector(ft::vector<std::string> & vector, int num)
{
	(void)num;
	std::string array[] = {"aaa", "bbb", "ccc"};
	for (int i = 0; i < 3; i++)
		vector.push_back(array[i]);
}

void	fill_vector(std::vector<std::string> & vector, int num)
{
	(void)num;
	std::string array[] = {"aaa", "bbb", "ccc"};
	for (int i = 0; i < 3; i++)
		vector.push_back(array[i]);
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
void	vector_test_push_back(T & cont, ft::notstr_type)
{
	for (int i = 97; i < 105; ++i)
			cont.push_back(i);
	print_cont(cont);
}

template<typename T>
void	vector_test_push_back(T & cont, ft::str_type)
{
	for (int i = 97; i < 105; ++i)
		cont.push_back(ft::to_string(i, 10));
	print_cont(cont);
}

template<typename T>
void	vector_test_pop_back(T & cont, int n)
{
	for (int i = 0; i < n; ++i)
		cont.pop_back();
	print_cont(cont);
}

template<typename T>
void	vector_test_resize(T & cont, int n)
{
	cont.resize(n);
	print_cont(cont);
}

template < typename T >
void	vector_push_pop_resize()
{
	typedef typename ft::what_type<T>::type what_type;
	print_test_name("\n\n---------------*** TEST: ", what_type());
	typedef typename ft::is_string<T>::type is_string;

	std::vector<T> st_2;
	fill_vector(st_2, 5);

	ft::vector<T> ft_2;
	fill_vector(ft_2, 5);

	print_cont(st_2);
	print_cont(ft_2);

	std::cout << "max_size:" << st_2.max_size() << "\n";
	std::cout << "max_size:" << ft_2.max_size() << "\n";

	std::cout << "\n--- push_back 1" << std::endl;
	vector_test_push_back(st_2, is_string());
	vector_test_push_back(ft_2, is_string());

	std::cout << "\n--- push_back 2" << std::endl;
	vector_test_push_back(st_2, is_string());
	vector_test_push_back(ft_2, is_string());

	std::cout << "max_size:" << st_2.max_size() << "\n";
	std::cout << "max_size:" << ft_2.max_size() << "\n";

	std::cout << "\n--- pop_back" << std::endl;
	vector_test_pop_back(st_2, 5);
	vector_test_pop_back(ft_2, 5);

	std::cout << "\n--- resize 4" << std::endl;
	vector_test_resize(st_2, 4);
	vector_test_resize(ft_2, 4);

	std::cout << "max_size:" << st_2.max_size() << "\n";
	std::cout << "max_size:" << ft_2.max_size() << "\n";

	std::cout << "\n--- resize 17" << std::endl;
	vector_test_resize(st_2, 17);
	vector_test_resize(ft_2, 17);

	std::cout << "max_size:" << st_2.max_size() << "\n";
	std::cout << "max_size:" << ft_2.max_size() << "\n";

	std::cout << "\nfront: " << st_2.front() << "\n";
	std::cout << "front: " << ft_2.front() << "\n";
	std::cout << "back: " << st_2.back() << "\n";
	std::cout << "back: " << ft_2.back() << "\n";

	std::cout << "size: " << st_2.size() << "\n";
	std::cout << "size: " << ft_2.size() << "\n";

	std::cout << "\n--- resize 0" << std::endl;
	vector_test_resize(st_2, 0);
	vector_test_resize(ft_2, 0);

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
void	test_vector_iterators_simple_obj()
{
	typedef typename ft::what_type<T>::type what_type;
std::cout << YELLOW << "\n\n***--- vector ITERATORS. TYPE: " << define_type(what_type()) << RESET << std::endl;
	std::vector<T> st;
	fill_vector(st, 3);

	ft::vector<T> ft;
	fill_vector(ft, 3);

std::cout << BLUE << "\n***------------------------- 1 vector <> iterator" << RESET << std::endl;
	print_cont(st);
	print_cont(ft);

std::cout << BLUE << "\n***------------------------- 2 vector <> reverse_iterator" << RESET << std::endl;
	print_rev_cont(st);
	print_rev_cont(ft);

	std::vector<T> const stconst(st);
	ft::vector<T> const ftconst(ft);

std::cout << BLUE << "\n***------------------------- 3 vector <> const_iterator" << RESET << std::endl;
	print_cont(stconst);
	print_cont(ftconst);

std::cout << BLUE << "\n***------------------------- 4 vector <> const_reverse_iterator" << RESET << std::endl;
	print_rev_cont(stconst);
	print_rev_cont(ftconst);
}

void	test_vector_iterators_complex()
{
std::cout << YELLOW << "\n\n***--- vector ITERATORS. TYPE: COMPLEX" << RESET << std::endl;

	std::vector<temp> st_11;
	fill_vector(st_11, 3);
	ft::vector<temp> ft_11;
	fill_vector(ft_11, 3);

	std::vector<temp> const st_1(st_11);
	ft::vector<temp> const ft_1(ft_11);

std::cout << BLUE << "\n***------------------------- 1 vector< COMPLEX > iterator + << overload" << RESET << std::endl;
	print_cont(st_11);
	print_cont(ft_11);

std::cout << BLUE << "\n***------------------------- 2 vector< COMPLEX > iterator + << overload" << RESET << std::endl;
	print_cont(st_1);
	print_cont(ft_1);

std::cout << BLUE << "\n***------------------------- 3 vector< COMPLEX > reverse_iterator + << overload" << RESET << std::endl;
	print_rev_cont(st_11);
	print_rev_cont(ft_11);

std::cout << BLUE << "\n***------------------------- 4 vector< COMPLEX > reverse_iterator + << overload" << RESET << std::endl;
	print_rev_cont(st_1);
	print_rev_cont(ft_1);

std::cout << BLUE << "***------------------------- 5 vector< COMPLEX > iterator + << overload" << RESET << std::endl;
	print_cont_temp(st_11);
	print_cont_temp(ft_11);

std::cout << BLUE << "***------------------------- 6 vector< COMPLEX > iterator + << overload" << RESET << std::endl;
	print_cont_temp(st_1);
	print_cont_temp(ft_1);

std::cout << BLUE << "***------------------------- 7 vector< COMPLEX > reverse_iterator + operator ->" << RESET << std::endl;
	print_rev_cont_temp(st_11);
	print_rev_cont_temp(ft_11);

std::cout << BLUE << "***------------------------- 8 vector< COMPLEX > reverse_iterator + operator ->" << RESET << std::endl;
	print_rev_cont_temp(st_1);
	print_rev_cont_temp(ft_1);
}

void	test_vector_iterators()
{
	test_vector_iterators_simple_obj<int>();
	test_vector_iterators_simple_obj<char>();
	test_vector_iterators_simple_obj<std::string>();
	test_vector_iterators_complex();
}

template < typename T >
void	test_vector_constructors()
{
	typedef typename ft::what_type<T>::type what_type;

std::cout << YELLOW << "\n\n***--- vector CONSTRUCTORS. TYPE: " << define_type(what_type()) << RESET << std::endl;

std::cout << BLUE << "***------------------------- 0 vector: init with 0" << RESET << std::endl;
	std::vector<T> as(5);		//print_cont(as);
	ft::vector<T> af(5);		//print_cont(af);
	std::cout << "Size 1: " << as.size() << "\nSize 2: " << af.size() << std::endl;

std::cout << BLUE << "\n***------------------------- 1.1 vector: Copy constructor" << RESET << std::endl;
	std::vector<T> st;
	fill_vector(st, 3);

	ft::vector<T> ft;
	fill_vector(ft, 3);

	std::vector<T> st_cpy(st);
	print_cont(st_cpy);

	ft::vector<T> ft_cpy(ft);
	print_cont(ft_cpy);

	print_rev_cont(st_cpy);
	print_rev_cont(ft_cpy);

std::cout << BLUE << "\n***------------------------- 1.2 vector: Copy constructor const" << RESET << std::endl;
	std::vector<T> const st_cpy_const(st);
	print_cont(st_cpy_const);

	ft::vector<T> const ft_cpy_const(ft);
	print_cont(ft_cpy_const);

	print_rev_cont(st_cpy_const);
	print_rev_cont(ft_cpy_const);

std::cout << BLUE << "***------------------------- 2.1 vector: Copy constructor" << RESET << std::endl;
	std::vector<T> st_cpy1 = st;
	print_cont(st_cpy1);

	ft::vector<T> ft_cpy1 = ft;
	print_cont(ft_cpy1);

	print_rev_cont(st_cpy1);
	print_rev_cont(ft_cpy1);

std::cout << BLUE << "\n***------------------------- 2.2 vector: Copy constructor const" << RESET << std::endl;
	std::vector<T> const st_cpy1_const = st;
	print_cont(st_cpy1_const);

	ft::vector<T> const ft_cpy1_const = ft;
	print_cont(ft_cpy1_const);

	print_rev_cont(st_cpy1_const);
	print_rev_cont(ft_cpy1_const);

std::cout << BLUE << "***------------------------- 3 vector: Assignment operator" << RESET << std::endl;
	std::vector<T> st_ass;
	st_ass = st;
	print_cont(st_ass);

	ft::vector<T> ft_ass;
	ft_ass = ft;
	print_cont(ft_ass);

	print_rev_cont(st_ass);
	print_rev_cont(ft_ass);

std::cout << BLUE << "\n***------------------------- 4 vector: reassign" << RESET << std::endl;
	st_ass = st_cpy1;
	ft_ass = ft_cpy1;

	print_cont(st_ass);
	print_cont(ft_ass);

// std::cout << BLUE << "\n***------------------------- 5 vector: constructor with iterators" << RESET << std::endl;
// 	std::vector<T> st_it;	fill_vector(st_it, 8);
// 	ft::vector<T> ft_it;	fill_vector(ft_it, 8);
// 	print_cont(st_it);
// 	print_cont(ft_it);
// 	typename std::vector<T>::iterator st_iter = st_it.begin(); ++st_iter;
// 	typename ft::vector<T>::iterator ft_iter = ft_it.begin(); ++ft_iter;
// 	typename std::vector<T>::iterator st_iterend = st_it.begin(); --st_iterend;
// 	typename ft::vector<T>::iterator ft_iterend = ft_it.begin(); --ft_iterend;
// 	std::vector<T> st_ass1(st_iter, st_iterend);
	// ft::vector<T> ft_ass1(ft_iter, ft_iterend);
	// print_cont(st_ass1);
	// print_cont(ft_ass1);
	// print_cont(st_it);
	// print_cont(ft_it);
// 	st_ass_iter = st_cpy1;
// 	ft_ass_iter = ft_cpy1;
// 	print_cont(st_ass_iter);
// 	print_cont(ft_ass_iter);
}

template < typename T >
void	test_insert_2args_reg()
{
	typedef typename ft::what_type<T>::type what_type;
std::cout << GREEN << "\n\n***--- vector INSERT. TYPE: " << define_type(what_type()) << RESET << std::endl;

std::cout << BLUE << "\n***------------------------- 0 vector: original containers" << RESET << std::endl;
	std::vector<T> std_1;
	fill_vector(std_1, 5);
	print_cont(std_1);

	ft::vector<T> ft_1;
	fill_vector(ft_1, 5);
	print_cont(ft_1);

std::cout << BLUE << "\n***------------------------- 1.1 vector: INSERT at second pos" << RESET << std::endl;
	typename std::vector<T>::iterator std_it1 = std_1.begin();
	std_it1++; std_it1++;
	std_1.insert(std_it1, 63);
	print_cont(std_1);

	typename ft::vector<T>::iterator ft_it1 = ft_1.begin();
	ft_it1++; ft_it1++;
	ft_1.insert(ft_it1, 63);
	print_cont(ft_1);

std::cout << BLUE << "\n***------------------------- 1.2 vector: INSERT at begin pos" << RESET << std::endl;
	typename std::vector<T>::iterator std_it0 = std_1.begin();
	std_1.insert(std_it0, 35);
	print_cont(std_1);

	typename ft::vector<T>::iterator ft_it0 = ft_1.begin();
	ft_1.insert(ft_it0, 35);
	print_cont(ft_1);

// std::cout << BLUE << "\n***------------------------- 1.1 vector: INSERT at begin-- pos" << RESET << std::endl;
// 	typename std::vector<T>::iterator std_it00 = std_1.begin();
// 	for (int i = 0; i < 11 ; i++)
// 		std_it00--;
// 	std_1.insert(std_it00, -5);
// 	print_cont(std_1);

// 	typename ft::vector<T>::iterator ft_it00 = ft_1.begin();
// 	for (int i = 0; i < 11 ; i++)
// 		std_it00--;
// 	ft_1.insert(ft_it00, -5);
// 	print_cont(ft_1);

std::cout << BLUE << "\n***------------------------- 1.3 vector: INSERT at end pos" << RESET << std::endl;
	typename std::vector<T>::iterator std_it_end = std_1.end();
	std_1.insert(std_it_end, 39);
	print_cont(std_1);

	typename ft::vector<T>::iterator ft_it_end = ft_1.end();
	ft_1.insert(ft_it_end, 39);
	print_cont(ft_1);

// // std::cout << BLUE << "\n***------------------------- 1.1 vector: INSERT at end++ pos" << RESET << std::endl;
// // 	std_it_end++;
// // 	ft_it_end++;
// // 	std_1.insert(std_it_end, 9);
// // 	print_cont(std_1);
// // 	ft_1.insert(ft_it_end, 9);
// // 	print_cont(ft_1);
// 	// std::vector<T> std_11;
// 	// fill_vector(std_11, 3);
// 	// ft::vector<T> ft_11;
// 	// fill_vector(ft_11, 3);
// 	// typename std::vector<T>::iterator std_it_end1 = std_11.end();
// 	// typename ft::vector<T>::iterator ft_it_end1 = ft_11.end();
// 	// // std_it_end1++;
// 	// // ft_it_end1++;
// 	// std_11.insert(std_it_end1, 9);
// 	// print_cont(std_11);
// 	// ft_11.insert(ft_it_end1, 9);
// 	// print_cont(ft_11);
}

template < typename T, typename Type >
void	vector_insert_range(int srcSize, int dstSize)
{
	T source;
	fill_vector<Type>(source, srcSize);
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
void	vectorvectorTest_insert_range2args()
{
	typedef typename ft::what_type<T>::type what_type;
std::cout << GREEN << "\n\n***--- vector RANGE 2 ITERS. TYPE: " << define_type(what_type()) << RESET << std::endl;

	std::cout << BLUE << "\n***------------------------- valid range in source and in dest" << RESET << std::endl;
	vector_insert_range<std::vector<T>, T>(5, 3);
	vector_insert_range<ft::vector<T>, T>(5, 3);

	std::cout << BLUE << "\n***------------------------- range in sourse is empty" << RESET << std::endl;
	vector_insert_range<std::vector<T>, T>(2, 5);
	vector_insert_range<ft::vector<T>, T>(2, 5);

	std::cout << BLUE << "\n***------------------------- one elem in dest" << RESET << std::endl;
	vector_insert_range<std::vector<T>, T>(5, 1);
	vector_insert_range<ft::vector<T>, T>(5, 1);//

	std::cout << BLUE << "\n***------------------------- source is empty" << RESET << std::endl;
	vector_insert_range<std::vector<T>, T>(0, 4);
	vector_insert_range<ft::vector<T>, T>(0, 4);

	std::cout << BLUE << "\n***------------------------- dest is empty, insert 1 node" << RESET << std::endl;
	vector_insert_range<std::vector<T>, T>(3, 0);//
	vector_insert_range<ft::vector<T>, T>(3, 0);//differs

	std::cout << BLUE << "\n***------------------------- dest is empty, insert >1 nodes" << RESET << std::endl;
	vector_insert_range<std::vector<T>, T>(5, 0);//
	vector_insert_range<ft::vector<T>, T>(5, 0);//
}

template < typename T >
void	vector_insert_range_3args(int contSize, int n, int val)
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
void	vector_test_insert_itself()
{
	T myvector;
	typename T::iterator it1,it2;

	for (int i=97; i<106; ++i) myvector.push_back(i);
	print_cont(myvector);
	it1 = it2 = myvector.begin();
	for (int i=0; i<5; i++) it2++;
	++it1;
	std::cout << "it1: " << *it1 << " it2: " << *it2 << std::endl;
	myvector.insert(it1, it1, it2);
	print_cont(myvector);
	std::cout << "\n";
}

template < typename T >
void vectorTest_insert_range3args()
{
	typedef typename ft::what_type<T>::type what_type;
std::cout << GREEN << "\n\n***--- vector RANGE 3 ARGS. TYPE: " << define_type(what_type()) << RESET << std::endl;

	std::cout << BLUE << "\n***------------------------- normal case 1" << RESET << std::endl;
	vector_insert_range_3args<std::vector<T> >(5, 3, 111);
	vector_insert_range_3args<ft::vector<T> >(5, 3, 111);

	std::cout << BLUE << "\n***------------------------- normal case 2: insert 1 elem" << RESET << std::endl;
	vector_insert_range_3args<std::vector<T> >(4, 1, 111);
	vector_insert_range_3args<ft::vector<T> >(4, 1, 111);

	std::cout << BLUE << "\n***------------------------- normal case 3" << RESET << std::endl;
	vector_insert_range_3args<std::vector<T> >(1, 3, 111);
	vector_insert_range_3args<ft::vector<T> >(1, 3, 111);

	std::cout << BLUE << "\n***------------------------- insert 0 elems" << RESET << std::endl;
	vector_insert_range_3args<std::vector<T> >(5, 0, 111);
	vector_insert_range_3args<ft::vector<T> >(5, 0, 111);

	std::cout << BLUE << "\n***------------------------- insert to empty container" << RESET << std::endl;
	vector_insert_range_3args<std::vector<T> >(0, 3, 111);
	vector_insert_range_3args<ft::vector<T> >(0, 3, 111);

	std::cout << BLUE << "\n***------------------------- insert from itself" << RESET << std::endl;
	vector_test_insert_itself<ft::vector<T>, T >();
	vector_test_insert_itself<std::vector<T>, T >();
}

template < typename T >
void	test_insert_iterators()
{
	T vec_dst(5, "a");
	T vec_src;
	for (int i = 0; i < 5; ++i)
		vec_src.push_back(ft::to_string(i, 10));

	std::cout << "dest:  "; print_cont(vec_dst);
	std::cout << "src:   "; print_cont(vec_src);

	typename T::iterator it = vec_dst.begin(); ++it;

std::cout << BLUE << "***--- insert 1 value" << RESET << std::endl;
	vec_dst.insert(it, "c");
	std::cout << "src:\t"; print_cont(vec_dst);

std::cout << BLUE << "***--- insert range between inters" << RESET << std::endl;
	typename T::iterator it1 = vec_dst.begin(); ++it1;
	typename T::iterator it_src_b = vec_src.begin(); std::advance(it_src_b, 2);
	typename T::iterator it_src_e = vec_src.end();   std::advance(it_src_e, -1);//--it_src_e;
	vec_dst.insert(it1, it_src_b, it_src_e);
	std::cout << "st:     ";	print_cont(vec_dst);

std::cout << BLUE << "***--- insert range between inters from self" << RESET << std::endl;
	typename T::iterator it_b = vec_dst.begin(); std::advance(it_b, 2);   //for (int i = 0; i < 3; i++) ++it_b;//	vecd::advance(it_b, 3);
	typename T::iterator it_e = vec_dst.end();   std::advance(it_e, -2); //for (int i = 0; i < 7; i++) --it_e;	//	std::advance(it_e, -7);
	it1 = vec_dst.begin(); ++it1;

	vec_dst.insert(it1, it_b, it_e);
	print_cont(vec_dst);

std::cout << BLUE << "***--- insert 3 args, 1 iter" << RESET << std::endl;
	typename T::iterator it_b1 = vec_dst.begin();	std::advance(it_b1, 3);
	vec_dst.insert(it_b1, 4, "rrr");
	print_cont(vec_dst);
	std::cout << "---------\n\n";
}

void vector_test_insert()
{
std::cout << GREEN << "\n\n***--- vector INSERT" << RESET << std::endl;

	test_insert_2args_reg<int>();
	test_insert_2args_reg<char>();

	vectorvectorTest_insert_range2args<int>();
	vectorvectorTest_insert_range2args<char>();

	vectorTest_insert_range3args<int>();
	vectorTest_insert_range3args<char>();

std::cout << GREEN << "***--- vector INSERT test with iterators" << RESET << std::endl;
	test_insert_iterators<std::vector<std::string> >();
	test_insert_iterators<ft::vector<std::string> >();
}

template < typename T>
void	test_erase_(int delta)
{
	T myvector;
	typename T::iterator it1,it2;
	for (int i=97; i<107; ++i) myvector.push_back(i);
	print_cont(myvector);

	it1 = it2 = myvector.begin();
	std::advance (it2,delta);// for (int i=0; i<delta; i++) it2++;
	++it1;

	std::cout << "before: " << "it1: " << *it1 << "\tit2: " << *it2 << std::endl;
	it1 = myvector.erase (it1);
	it2 = myvector.erase (it2);
	std::cout << "after:  it1: " << *it1 << "\tit2: " << *it2 << std::endl;
	print_cont(myvector);

	++it1;
	--it2;

	std::cout << "before: " << "it1: " << *it1 << "\tit2: " << *it2 << std::endl;
	myvector.erase (it1,it2);
	std::cout << "after:  it1: " << *it1 << "\tit2: " << *it2 << std::endl;
	print_cont(myvector);
	std::cout << "\n";
}

template <typename T>
void	test_erase()
{
	typedef typename ft::what_type<T>::type what_type;
std::cout << YELLOW << "\n\n***--- vector ERASE 1 ITER. TYPE: " << define_type(what_type()) << RESET << std::endl;

	std::vector<T> stl;
	ft::vector<T> ftl;
	test_erase_<std::vector<T> >(7);
	test_erase_<ft::vector<T> >(7);
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
std::cout << YELLOW << "\n\n***--- vector SWAP. TYPE: " << define_type(what_type()) << RESET << std::endl;

	std::vector<T> stl;
	ft::vector<T> ftl;
	test_swap_<std::vector<T> >();
	test_swap_<ft::vector<T> >();
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

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

// compare only integral part:
bool mycomparison_integral (double first, double second)
{ return ( int(first) < int(second) ); }

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

template < typename T>
void	test_assign_()
{
	T first;
	T second;

	std::cout << BLUE << "\n***------------------------- assign 2 args" << RESET << std::endl;
	first.assign (7,100);
	print_cont(first);

	std::cout << BLUE << "\n***------------------------- assign iterators" << RESET << std::endl;
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
	// first.pop_front();
	print_cont(first);
	std::cout << "size of first:   " << int (first.size()) << '\t';
	std::cout << "front() first:   " << first.front() << '\t';
	std::cout << "back() first:    " << first.back() << '\n';
	std::cout << '\n';

}

template < typename T>
void	test_sizes()
{
	T zero;
	std::cout << "size: " << int (zero.size()) << ' ' \
	<< "empty: " << zero.empty() << ' ' \
	<< "capacity: " << zero.capacity() << "\t";
	print_cont(zero);

	int myints[]={1776, 70, 46, 55, 65};
	T first(myints, myints + 2);

	std::cout << "size: " << int (first.size()) << ' ' \
	<< "empty: " << first.empty() << ' ' \
	<< "capacity: " << first.capacity() << '\t';
	print_cont(first);


	T second(myints, myints + 5);

	std::cout << "size: " << int (second.size()) << ' ' \
	<< "empty: " << second.empty() << ' ' \
	<< "capacity: " << second.capacity() << '\t';
	print_cont(second);

	second.clear();
	std::cout << "size: " << second.size() << ' ' \
	<< "empty: " << second.empty() << ' ' \
	<< "capacity: " << second.capacity() << '\n';

	std::cout << "---\n\n";
}

void	test_contents()
{
std::cout << YELLOW << "\n\n***--- vector: ASSIGN SIZE POPS" << RESET << std::endl;
	test_assign_<std::vector<int> >();
	test_assign_<ft::vector<int> >();

std::cout << YELLOW << "\n\n***--- vector: SIZE CLEAR EMPTY" << RESET << std::endl;
	test_sizes<std::vector<int> >();
	test_sizes<ft::vector<int> >();
}

void	test_non_member()
{
std::cout << YELLOW << "\n\n***--- vector: NON_MEMBER" << RESET << std::endl;
	std::vector<size_t> st_a(5, 10);
	std::vector<size_t> st_b(st_a);

	ft::vector<size_t> ft_a(5, 10);
	ft::vector<size_t> ft_b(ft_a);

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
std::cout << YELLOW << "\n\n***--- vector: ALL KIND OF ITERS" << RESET << std::endl;
	std::cout << BLUE << "\n***------------------------- iters on normal obj" << RESET << std::endl;

	ft::vector<size_t> ft_vector_s(5, 21);
	std::vector<size_t> std_vector_s(5, 21);

	ft::vector<size_t>::iterator ft_it = ft_vector_s.begin();
	std::vector<size_t>::iterator st_it = std_vector_s.begin();

	ft::vector<size_t>::const_iterator ft_it_const = ft_vector_s.begin();
	std::vector<size_t>::const_iterator st_it_const = std_vector_s.begin();

	ft::vector<size_t>::reverse_iterator ft_it_r = ft_vector_s.rbegin();
	std::vector<size_t>::reverse_iterator st_it_r = std_vector_s.rbegin();

	// ft::vector<size_t>::const_reverse_iterator ft_it_const_r = ft_vector_s.rbegin();//todo
	// std::vector<size_t>::const_reverse_iterator st_it_const_r = std_vector_s.rbegin();
	ft::vector<size_t>::const_reverse_iterator ft_it_const_r2(ft_it_r);
	std::vector<size_t>::const_reverse_iterator st_it_const_r2(st_it_r);

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

	// // *ft_it_const_r = 5;// should not work
	// // *st_it_const_r = 5;// should not work
	std::cout << "ft_it_const_r: " << *ft_it_const_r2 << "\n";
	std::cout << "st_it_const_r: " << *st_it_const_r2 << "\n---\n";
	std::cout << "ft_it_const_r: " << *++ft_it_const_r2 << "\n";
	std::cout << "st_it_const_r: " << *++st_it_const_r2 << "\n";
	print_cont(ft_vector_s);
	print_cont(std_vector_s);

	std::cout << BLUE << "\n***------------------------- COPY constructors of iters on normal obj" << RESET << std::endl;

	ft::vector<size_t>::iterator ft_it_cpy(ft_it);
	std::vector<size_t>::iterator st_it_cpy(st_it);

	ft::vector<size_t>::const_iterator ft_it_const_cpy(ft_it_const);
	std::vector<size_t>::const_iterator st_it_const_cpy(st_it_const);

	ft::vector<size_t>::reverse_iterator ft_it_r_cpy(ft_it_r);
	std::vector<size_t>::reverse_iterator st_it_r_cpy(st_it_r);

	ft::vector<size_t>::const_reverse_iterator ft_it_const_r_cpy(ft_it_const_r2);//todo
	std::vector<size_t>::const_reverse_iterator st_it_const_r_cpy(st_it_const_r2);//

	std::cout << *ft_it_cpy << "\t" << *st_it_cpy << "\n";
	std::cout << *ft_it_const_cpy << "\t" << *st_it_const_cpy << "\n";
	std::cout << *ft_it_r_cpy << "\t" << *st_it_r_cpy << "\n";
	std::cout << *ft_it_const_r_cpy << "\t" << *st_it_const_r_cpy << "\n";


	std::cout << BLUE << "\n***------------------------- iters on CONST obj" << RESET << std::endl;

	ft::vector<size_t> const ft_const_X(ft_vector_s);
	std::vector<size_t> const std_const_X(std_vector_s);

	// ft::vector<size_t>::iterator ft_it_X = ft_const_X.begin();// should not work
	// std::vector<size_t>::iterator st_it_X = std_const_X.begin();// should not work

	ft::vector<size_t>::const_iterator ft_it_const_X = ft_const_X.begin();
	std::vector<size_t>::const_iterator st_it_const_X = std_const_X.begin();

	// ft::vector<size_t>::reverse_iterator ft_it_X_r = ft_const_X.rbegin();// same as std: should not work
	// std::vector<size_t>::reverse_iterator st_it_X_r = std_const_X.rbegin();// same as std: should not work

	ft::vector<size_t>::const_reverse_iterator ft_it_const_X_r = ft_const_X.rbegin();
	std::vector<size_t>::const_reverse_iterator st_it_const_X_r = std_const_X.rbegin();

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

	ft::vector<size_t>::const_iterator ft_it_const_X_cpy(ft_it_const_X);
	std::vector<size_t>::const_iterator st_it_const_X_cpy(st_it_const_X);

	ft::vector<size_t>::const_reverse_iterator ft_it_const_X_r_cpy(ft_it_const_X_r);
	std::vector<size_t>::const_reverse_iterator st_it_const_X_r_cpy(st_it_const_X_r);

	std::cout << *ft_it_const_X_cpy << " " << *ft_it_const_X_r_cpy << "\n";
	std::cout << *st_it_const_X_cpy << " " << *st_it_const_X_r_cpy << "\n";
}

template < typename T >
void	test_reserve_()
{
	typename T::size_type sz;

	T foo;
	sz = foo.capacity();
	std::cout << "--- making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	T bar;
	sz = bar.capacity();
	bar.reserve(100);	 // this is the only difference with foo above
	std::cout << "--- making bar grow:\n";
	for (int i=0; i<101; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	std::cout << "\n\n";
}

void	test_reserve()
{
std::cout << YELLOW << "\n\n***--- vector: RESERVE" << RESET << std::endl;
	test_reserve_<std::vector<int> >();
	test_reserve_<ft::vector<int> >();
}

template <typename T>
void	test_sqbrackets_at_()
{
	T myvector (10);
	typename T::size_type sz = myvector.size();
	for (unsigned i=0; i<sz; i++) myvector.at(i) = i;

	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}
	std::cout << "myvector contains:";
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myvector[i];

	try {
		std::cout << "\n" << myvector[200];
		std::cout << "\n" << myvector.at(200);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << '\n';
}

void	test_sqbrackets_at()
{
std::cout << YELLOW << "\n\n***--- vector: OPERATOR [] vs vector.at()" << RESET << std::endl;
	test_sqbrackets_at_<std::vector<int> >();
	test_sqbrackets_at_<ft::vector<int> >();
}

int main()
{
std::cout << GREEN << "\n\n***--- vector CONSTRUCTORS" << RESET << std::endl;
	test_vector_constructors<int>();
	test_vector_constructors<long>();
	test_vector_constructors<char>();
	test_vector_constructors<std::string>();
	test_vector_constructors<temp>();

std::cout << GREEN << "\n\n***--- vector ITERATORS" << RESET << std::endl;
	test_vector_iterators();
	test_all_kinds_of_iters();

	test_contents();

	vector_push_pop_resize<int>();
	vector_push_pop_resize<char>();
	vector_push_pop_resize<std::string>();

	vector_test_insert();

	test_erase<int>();
	test_erase<char>();

	test_sqbrackets_at();

	test_swap<int>();
	test_swap<char>();

	test_non_member();

	test_reserve();
}
