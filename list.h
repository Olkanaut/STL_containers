#pragma once

#include <iostream>
#include <limits>
#include <list>
#include "utils.h"
#include "list_node.h"
#include "list_iterator.h"
#include "list_reverse_iterator.h"

namespace ft
{
template <typename T, typename Alloc = std::allocator<T> >
class list
{
public:
// Member types
	typedef	T							value_type;
	typedef	Alloc			allocator_type;

	typedef typename Alloc::reference			reference;
	typedef typename Alloc::const_reference		const_reference;
	typedef typename Alloc::pointer				pointer;
	typedef typename Alloc::const_pointer		const_pointer;
	typedef	typename Alloc::difference_type 	difference_type;//	Signed integer type (usually std::ptrdiff_t)
	typedef	typename Alloc::size_type			size_type;

	typedef list_iterator<T>						iterator;
	typedef list_const_iterator<T>					const_iterator;
	typedef list_reverse_iterator<iterator>			reverse_iterator;
	typedef list_reverse_iterator<const_iterator>	const_reverse_iterator;
	// typedef const list_reverse_iterator<iterator>	const_reverse_iterator;
	// typedef List_const_reverse_iterator<const_iterator>	const_reverse_iterator;///
	// typedef List_const_reverse_iterator<iterator>	const_reverse_iterator;///


////// using iterators defined in STD
	// typedef typename std::list<T>::iterator				iterator;
	// typedef typename std::list<T>::iterator const		const_iterator;
	// typedef std::reverse_iterator<iterator>				reverse_iterator;
	// typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;


private:
	size_type		_size;// difference_type
	Alloc			_allocator;///

	struct Node<T>	*_head;
	// struct Node<T>	*_begin;
	struct Node<T>	*_tail;

	// void init_ends()
	// {
	// 	this->_tail = new struct Node<T>();
	// 	// this->_head = new struct Node<T>();
	// 	this->_tail->_prev = this->_tail;
	// 	// this->_head->_next = this->_tail;
	// 	this->_tail->_next = this->_tail;//->_next;
	// 	// this->_head->_prev = this->_tail;//->_prev;
	// 	_size = 0;//size//alloc
	// }

	// Node<T> *init_node()
	// {
	// 	Node<T> *new_node = new struct Node<T>();
	// 	new_node->_next = NULL;
	// 	new_node->_prev = NULL;
	// 	return new_node;
	// }
	// Node<T> *init_node(const T & val)
	// {
	// 	Node<T> *new_node = new struct Node<T>(val);
	// 	new_node->_next = NULL;
	// 	new_node->_prev = NULL;
	// 	return new_node;
	// }

	void init_ends()
	{
		this->_tail = new struct Node<T>();
		this->_head = new struct Node<T>();
		// this->_tail = init_node();
		// this->_head = init_node();

		this->_tail->_prev = this->_head;
		this->_head->_next = this->_tail;
		// this->_tail->_next = this->_head;//->_next;
		// this->_head->_prev = this->_tail;//->_prev;
		_size = 0;//size//alloc
	}

	template <class InputIterator>
	void init(InputIterator first, InputIterator last, false_type)
	{
		init_ends();
		while (first != last)
		{
			// this->push_back(first._node->_elem);
			this->push_back(*first);
			++first;
		}
	}

	void init(size_type n, const value_type & val, true_type)
	{
		init_ends();
		while (_size < n)
			this->push_back(val);
	}

	template <class InputIterator>
	void	assign(InputIterator first, InputIterator last, false_type)
	{
		list<T> tmp(first, last);
		this->clear();
		for (iterator it = tmp.begin(); it != tmp.end(); ++it)
		{
			this->push_back(it._node->_elem);
		}
		tmp.clear();
	}

	void	assign(size_type n, const value_type & val, true_type)
	{
		std::cout << "redirected assign\n";
		this->clear();
		while (n-- > 0)
			push_back(val);
	}

	void	insert(iterator pos, size_type n, const value_type & val, true_type)//_
	{
		// std::cout << "redirected insert 3 args\n";
		while (n)
		{
			insert(pos, val);
			// pos++;//
			n--;
		} //if (pos == end()) pos--
	}

