#pragma once

#include <iostream>

namespace ft
{
template<typename T>
struct vector_iterator
{
public:
	typedef vector_iterator<T>				_Self;
	typedef std::ptrdiff_t					difference_type;
	typedef std::random_access_iterator_tag	iterator_category;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;

	T*	arr;

	vector_iterator() : arr(0) {}

	vector_iterator(T *value) : arr(value) {}

	vector_iterator(vector_iterator const & src) : arr(src.arr) {}

	vector_iterator & operator=(vector_iterator const & src)
	{
		if (this == & src)
			return *this;
		arr = src.arr;
		return *this;
	}

	~vector_iterator() {}

	reference operator*() const	{ return *arr; }
	pointer operator->() const	{ return arr; }

	vector_iterator & operator++()
	{
		++arr;
		return *this;
	}

	vector_iterator operator++(int)
	{
		vector_iterator tmp(*this);
		++arr;
		return tmp;
	}

	vector_iterator & operator--()
	{
		--arr;
		return *this;
	}

	vector_iterator operator--(int)
	{
		vector_iterator tmp(*this);
		--arr;
		return tmp;
	}

	reference operator[](difference_type n) const { return arr[n]; }

	vector_iterator & operator+=(difference_type n)
	{
		arr += n;
		return *this;
	}


	vector_iterator & operator-=(difference_type n)
	{
		arr -= n;
		return *this;
	}

	vector_iterator operator+(difference_type n) const { return vector_iterator(arr + n); }
	vector_iterator operator-(difference_type n) const { return vector_iterator(arr - n); }

	const vector_iterator &	base() const { return arr; }

	bool operator==(const _Self & it) { return arr == it.arr; }
	bool operator!=(const _Self & it) { return arr != it.arr; }
	bool operator>=(const _Self & it) { return arr >= it.arr; }
	bool operator>(const _Self & it)  { return arr > it.arr; }
	bool operator<=(const _Self & it) { return arr <= it.arr; }
	bool operator<(const _Self & it)  { return arr < it.arr; }
};


template<typename T>
struct vector_const_iterator
{
public:
	typedef vector_const_iterator<T>		_Self;
	typedef vector_iterator<T>				iterator;
	typedef std::ptrdiff_t					difference_type;
	typedef std::random_access_iterator_tag	iterator_category;
	typedef T								value_type;
	typedef const T*						pointer;
	typedef const T&						reference;

	const T*	arr;

	vector_const_iterator() : arr() {}

	vector_const_iterator(const T *value) : arr(value) {}//

	vector_const_iterator(vector_const_iterator const & src) : arr(src.arr) {}//

	vector_const_iterator(iterator const & src) : arr(src.arr) {}//

	vector_const_iterator & operator=(vector_const_iterator const & src)
	{
		if (this == & src)
			return *this;
		arr = src.arr;
		return *this;
	}

	~vector_const_iterator() {}

	reference operator*() const	{ return *arr; }
	pointer operator->() const	{ return arr; }

	_Self & operator++()
	{
		++arr;
		return *this;
	}

	_Self operator++(int)
	{
		vector_const_iterator tmp(*this);
		++arr;
		return tmp;
	}

	_Self & operator--()
	{
		--arr;
		return *this;
	}

	_Self operator--(int)
	{
		vector_const_iterator tmp(*this);
		--arr;
		return tmp;
	}

	reference operator[](difference_type n) const { return arr[n]; }

	_Self & operator+=(difference_type n)
	{
		arr += n;
		return *this;
	}

	_Self operator+(difference_type n) const { return vector_const_iterator(arr + n); }

	_Self & operator-=(difference_type n)
	{
		arr -= n;
		return *this;
	}

	const vector_const_iterator & base() const { return arr; }

	bool operator==(const _Self & it) { return arr == it.arr; }
	bool operator!=(const _Self & it) { return arr != it.arr; }
	bool operator>=(const _Self & it) { return arr >= it.arr; }
	bool operator>(const _Self & it)  { return arr > it.arr; }
	bool operator<=(const _Self & it) { return arr <= it.arr; }
	bool operator<(const _Self & it)  { return arr < it.arr; }
};
}
