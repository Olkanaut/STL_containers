#pragma once

#include <iostream>

namespace ft
{
template<typename T>
struct Node
{
	struct Node	*_next;
	struct Node	*_prev;
	explicit Node(const T & elem) : _elem(elem) {}
	Node() {}
	T			_elem;
};

template<typename T>
struct list_iterator
{
	typedef list_iterator<T>	_Self;
	typedef Node<T>				_node_type;

	typedef std::ptrdiff_t					difference_type;
	typedef std::bidirectional_iterator_tag	iterator_category;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;

	_node_type	*_node;

	list_iterator() : _node() {}

	explicit list_iterator(_node_type* node) : _node(node) {}

	list_iterator(const list_iterator & src) : _node(src._node) {}

	list_iterator &operator=(const list_iterator & src)
	{
		this->_node = src._node;
		return *this;
	}

	reference operator*() const { return _node->_elem; }
	pointer operator->() const { return &_node->_elem; }

	_Self & operator++() {
		_node = _node->_next;
		return *this;
	}

	_Self operator++(int)
	{
		_Self tmp = *this;
		_node = _node->_next;
		return tmp;
	}

	_Self & operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	_Self operator--(int)
	{
		_Self tmp = *this;
		_node = _node->_prev;
		return tmp;
	}

	list_iterator operator+(int) { return list_iterator(this->_node->_next); }//
	list_iterator operator-(int) { return list_iterator(this->_node->_prev); }//

	friend bool operator==(const _Self & x, const _Self & y) { return x._node == y._node; }
	friend bool operator!=(const _Self & x, const _Self & y) { return x._node != y._node; }
};

template<typename T>
struct list_const_iterator
{
	typedef list_const_iterator<T>	_Self;
	typedef const Node<T>			_node_type;
	typedef list_iterator<T>		iterator;///

	typedef std::ptrdiff_t					difference_type;
	typedef std::bidirectional_iterator_tag	iterator_category;
	typedef T								value_type;
	typedef const T*						pointer;
	typedef const T&						reference;

	const _node_type	*_node;

	list_const_iterator() : _node() {}

	explicit list_const_iterator(const _node_type* node) : _node(node) {}

	list_const_iterator(const iterator & x) : _node(x._node) {}

	list_const_iterator & operator=(const list_const_iterator & src)
	{
		this->_node = src._node;
		return *this;
	}

	reference operator*() const { return _node->_elem; }
	pointer operator->() const { return &_node->_elem; }

	_Self & operator++()
	{
		_node = _node->_next;
		return *this;
	}

	_Self operator++(int)
	{
		_Self tmp = *this;
		_node = _node->_next;
		return tmp;
	}

	_Self & operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	_Self operator--(int)
	{
		_Self tmp = *this;
		_node = _node->_prev;
		return tmp;
	}

	friend bool operator==(const _Self & x, const _Self & y)
	{ return x._node == y._node; }

	friend bool operator!=(const _Self & x, const _Self & y)
	{ return x._node != y._node; }
};
}
