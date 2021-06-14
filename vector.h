#pragma once

# include <iostream>
# include <limits>
#include <string>//
#include <fstream>//

// # include <array>
// # include <vector>
// # include "vector.ipp"
# include "vector_iterator.h"
# include "list.h"

// _GLIBCXX_PROFILE_ARRAY

namespace ft
{
template <typename T, typename Alloc = std::allocator<T> >
class vector
{
public:
	typedef T		value_type;
	typedef Alloc	allocator_type;

	typedef typename Alloc::reference			reference;
	typedef typename Alloc::const_reference		const_reference;
	typedef typename Alloc::pointer				pointer;//_Base::pointer
	typedef typename Alloc::const_pointer		const_pointer;
	typedef	typename Alloc::difference_type 	difference_type;//	Signed integer type (usually std::ptrdiff_t)
	typedef	typename Alloc::size_type			size_type;
	typedef vector_iterator<T>					iterator;
	typedef vector_const_iterator<T>			const_iterator;
	typedef list_reverse_iterator<iterator>		reverse_iterator;//list
	typedef list_reverse_iterator<const_iterator> const_reverse_iterator;//list

private:
	T*				_arr;
	size_type		_size;
	size_type		_capacity;
	allocator_type	_alloc;

	void print_vector()
	{
		std::cout << "vector: ";
		for (size_type i = 0; i < _size; ++i)
			std::cout << " " << _arr[i];
		std::cout << std::endl;
	}

	void	init(size_type n, const value_type & val, true_type)
	{
		// if (n)
		_arr = _alloc.allocate(n);
		for (size_type i = 0; i < n; ++i)
			_alloc.construct(_arr + i, val);
		_capacity = n;///
		_size = n;
	}

	template <class InputIt>
	void	init(InputIt first, InputIt last, false_type)
	{
		size_type size = 0;
		for (InputIt it = first; it != last; ++it)
			size++;
		_arr = _alloc.allocate(size);

		size_type i = 0;
		for (; first != last; ++first, i++)
			_alloc.construct(_arr + i, *first);
		_size = size;
		_capacity = size;
	}

    // {
    //   if (__n > capacity())
	// {
	//   vector __tmp(__n, __val, _M_get_Tp_allocator());
	//   __tmp._M_impl._M_swap_data(this->_M_impl);
	// }
    //   else if (__n > size())
	// {
	//   std::fill(begin(), end(), __val);
	//   const size_type __add = __n - size();
	//   _GLIBCXX_ASAN_ANNOTATE_GROW(__add);
	//   this->_M_impl._M_finish =
	//     std::__uninitialized_fill_n_a(this->_M_impl._M_finish,
	// 				  __add, __val, _M_get_Tp_allocator());
	//   _GLIBCXX_ASAN_ANNOTATE_GREW(__add);
	// }
    //   else
    //     _M_erase_at_end(std::fill_n(this->_M_impl._M_start, __n, __val));
    // }

	void assign(size_type n, const value_type & val, true_type)
	{
		if (_size > 0 && n < _capacity)
			clear();
		if (n > _capacity)//reserve
			reserve(n);
		for (size_type i = 0; i < n; i++)
			_alloc.construct(_arr + i, val);
		_size = n;
	}

