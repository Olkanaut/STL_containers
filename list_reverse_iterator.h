#pragma once

#include <iostream>
#include "list_node.h"

template<typename Iter_type>
struct List_reverse_iterator
{
protected:
	Iter_type	current;

public:
	typedef List_reverse_iterator<Iter_type>	_Self;

	typedef Iter_type								iterator_type;//
	typedef typename Iter_type::difference_type		difference_type;
	typedef typename Iter_type::iterator_category	iterator_category;//
	typedef typename Iter_type::value_type			value_type;//?
	typedef typename Iter_type::pointer				pointer;//
	typedef typename Iter_type::reference			reference;//?

	// typedef const Iter_type*				const_pointer;//
	// typedef const Iter_type&				const_reference;//

	List_reverse_iterator() : current() { }

	explicit List_reverse_iterator(Iter_type iter) : current(iter) { }

      /**
       *  The copy constructor is normal.
      */
	// List_reverse_iterator(const List_reverse_iterator & src) : current(src.current) { }
	// List_reverse_iterator(const List_reverse_iterator & src) : current(src.base()) { }

	// List_reverse_iterator& operator=(const List_reverse_iterator & src) = default;

    //   /**
    //    *  A %reverse_iterator across other types can be copied if the
    //    *  underlying %iterator can be converted to the type of @c current.
    //   */
	// template<typename Iter_type>
	List_reverse_iterator(const List_reverse_iterator<Iter_type>& x)
	: current(x.base()) { };

	Iter_type base() const { return current; }

//operator= ? // <> >= <= + -
	reference operator*() const//const?
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

	// _Self operator+(difference_type n) const//*  The underlying iterator must be a Random Access Iterator.
	// {
	// 	return _Self(current - n);
	// }

	// _Self & operator+=(difference_type n)//*  The underlying iterator must be a Random Access Iterator.
	// {
	// 	current -= n;
	// 	return *this;
	// }

	// _Self operator-(difference_type n) const
	// {
	// 	return _Self(current + n);//*  The underlying iterator must be a Random Access Iterator.
	// }

	// _Self & operator-=(difference_type n)
	// {
	// 	current += n;
	// 	return *this;
	// }

	// reference operator[](difference_type n) const//*  The underlying iterator must be a Random Access Iterator.
	// {
	// 	return *(*this + n);
	// }

	// bool operator==(const _Self & x, const _Self & y)
	// { return x.base() == y.base(); }

	// bool operator!=(const _Self & x, const _Self & y)
	// { return x.base() != y.base(); }

	// bool operator==(const _Self & x)
	// { return current == x.base(); }

	// bool operator!=(const _Self & x)
	// { return current != x.base(); }
	// operator< > <= >=

	friend bool operator==(const _Self & x, const _Self & y)
	{ return x.current == y.current; }

	friend bool operator!=(const _Self & x, const _Self & y)
	{ return x.current != y.current; }
};
