#pragma once

#include <iostream>
#include "vector.h"

namespace ft
{
template <typename T, typename Sequence = ft::vector<T> >
class stack
{
	public:
		typedef typename Sequence::value_type		value_type;
		typedef typename Sequence::reference		reference;
		typedef typename Sequence::const_reference	const_reference;
		typedef typename Sequence::size_type		size_type;
		typedef			 Sequence					container_type;

	protected:
		Sequence c;
	public:
		explicit stack(const Sequence & _c = Sequence()) : c(_c) { }

	bool empty() const		{ return c.empty(); }
	size_type size() const	{ return c.size(); }
	reference top()			{ return c.back(); }
	void pop() 				{ c.pop_back(); }
	const_reference top() const	{ return c.back(); }
	void push(const value_type& __x) { c.push_back(__x); }

	friend bool operator==(const ft::stack<T, Sequence>& x, const ft::stack<T, Sequence>& y)
	{ return x.c == y.c; }

	friend bool operator<(const ft::stack<T, Sequence>& x, const ft::stack<T, Sequence>& y)
	{ return x.c < y.c; }
};
	template<typename T, typename Seq>
	void swap(stack<T, Seq>& x, stack<T, Seq>& y)
	{ x.swap(y); };///

	template<typename T, typename Seq>
	inline bool operator!=(const stack<T, Seq>& x, const stack<T, Seq>& y)
	{ return !(x == y); }

	template<typename T, typename Seq>
	inline bool operator>(const stack<T, Seq>& x, const stack<T, Seq>& y)
	{ return y < x; }

	template<typename T, typename Seq>
	inline bool operator<=(const stack<T, Seq>& x, const stack<T, Seq>& y)
	{ return !(y < x); }

	template<typename T, typename Seq>
	inline bool operator>=(const stack<T, Seq>& x, const stack<T, Seq>& y)
	{ return !(x < y); }
}
