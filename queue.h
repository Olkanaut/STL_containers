#pragma once

#include <iostream>
#include "vector.h"

namespace ft
{
template <typename T, typename Sequence = ft::list<T> >
class queue
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
		explicit queue(const Sequence & _c = Sequence()) : c(_c) { }

	bool empty() const				{ return c.empty(); }
	size_type size() const			{ return c.size(); }
	reference front()				{ return c.front(); }
	const_reference front() const	{ return c.front(); }
	reference back()				{ return c.back(); }
	const_reference back() const	{ return c.back(); }
	void push(const value_type& x)	{ c.push_back(x); }
	void pop()						{ c.pop_front(); }

	friend bool operator==(const ft::queue<T, Sequence>& x, const ft::queue<T, Sequence>& y)
	{ return x.c == y.c; }

	friend bool operator<(const ft::queue<T, Sequence>& x, const ft::queue<T, Sequence>& y)
	{ return x.c < y.c; }
};

	template<typename T, typename Seq>
	void swap(queue<T, Seq>& x, queue<T, Seq>& y)
	{ x.swap(y); };

	template<typename T, typename Seq>
	inline bool operator!=(const queue<T, Seq>& x, const queue<T, Seq>& y)
	{ return !(x == y); }

	template<typename T, typename Seq>
	inline bool operator>(const queue<T, Seq>& x, const queue<T, Seq>& y)
	{ return y < x; }

	template<typename T, typename Seq>
	inline bool operator<=(const queue<T, Seq>& x, const queue<T, Seq>& y)
	{ return !(y < x); }

	template<typename T, typename Seq>
	inline bool operator>=(const queue<T, Seq>& x, const queue<T, Seq>& y)
	{ return !(x < y); }
}