	template <class InputIterator>
	void	insert(iterator pos, InputIterator first, InputIterator last, false_type)
	{
		while (first != last)
		{
			insert(pos, *first);
			++first;
		}
	}

	static bool	default_compare(T const & a, T const & b) { return a < b; }

	void	print_this()
	{
		iterator jt = begin();
		iterator jte = end();
		while (jt != jte)
		{
			std::cout << *jt << " ";
			jt++;
		}
		std::cout << "\n";
	}

	void	print_this(list & cont)
	{
		iterator jt = cont.begin();
		iterator jte = cont.end();
		while (jt != jte)
		{
			std::cout << *jt << " ";
			jt++;
		}
		std::cout << "\n";
	}

public:

	explicit list (const allocator_type & alloc = allocator_type())
		:	_allocator(alloc)	//  _head(NULL), _tail(NULL),
	{
		init_ends();
	};

	explicit list (size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type())
		:	_allocator(alloc)	//  _head(NULL), _tail(NULL),
	{
		init_ends();
		while (_size < n)
			this->push_back(val);
	};

	template <class InputIterator>
	list (InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type())
		:	_allocator(alloc)
	{
		typedef typename ft::is_int<InputIterator>::type is_int;//check other types long size_t
		init(first, last, is_int());
	};

	list(const list & src) : _allocator(src._allocator)
	{
		init_ends();
		this->assign(src.begin(), src.end());
	}

	list & operator=(list const & src)//allocator, size?
	{
		if (this == & src)
			return *this;
		this->assign(src.begin(), src.end());
		return *this;
	};

	~list()
	{
		this->clear();
		delete _tail;
		delete _head;
	};

// Iterators:
////// using allocators defined in STD   { return iterator(this->_M_impl._M_node._M_next); }
// 	iterator				begin() { return iterator(reinterpret_cast<std::__detail::_List_node_base*>(_head->_next)); };// bidirectional iterator
// 	const_iterator			begin() const { return const_iterator(reinterpret_cast<std::__detail::_List_node_base*>(_head->_next)); };//If the container is empty, the returned iterator value shall not be dereferenced.
// 	iterator				end() { return iterator(reinterpret_cast<std::__detail::_List_node_base*>(_tail)); };
// 	const_iterator			end() const { return const_iterator(reinterpret_cast<std::__detail::_List_node_base*>(_tail)); };

	iterator				begin() { return iterator(_head->_next); };// bidirectional iterator
	const_iterator			begin() const { return const_iterator(_head->_next); };//If the container is empty, the returned iterator value shall not be dereferenced.
	iterator				end() { return iterator(_tail); };
	const_iterator			end() const { return const_iterator(_tail); };

	reverse_iterator		rbegin() { return reverse_iterator(end()); };
	const_reverse_iterator	rbegin() const { return const_reverse_iterator(end()); };
	reverse_iterator		rend() { return reverse_iterator(begin()); };
	const_reverse_iterator	rend() const { return const_reverse_iterator(begin()); };


// Capacity:
	bool			empty() const { return _size == 0; }
	size_type		size() const { return _size; }
	size_type		max_size() const { return (std::numeric_limits<difference_type>::max() / sizeof(Node<T>)); }

// Element access:
	reference		front() { return *begin(); }//Calling this function on an empty container causes undefined behavior.
	const_reference	front() const { return *begin(); }

	reference		back()
	{
		// iterator tmp = end();// --tmp;// return *tmp;
		return _tail->_prev->_elem;
	}

	const_reference	back() const
	{
// 		iterator tmp = end();// 		--tmp;// return *tmp;
		return _tail->_prev->_elem;
	}


// Modifiers:
	template <class InputIterator>
	void	assign (InputIterator first, InputIterator last)
	{
		typedef typename ft::is_int<InputIterator>::type is_int;//check other types long size_t
		assign(first, last, is_int());
	}

	void		assign (size_type n, const value_type & val)
	{
		std::cout << "normal assign\n";
		this->clear();
		while (n-- > 0)
			push_back(val);
	}

