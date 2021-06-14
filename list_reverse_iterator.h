#pragma once

#include <iostream>
#include "list_node.h"

template<typename Iter_type>
struct list_reverse_iterator : public Iter_type
{
protected:
	Iter_type	current;

public:
	typedef list_reverse_iterator<Iter_type>	_Self;

	typedef Iter_type								iterator_type;//
	typedef typename Iter_type::difference_type		difference_type;
	typedef typename Iter_type::iterator_category	iterator_category;//
	typedef typename Iter_type::value_type			value_type;//?
	typedef typename Iter_type::pointer				pointer;//
	typedef typename Iter_type::reference			reference;//?

	// typedef const Iter_type*				const_pointer;//
	// typedef const Iter_type&				const_reference;//

	list_reverse_iterator() : Iter_type() { }
	list_reverse_iterator(Iter_type const & it) : Iter_type(it), current(it) { }//
	list_reverse_iterator(list_reverse_iterator const & src) : Iter_type(src.current), current(src.base()) {}
	list_reverse_iterator &operator=(list_reverse_iterator const & src)
	{
		this->current = src.current;
		return *this;
	}

    template <class _Up>
        list_reverse_iterator( const list_reverse_iterator<_Up> & src) : Iter_type(src.base()), current(src.base()) {}
// Iter_type(src.current),
        // list_reverse_iterator( list_reverse_iterator<_Up> const & src) : current(src.base()) {}
        // list_reverse_iterator(const list_reverse_iterator<_Up>& src) : Iter_type(src.current) {}


	// explicit list_reverse_iterator(Iter_type iter) : current(iter) { }

      /**
       *  The copy constructor is normal.
      */
	// list_reverse_iterator(const list_reverse_iterator & src) : current(src.current) { }
	// list_reverse_iterator(const list_reverse_iterator & src) : current(src.current) { }
	// list_reverse_iterator(const list_reverse_iterator & src) : current(src.base()) { }



	// list_reverse_iterator& operator=(const list_reverse_iterator & src) = default;

    //   /**
    //    *  A %reverse_iterator across other types can be copied if the
    //    *  underlying %iterator can be converted to the type of @c current.
    //   */
	// template<typename Iter_type>
	// list_reverse_iterator(const list_reverse_iterator<Iter_type>& x)
	// : current(x.base()) { };

	Iter_type base() const { return current; }


//operator= ? // <> >= <= + -
	reference operator*()
	{
		Iter_type tmp = current;
		return *--tmp;
	}

	reference operator*() const//const?
	{
		Iter_type tmp = current;
		return *--tmp;
	}

	pointer operator->()
	{
		return &(operator*());
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

	bool operator==(const _Self & x)
	{ return current == x.base(); }

	bool operator!=(const _Self & x)
	{ return current != x.base(); }
	// operator< > <= >=



	// friend bool operator==(const _Self & x, const _Self & y)
	// { return x.current == y.current; }

	// friend bool operator!=(const _Self & x, const _Self & y)
	// { return x.current != y.current; }
};