	template <class InputIter>
	void assign(InputIter first, InputIter last, false_type)
	{
		size_type len = 0;// = std::distance(first, last);
		for (InputIter it = first; it != last; ++it)
			len++;
		if (_size > 0 && len < _capacity)
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_arr + i);
			_size = 0;
		}
		if (len > _capacity)
		{
			// std::cout << "len: " << len << "\n";
			reserve(len);
		}
		for (size_type i = 0; i < len; i++, _size++)
		{
			_alloc.construct(_arr + i, *first);
			++first;
		}
	}

		iterator	_vector_fill_insert(iterator pos, size_type n, const value_type& val)
		{
			if (n == 0)
				return (pos);

			iterator	res = pos;
			if (_size + n > _capacity)
			{
				vector		tmp;
				if (_size + n <= _capacity * 2)
					tmp.reserve(_capacity * 2);
				else
					tmp.reserve(_size + n);

				iterator	it = this->begin();
				while (it != pos)
					tmp.push_back(*it++);

				res = tmp.end();
				for (size_type i = 0; i < n; i++)
					tmp.push_back(val);

				while (it != this->end())
					tmp.push_back(*it++);

				swap(tmp);
			}
			else
			{
				iterator	it = end();
				while (it != pos)
				{
					--it;
					_alloc.construct(&(*(it + n)), *it);
					_alloc.destroy(&(*it));
				}
				for (size_type i = 0; i < n; i++)
				{
					_alloc.construct(&(*it), val);//_alloc.construct(_arr + _size, val);
					++it;
					++_size;
				}
			}

			return (res);
		}

	void		insert(iterator pos, size_type n, const value_type& val, true_type)
	{
		_vector_fill_insert(pos, static_cast<size_type>(n), val);
	}

	template <class InputIter>
	void		insert(iterator pos, InputIter first, InputIter last, false_type)
	{
		if (first == last)
			return ;
		vector tmp(first, last);	//	in case [first, last) are from this vector
		for (size_type i = 0; i < tmp.size(); i++)
		{
			pos = _vector_fill_insert(pos, 1, tmp.at(i));
			++pos;
		}
	}

public:
	// explicit vector(const allocator_type & alloc = allocator_type())  : _start(), _finish(), _end_of_storage() {}
	explicit vector(const allocator_type & a = allocator_type())
	: _arr(NULL), _size(0), _capacity(0), _alloc(a) {}

	// explicit vector(size_type n, const allocator_type & a = allocator_type()){}
	// // : _Base(_S_check_init_len(__n, __a), __a)
	// // { _M_default_initialize(__n); }

	explicit vector(size_type n, const value_type & val = value_type(), const allocator_type & a = allocator_type())
	: _arr(NULL), _size(0), _capacity(0), _alloc(a) { init(n, val, true_type()); }
	// : _alloc(a) { init(n, val, true_type()); }
	// : _Base(_S_check_init_len(__n, __a), __a)
	// { _M_fill_initialize(__n, __value); }

	template <class InputIt>
	vector (InputIt first, InputIt last, const allocator_type& a = allocator_type())
	: _arr(NULL), _size(0), _capacity(0), _alloc(a)
	{
		typedef typename ft::is_int<InputIt>::type is_int;//check other types long size_t
		init(first, last, is_int());
	}

	// vector(vector const & src) : vector(src.begin(), src.end()) {}//_alloc
	// vector(vector const & src) : _start(src._start), _finish(src._finish), _end_of_storage(src._end_of_storage) {}
	// { __x._M_start = __x._M_finish = __x._M_end_of_storage = pointer(); }
	vector(vector const & src)
	: _arr(NULL), _size(0), _capacity(0), _alloc(src._alloc) { *this = src; }//_alloc

	vector & operator=(vector const & src)//
	{
		if (this == &src)
			return *this;
		this->assign(src.begin(), src.end());//delete_vector
		this->_alloc = src._alloc;
		this->_size = src._size;
		this->_capacity = src._capacity;
		return *this;
	}

	~vector()
	{
		if (!this->_arr)//size?
			return ;
		for (size_type i = 0; i < this->_size; i++)
			this->_alloc.destroy(this->_arr + i);
		this->_alloc.deallocate(this->_arr, this->_capacity);//_capacity
		this->_arr = NULL;
		this->_size = 0;
		this->_capacity = 0;
	}