	void		push_front (const value_type & val)
	{
		insert(this->begin(), val);
		// Node<T> *tmp = new Node<T>(val);
		// tmp->_prev = _head;
		// tmp->_next = _head->_next;
		// _head->_next->_prev = tmp;
		// _head->_next = tmp;
		// _size++;
	}

	void		pop_front()
	{
		if (_size > 0)
		{
			Node<T> *tmp = _head->_next;
			_head->_next->_next->_prev = _head;
			_head->_next = _head->_next->_next;
			delete tmp;
			_size--;
		}
	}

	void		push_back (const value_type & val)
	{
		this->insert(end(), val);
		// Node<T> *tmp = new Node<T>(val);
		// // pos->_node = reinterpret_cast<std::__detail::_List_node_base*>(tmp);
		// tmp->_next = _tail;
		// tmp->_prev = _tail->_prev;//
		// _tail->_prev->_next = tmp;
		// _tail->_prev = tmp;//
		// _size++;
	}

	void		pop_back()
	{
		if (_size > 0)
		{
			Node<T> *tmp = _tail->_prev;
			_tail->_prev->_prev->_next = _tail;
			_tail->_prev = _tail->_prev->_prev;
			delete tmp;
			_size--;
		}
	}

	iterator	insert(iterator pos, const value_type & val)
	{
		// std::cout << "normal insert 2 args\n";
		Node<T> *tmp = new Node<T>(val);
		// Node<T> *tmp = init_node(val);
		tmp->_next = pos._node;
		tmp->_prev = pos._node->_prev;//
		tmp->_prev->_next = tmp;//
		tmp->_next->_prev = tmp;
		_size++;
		// pos++;
		return iterator(tmp);
		// return --pos;
		// return pos;
	}

	void		insert(iterator pos, size_type n, const value_type & val)
	{
		std::cout << "normal insert 3 args\n";

		while (n)
		{
			insert(pos, val);
			// pos++;//
			n--;
		}
	}
	template <class InputIterator>
	void	insert(iterator pos, InputIterator first, InputIterator last)
	{
		typedef typename ft::is_int<InputIterator>::type is_int;//check other types long size_t
		insert(pos, first, last, is_int());
	}



	iterator	erase (iterator pos)
	{
		// iterator tmp = pos;
		// tmp++;
		pos._node->_prev->_next = pos._node->_next;//tmp
		pos._node->_next->_prev = pos._node->_prev;
		iterator tmp = iterator(pos._node->_next);
		delete pos._node;
		_size--;
		return tmp;
	}
	iterator	erase (iterator first, iterator last)
	{
		while (first != last)
			first = erase(first);
		return last;
	}

	void		swap (list & x)
	{
		Node<T> *tmp = _head;
		_head = x._head;
		x._head = tmp;

		tmp = _tail;
		_tail = x._tail;
		x._tail = tmp;

		allocator_type type = _allocator;
		_allocator = x._allocator;
		x._allocator = type;

		size_type size = _size;
		_size = x._size;
		x._size = size;
	}

	void		resize (size_type n, value_type val = value_type())
	{
		while (n >= 0 && n < _size)
			pop_back();
		while (n > _size)
			push_back(val);
	}
	void		clear()
	{
		while (_size)
			pop_back();
	}

// Operations:
	void		splice (iterator pos, list & x)
	{
		insert(pos, x.begin(), x.end());
		x.clear();
	}
	void		splice (iterator pos, list & x, iterator i)
	{
		insert(pos, *i);
		x.erase(i);
	}
	void		splice (iterator pos, list & x, iterator first, iterator last)
	{
		insert(pos, first, last);
		x.erase(first, last);
	}

	void		remove (const value_type & val)
	{
		iterator it = this->begin();
		iterator ite = this->end();
		while (it != ite)
		{
			if (*it == val)
				it = erase(it);
			else
				++it;
		}
	}
	template <class Predicate>
		void remove_if (Predicate pred)
	{
		iterator it = this->begin();
		iterator ite = this->end();
		while (it != ite)
		{
			if (pred(*it))
				it = erase(it);
			else
				++it;
		}
	}

