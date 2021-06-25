#pragma once

#include <iostream>

template<typename Iter_type>
struct my_reverse_iterator : public Iter_type
{
protected:
	Iter_type	current;

public:
	typedef my_reverse_iterator<Iter_type>	_Self;

	typedef Iter_type								iterator_type;
	typedef typename Iter_type::difference_type		difference_type;
	typedef typename Iter_type::iterator_category	iterator_category;
	typedef typename Iter_type::value_type			value_type;
	typedef typename Iter_type::pointer				pointer;
	typedef typename Iter_type::reference			reference;

	my_reverse_iterator() : Iter_type() { }
	my_reverse_iterator(Iter_type const & it) : Iter_type(it), current(it) { }
	my_reverse_iterator(my_reverse_iterator const & src) : Iter_type(src.current), current(src.base()) {}
	my_reverse_iterator &operator=(my_reverse_iterator const & src)
	{
		this->current = src.current;
		return *this;
	}

	template <class Up>
	my_reverse_iterator( const my_reverse_iterator<Up> & src) : Iter_type(src.base()), current(src.base()) {}

	Iter_type base() const { return current; }

	reference operator*() const
	{
		Iter_type tmp = current;
		return *--tmp;
	}

	pointer operator->() const
	{
		return &(operator*());
	}

	_Self & operator++()
	{
		--current;
		return *this;
	}

	_Self operator++(int)
	{
		_Self tmp = *this;
		--current;
		return tmp;
	}

	_Self & operator--()
	{
		++current;
		return *this;
	}

	_Self operator--(int)
	{
		_Self tmp = *this;
		++current;
		return tmp;
	}

	bool operator==(const _Self & x)
	{ return current == x.base(); }

	bool operator!=(const _Self & x)
	{ return current != x.base(); }
};
