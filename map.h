#pragma once

#include <iostream>
#include <limits>
#include "bst.h"
#include "bst_node.h"
#include "my_reverse_iterator.h"

namespace ft
{
template<typename Key,
		 typename Tp,
		 typename Compare = std::less<Key>,
		 typename Alloc = std::allocator<std::pair<const Key, Tp> > >
	class map
{
public:
	typedef Key							key_type;
	typedef Tp							value;
	typedef std::pair<const Key, Tp>	value_type;
	typedef Compare						key_compare;
	typedef Alloc						allocator_type;
	typedef bst<Key, Tp, Compare>		bst_struct;

	typedef value_type*							pointer;
	typedef const value_type*					const_pointer;
	typedef value_type&							reference;
	typedef const value_type&					const_reference;
	typedef size_t								size_type;
	typedef std::ptrdiff_t						difference_type;

	typedef bst_iterator<value_type>				iterator;
	typedef bst_const_iterator<value_type>			const_iterator;
	typedef my_reverse_iterator<iterator>			reverse_iterator;
	typedef my_reverse_iterator<const_iterator>	const_reverse_iterator;

	class value_compare	: public std::binary_function<value_type, value_type, bool>
	{
		friend class map<Key, Tp, Compare, Alloc>;
		protected:
			Compare comp;
			value_compare(Compare _c) : comp(_c) { }

		public:
			bool operator()(const value_type& x, const value_type& y) const
			{ return comp(x.first, y.first); }
	};

private:
	bst_struct	_tree;
	size_type	_size;//////
	Alloc		_alloc;

public:
	explicit map(const key_compare& comp = key_compare(), const allocator_type& a = allocator_type())
	: _tree(comp), _alloc(a) { _size = 0; }

	// * This is linear in N if the range is already sorted, and NlogN otherwise (N=dist(first,__last))
	template <class InputIterator>
	map (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& a = allocator_type())
	: _tree(comp), _alloc(a)
	{
		_size = 0;
		this->insert(first, last);
	}

	map(map const & src)
	: _size(0), _alloc(src._alloc) { *this = src; }

	map & operator=(map const & src)
	{
		if (this == &src)
			return *this;
		this->clear();
		this->insert(src.begin(), src.end());
		this->_size = src._size;
		this->_alloc = src._alloc;
		return *this;
	}

	~map() {}

	iterator begin()				{ return _tree.begin(); }
	const_iterator begin() const	{ return _tree.begin(); }
	iterator				end()		{ return _tree.end(); }
	const_iterator			end() const { return _tree.end(); }
	reverse_iterator		rbegin()		{ return _tree.rbegin(); }
	const_reverse_iterator	rbegin() const	{ return _tree.rbegin(); }
	reverse_iterator		rend()			{ return _tree.rend(); }
	const_reverse_iterator	rend() const	{ return _tree.rend(); }


	size_type size() const		{ return _tree.get_size(); }
	size_type max_size() const	{ return std::numeric_limits<size_type>::max() / sizeof(value_type); }
	bool empty() const			{ return _tree.get_size() == 0; }//

	size_type count(const key_type & key) const
	{ return _tree.find(key) == _tree.end() ? 0 : 1; }

	value &  operator[](const key_type& key)
	{ return _tree.operator[](key); }

	void clear()
	{ _tree.clear(); }

	std::pair<iterator, bool> insert(const value_type & val)
	{ return _tree.insert(val); }

	iterator insert(iterator pos, const value_type & val)
	{ return _tree.insert(pos, val); }

	template<typename _InputIterator>
	void insert(_InputIterator first, _InputIterator last)
	{
		while (first != last)
		{
			_tree.insert(std::pair<key_type, value>(first->first, first->second));
			++first;
		}
	}

// * Note: erases the element, and that if the element is itself a pointer,
//   the pointed-to memory is not touched in any way
	void erase(iterator pos)
	{ _tree.remove(pos->first); }//

