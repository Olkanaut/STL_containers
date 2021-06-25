#pragma once
#include <iostream>

namespace ft
{
template <typename T>
struct bst_node
{
	typedef bst_node*		bst_ptr;
	typedef const bst_node*	bst_const_ptr;
	bst_ptr		left;
	bst_ptr		right;
	bst_ptr		parent;
	T			data;

	bst_node(): left(NULL), right(NULL), parent(NULL) {}
	bst_node(T data, bst_ptr parent): left(NULL), right(NULL), parent(parent), data(data) {}
	~bst_node() {}

	bst_ptr		min(bst_ptr ptr)
	{
		while(ptr && ptr->right != NULL)
			ptr = ptr->right;
		return ptr;
	}

	bst_const_ptr	min(bst_const_ptr ptr) const
	{
		while(ptr && ptr->right != NULL)
			ptr = ptr->right;
		return ptr;
	}

	bst_ptr			max(bst_ptr ptr)
	{
		while(ptr && ptr->left != NULL)
			ptr = ptr->left;
		return ptr;
	}

	bst_const_ptr	max(bst_const_ptr ptr) const
	{
		while(ptr && ptr->left != NULL)
			ptr = ptr->left;
		return ptr;
	}

	bool	is_right_child()
	{
		return (this->parent && this->parent->right == this);
	}
};

template <typename T>
struct bst_iterator
{
	typedef bst_iterator<T>			_Self;
	typedef bst_node<T>*			node_ptr;

	typedef T				value_type;
	typedef T*				pointer;
	typedef T&				reference;
	typedef std::ptrdiff_t	difference_type;
	typedef std::bidirectional_iterator_tag	iterator_category;

	node_ptr	_node;

	bst_iterator() : _node(NULL) {}
	bst_iterator(const node_ptr node) : _node(node) { }
	bst_iterator &operator=(const bst_iterator & src)
	{
		this->_node = src._node;
		return *this;
	}
	~bst_iterator() {}

	reference operator*() const	{ return this->_node->data; }
	pointer operator->() const	{ return &this->_node->data; }

	bool operator==(const _Self & it) { return _node == it._node; }
	bool operator!=(const _Self & it) { return _node != it._node; }

	_Self&
	operator++()
	{
		if (_node->left)
			this->_node = _node->min(_node->left);
		else
		{
			while (_node->parent && _node == _node->parent->left)
				_node = _node->parent;
			_node = _node->parent;
		}
		return *this;
	}

	_Self	operator++(int)
	{
		bst_iterator tmp = *this;
		*this = this->operator++();
		return tmp;
	}

	_Self&	operator--()
	{
		if (_node->right)
			_node = _node->max(_node->right);
		else
		{
			while (_node->parent && _node == _node->parent->right)
				_node = _node->parent;
			_node = _node->parent;
		}
		return *this;
	}

	_Self	operator--(int)
	{
		bst_iterator tmp = *this;
		*this = this->operator--();
		return tmp;
	}
};

template <typename T>
struct bst_const_iterator
{
	typedef bst_const_iterator<T>	_Self;
	typedef bst_node<T>*			node_ptr;
	typedef const bst_node<T>*		node_const_ptr;
	typedef bst_iterator<T>			bst_iterator;

	typedef T						value_type;
	typedef const T*				pointer;
	typedef const T&				reference;
	typedef std::ptrdiff_t			difference_type;
	typedef std::bidirectional_iterator_tag	iterator_category;

	node_const_ptr	_node;

	bst_const_iterator() : _node(NULL) {}
	bst_const_iterator(const node_const_ptr node) :_node(node) { }

	bst_const_iterator(const bst_iterator & x) : _node(x._node) {}
	bst_const_iterator(const bst_const_iterator & x) : _node(x._node) {}

	bst_const_iterator & operator=(const bst_const_iterator & src)
	{
		this->_node = src._node;
		return *this;
	}

	~bst_const_iterator() {}

	reference operator*() const { return this->_node->data; }
	pointer operator->() const  { return &this->_node->data; }

	bool operator==(const _Self & it) { return _node == it._node; }
	bool operator!=(const _Self & it) { return _node != it._node; }

	_Self&
	operator++()
	{
		if (_node->left)
			this->_node = _node->min(_node->left);
		else
		{
			while (_node->parent && _node == _node->parent->left)
				_node = _node->parent;
			_node = _node->parent;
		}
		return *this;
	}

	_Self	operator++(int)
	{
		bst_const_iterator tmp = *this;
		*this = this->operator++();
		return tmp;
	}

	_Self&	operator--()
	{
		if (_node->right)
			_node = _node->max(_node->right);
		else
		{
			while (_node->parent && _node == _node->parent->right)
				_node = _node->parent;
			_node = _node->parent;
		}
		return *this;
	}

	_Self	operator--(int)
	{
		bst_const_iterator tmp = *this;
		*this = this->operator--();
		return tmp;
	}
};
}