public:
	void assign (size_type n, const value_type & val)
	{ assign(n, val, true_type()); }

	template <class InputIt>
	void assign (InputIt first, InputIt last)
	{
		typedef typename ft::is_int<InputIt>::type is_int;//check other types long size_t
		assign(first, last, is_int());
	}

	reference		at (size_type n)
	{
		if (n >= _size)
			throw std::out_of_range("index is out of range");
		return _arr[n];
	}
	const_reference	at (size_type n) const
	{
		if (n >= _size)
			throw std::out_of_range("index is out of range");
		return _arr[n];
	}

	reference		back()			{ return _arr[_size-1]; }
	const_reference	back() const	{ return _arr[_size-1]; }
	reference		front()			{ return _arr[0]; }
	const_reference front() const	{ return _arr[0]; }

	iterator		begin()			{ return iterator(_arr); }
	const_iterator	begin() const	{ return const_iterator(_arr); }
	iterator		end()			{ return iterator(_arr + _size); }
	const_iterator	end() const		{ return const_iterator(_arr + _size); }

	iterator		rbegin()		{ return reverse_iterator(_arr + _size); }//
	const_iterator	rbegin() const	{ return const_reverse_iterator(_arr + _size); }//
	iterator		rend()			{ return reverse_iterator(_arr); }//
	const_iterator	rend() const	{ return const_reverse_iterator(_arr); }//


	void		clear() { this->erase(begin(), end()); }//vector().swap(x);   // clear x reallocating

	// iterator	erase(iterator pos) { return(erase(pos, pos + 1)); }
	iterator	erase(iterator pos)
	{
		size_type idx = pos.arr - _arr;
		_alloc.destroy(&_arr[idx]);
		iterator it = pos;
		while (++idx != _size)
		{
			_alloc.construct(&_arr[idx - 1], _arr[idx]);
			_alloc.destroy(&_arr[idx]);
		}
		--_size;
		return pos;
	}

	iterator	erase(iterator first, iterator last)
	{
		size_type dist = last.arr - first.arr;
		if (dist <= 0)
			return first;
		for (iterator it = first; it != last; ++it)
			_alloc.destroy(&(*it));
		size_type offset = last.arr - _arr;
		for (size_type i = offset; i < _size; i++)
		{
			_alloc.construct(&_arr[i - dist], _arr[i]);
			_alloc.destroy(&_arr[i]);
		}
		_size -= dist;
		return first;
	}

	iterator	insert(iterator pos, const value_type & val)
	{
		std::cout << "here " << *pos << "\t";
		// size_type offset = 0;
		// for (iterator it = begin(); it != pos; ++it)	// ++offset;
		size_type offset = pos.arr - begin().arr;
		if (_size + 1 > _capacity)
			reserve(_size + 1);
		size_type i = _capacity - 1;
		for (; i > offset; --i)
		{
			_alloc.construct(&_arr[i], _arr[i - 1]);
			_alloc.destroy(&_arr[i - 1]);
		}
		_alloc.construct(&_arr[i], val);
		_size++;
		std::cout << "arr[i]: " << _arr[i] << "\n";
		return pos;
	}

	void		insert(iterator pos, size_type n, const value_type& val)
	{
		insert(pos, n, val, true_type());
	}

	template <class InputIter>
	void		insert(iterator pos, InputIter first, InputIter last)
	{
		typedef typename ft::is_int<InputIter>::type is_int;//check other types long size_t
		insert(pos, first, last, is_int());
	}

	reference		operator[](size_type n) { return _arr[n]; }
	const_reference	operator[](size_type n) const { return _arr[n]; }




	void		push_back(const value_type & val)
	{
		if (_size == _capacity)
		{
			if (_capacity == 0)
				reserve(1);
			else
				reserve(_capacity * 2);//_capacity = //
		}
		_alloc.construct(_arr + _size, val);
		++_size;
	}

	void		pop_back()
	{
		_alloc.destroy(_arr + _size - 1);//_alloc.destroy(&*(--end()));
		_size--;
	}

	bool		empty() const { return this->_size == 0; }//cursize==0
	size_type	size() const { return _size; }
	size_type	max_size() const
	{
		return std::numeric_limits<size_type>::max() / sizeof(value_type) / 2;
		// // return (size_type)(-1) / sizeof(T) / 2 ;
	}
	// https://www.codeproject.com/Questions/581266/vectorplusmax-sizepluscalculation-2cplushow-3f
	// https://stackoverflow.com/questions/7874464/c-vector-of-pointer-to-object-max-size

	size_type 	capacity() const { return _capacity; };

	void	_copy_assign(const vector & src)
	{
		clear();
		if (src._size > this->_capacity)
		{
			// src._alloc.deallocate(src._arr, src._capacity);//_vector_base_free()
			_alloc.deallocate(_arr, _capacity);//_vector_base_free()

			_size = 0;
			_capacity = src._size;
			_arr = _alloc.allocate(_capacity);
		}
		for (size_type i = 0; i < src._size; i++)
			push_back(src.at(i));
			// push_back(src._arr[i]);

	}

	void	reserve(size_type n)
	{
		if (n > max_size())
			throw std::length_error("length error: vector::reserve\n");
		if (_capacity < n)
		{
			vector tmp;
			// tmp._alloc.deallocate(tmp._arr, tmp._capacity);

			tmp._size = 0;
			tmp._capacity = n;
			tmp._arr = _alloc.allocate(n);

			tmp._copy_assign(*this);
			swap(tmp);
		}
	}
	void	resize(size_type n, value_type val = value_type())
	{
		if (n > _size)
		{
			if (n > _capacity)
				reserve(n);
			for (size_type i = _size; i < n; i++, _size++)//i != n
				_alloc.construct(_arr + i, val);
		}
		else if (n < _size)
			erase(iterator(&_arr[n]), end());
			//_M_erase_at_end(this->_M_impl._M_start + __new_size);
	}