	size_type erase(const key_type& key)
	{ return _tree.remove(key); }

	void erase(iterator first, iterator last)
	{
		while (first != last)
			erase(first++);		// _tree.remove((first->first)++);
	}

	void swap(map & x)
	{ _tree.swap(x._tree); }

	key_compare key_comp() const
	{ return _tree.key_comp(); }

	// * Value_compare has no public constructor, therefore no objects
	// can be directly created from this nested class outside map members.
	value_compare value_comp() const
	{ return value_compare(_tree.key_comp()); }

	iterator find(const key_type& key)
	{ return _tree.find(key); }

	const_iterator find(const key_type& key) const
	{ return _tree.find(key); }

	iterator lower_bound(const key_type & key)
	{ return _tree.lower_bound(key); }

	const_iterator lower_bound(const key_type & key) const
	{ return _tree.lower_bound(key); }

	iterator upper_bound(const key_type & key)
	{ return _tree.upper_bound(key); }

	const_iterator upper_bound(const key_type & key) const
	{ return const_iterator(_tree.upper_bound(key)); }

	// * This function probably only makes sense for multimaps.
	std::pair<iterator, iterator> equal_range(const key_type & key)
	{
		iterator it = lower_bound(key);
		iterator iu = upper_bound(key);
		return std::pair<iterator, iterator>(it, iu);
	}

	std::pair<const_iterator, const_iterator> equal_range(const key_type & key) const
	{
		const_iterator it = lower_bound(key);
		const_iterator iu = upper_bound(key);
		return std::pair<const_iterator, const_iterator>(it, iu);
	}
};

	template <class Key, class T, class Compare, class Alloc>
	bool	operator==(const ft::map<Key, T, Compare, Alloc>& x,
						const ft::map<Key, T, Compare, Alloc>& y)
	{
		if (x.size() != y.size())
			return (false);
		typename ft::map<Key, T, Compare, Alloc>::const_iterator	it1 = x.begin();
		typename ft::map<Key, T, Compare, Alloc>::const_iterator	it2 = y.begin();
		while (it1 != x.end())
		{
			if (!(*it1 == *it2))
				return false;
			++it1;
			++it2;
		}
		return true;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<(const ft::map<Key, T, Compare, Alloc>& x,
					const ft::map<Key, T, Compare, Alloc>& y)
	{
		typename ft::map<Key, T, Compare, Alloc>::const_iterator	it1 = x.begin();
		typename ft::map<Key, T, Compare, Alloc>::const_iterator	it2 = y.begin();

		while (it1 != x.end())
		{
			if (it2 == y.end() || *it2 < *it1)
				return false;
			else if (*it1 < *it2)
				return true;
			++it1;	++it2;
		}
		return it2 != y.end();
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	inline bool	operator!=(const ft::map<Key, T, Compare, Alloc>& x,
		const ft::map<Key, T, Compare, Alloc>& y)
	{ return !(x == y); }

	template<typename Key, typename T, typename Compare, typename Alloc>
	inline bool	operator>(const ft::map<Key, T, Compare, Alloc>& x,
	const ft::map<Key, T, Compare, Alloc>& y)
	{ return y < x; }

	template<typename Key, typename T, typename Compare, typename Alloc>
	inline bool	operator<=(const ft::map<Key, T, Compare, Alloc>& x,
		const ft::map<Key, T, Compare, Alloc>& y)
	{ return !(y < x); }

	template<typename Key, typename T, typename Compare, typename Alloc>
	inline bool	operator>=(const ft::map<Key, T, Compare, Alloc>& x,
		const ft::map<Key, T, Compare, Alloc>& y)
	{ return !(x < y); }

	template<typename Key, typename T, typename Compare, typename Alloc>
	inline void swap(ft::map<Key, T, Compare, Alloc>& x, ft::map<Key, T, Compare, Alloc>& y)
	{ x.swap(y); }
}