	void		unique()
	{
		iterator it = begin();
		iterator ite = end();
		if (it == ite)
			return ;
		iterator next = it;
		while (++next != ite)
		{
			if (*it == *next)
				erase(next);
			else
				it = next;
			next = it;
		}
	}
	template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred)
	{
		iterator it = begin();
		iterator ite = end();
		if (it == ite)
			return ;
		iterator next = it;
		while (++next != ite)
		{
			if (binary_pred(*it, *next))
				erase(next);
			else
				it = next;
			next = it;
		}
	}

	void		merge (list & x) { return merge(x, default_compare); }

	template <class Compare>
		void merge (list & x, Compare comp)
	{
		if (&x == this || _size == 0)
			return ;
		while (x.size())
		{
			iterator tmp = x.begin();
			for (iterator it = begin(); it != end();)
			{
				if (comp(*tmp, *it))
				{
					splice(it, x, tmp);
					break ;
				}
				if (++it == end())
					splice(it, x, tmp);
			}
		}
	}

	void		sort() { return sort(default_compare); }

	template <class Compare>
		void sort (Compare comp)
	{
		if (_size < 2)
			return ;
		iterator it = this->begin();
		iterator ite = this->end();
		T tmp;
		for (; it != this->end(); ++it)
		{
			for (iterator j = begin(); j != (ite-1); ++j)// for (iterator j = begin(); j != --ite; ++j)
			{	// ite++;
				if (comp(*(j+1), *(j)))// if (*j > *(j+1))
				{
					tmp = *j;
					*j = *(j+1);
					*(j+1) = tmp;
				}
			}
			--ite;//
		}
	}

	void		reverse()
	{
		iterator it = begin();
		reverse_iterator rit = rbegin();
		if (_size < 2)
			return ;
		size_type dist = _size / 2;
		while (dist)
		{
			T tmp(*it);// T tmp(it._node->_elem);
			*it = *rit;
			*rit = tmp;
			it++;
			rit++;
			dist--;
		}
	}

	// allocator_type get_allocator() const;
};

///// non-member overloads:
	template< class T, class Alloc >
	bool operator==(const ft::list<T, Alloc> & x, const ft::list<T, Alloc> & y)
	{
		// if (x.size() != y.size()) //c++11
		// 	return false;
		typename ft::list<T, Alloc>::const_iterator itx = x.begin();
		typename ft::list<T, Alloc>::const_iterator ity = y.begin();
		while (itx != x.end() && ity != y.end())
		{
			if (*itx != *ity)
				return false;
			++itx;
			++ity;
		}
		return itx == x.end() && ity == y.end();
	}

	template< class T, class Alloc >
	bool operator!=(const ft::list<T, Alloc> & x, const ft::list<T, Alloc> & y)
	{
		return !(x == y);
	}

	template< class T, class Alloc >
	bool operator<(const ft::list<T, Alloc> & x, const ft::list<T, Alloc> & y)
	{
		typename ft::list<T, Alloc>::const_iterator ix = x.begin();
		typename ft::list<T, Alloc>::const_iterator iy = y.begin();
		while (ix != x.end() && iy != y.end())
		{
			if (*ix < *iy)
				return true;
			else if (*ix > *iy)
				return false;
			++ix;
			++iy;
		}
		return ix == x.end() && iy != y.end();
	}

	template< class T, class Alloc >
	bool operator<=(const ft::list<T, Alloc> & x, const ft::list<T, Alloc> & y){
		return !(y < x);
	}

	template< class T, class Alloc >
	bool operator>(const ft::list<T, Alloc> & x, const ft::list<T, Alloc> & y){
		return y < x;
	}

	template< class T, class Alloc >
	bool operator>=(const ft::list<T, Alloc> & x, const ft::list<T, Alloc> & y){
		return !(x < y);
	}

	template< class T, class Alloc >
	void swap(ft::list<T, Alloc> & x, ft::list<T, Alloc> & y){
		x.swap(y);
	}
}