// from: struct _Vector_base -> struct _Vector_impl_data
	void	swap(vector & x)
	{
		pointer xarr = this->_arr;
		size_type xcapacity = this->_capacity;
		size_type xsize = this->_size;

		this->_arr = x._arr;
		this->_capacity = x._capacity;
		this->_size = x._size;

		x._arr = xarr;
		x._capacity = xcapacity;
		x._size = xsize;
	}
	//friend iterator operator+(int n, iterator &iter) { return (iter + n); }
	//friend const_iterator operator+(int n, const_iterator &iter) { return (iter + n); }
	//friend reverse_iterator operator+(int n, reverse_iterator &iter) { return (iter + n); }
	//friend const_reverse_iterator operator+(int n, const_reverse_iterator &iter) { return (iter + n); }
// All iterators, references and pointers remain valid for the swapped objects
};

///// non-member overloads:
	template< class T, class Alloc >
	bool operator==(const ft::vector<T, Alloc> & x, const ft::vector<T, Alloc> & y)
	{
		// if (x.size() != y.size()) //c++11
		// 	return false;
		typename ft::vector<T, Alloc>::const_iterator itx = x.begin();
		typename ft::vector<T, Alloc>::const_iterator ity = y.begin();
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
	bool operator!=(const ft::vector<T, Alloc> & x, const ft::vector<T, Alloc> & y)
	{
		return !(x == y);
	}

	template< class T, class Alloc >
	bool operator<(const ft::vector<T, Alloc> & x, const ft::vector<T, Alloc> & y)
	{
		typename ft::vector<T, Alloc>::const_iterator ix = x.begin();
		typename ft::vector<T, Alloc>::const_iterator iy = y.begin();
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
	bool operator<=(const ft::vector<T, Alloc> & x, const ft::vector<T, Alloc> & y){
		return !(y < x);
	}

	template< class T, class Alloc >
	bool operator>(const ft::vector<T, Alloc> & x, const ft::vector<T, Alloc> & y){
		return y < x;
	}

	template< class T, class Alloc >
	bool operator>=(const ft::vector<T, Alloc> & x, const ft::vector<T, Alloc> & y){
		return !(x < y);
	}

	template< class T, class Alloc >
	void swap(ft::vector<T, Alloc> & x, ft::vector<T, Alloc> & y){
		x.swap(y);
	}
}
