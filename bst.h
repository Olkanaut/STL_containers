#pragma once
#include <iostream>

#include "bst_node.h"
#include "my_reverse_iterator.h"

namespace ft
{
template<typename Key,
		typename T,
		typename Compare >
class bst
{
public:
	typedef Key			key_type;
	typedef T			value;
	typedef Compare		key_compare;
	typedef std::pair<const key_type, value>	value_type;

	typedef T*			pointer;
	typedef const T*	const_pointer;
	typedef T&			reference;
	typedef const T&	const_reference;

	typedef bst_node<value_type>					node;
	typedef bst_iterator<value_type>				iterator;
	typedef bst_const_iterator<value_type>			const_iterator;
	typedef my_reverse_iterator<iterator>			reverse_iterator;
	typedef my_reverse_iterator<const_iterator>		const_reverse_iterator;

	typedef size_t			size_type;
	typedef std::ptrdiff_t	difference_type;

private:
	node*		root_ptr;
	node		end_ptr;
	size_type	_size;
	key_compare	comp;

	bool		compare_keys(const key_type &a, const key_type &b) const { return comp(a, b); }

public:
	~bst() { this->clear(); }
	bst(const key_compare &comp = key_compare()) : comp(comp)
	{
		root_ptr = NULL;
		_size = 0;
	};

	iterator				begin()			{ return iterator(root_ptr ? root_ptr->min(root_ptr) : &end_ptr); }
	const_iterator			begin() const	{ return const_iterator(root_ptr ? root_ptr->min(root_ptr) : &end_ptr); }
	iterator				end()			{ return iterator(&end_ptr); }
	const_iterator			end() const		{ return const_iterator(&end_ptr); }
	reverse_iterator		rend()			{ return reverse_iterator(root_ptr ? (root_ptr->min(root_ptr)) : &end_ptr); }
	const_reverse_iterator	rend() const	{ return const_reverse_iterator(root_ptr ? (root_ptr->min(root_ptr)) : &end_ptr); }
	reverse_iterator		rbegin()		{ return reverse_iterator(&end_ptr); }
	const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(&end_ptr); }

	const key_compare &		key_comp() const { return comp; }
	key_compare &			key_comp()		 { return comp; }
	size_type				get_size() const { return _size; }

	iterator		find(key_type key)
	{
		iterator	it = this->begin();
		iterator	ite = this->end();
		while (it != ite)
		{
			if ((*it).first == key)
				return it;
			++it;
		}
		return ite;
	}

	const_iterator	find(key_type key) const
	{
		const_iterator	it = this->begin();
		const_iterator	ite = this->end();
		while (it != ite)
		{
			if ((*it).first == key)
				return it;
			++it;
		}
		return ite;
	}

	iterator		lower_bound(key_type key)
	{
		iterator	it = this->begin();
		iterator	ite = this->end();
		while (it != ite)
		{
			if (!compare_keys((*it).first, key))
				return it;
			++it;
		}
		return ite;
	}

	const_iterator	lower_bound(key_type key) const
	{
		const_iterator	it = this->begin();
		const_iterator	ite = this->end();
		while (it != ite)
		{
			if (!compare_keys((*it).first, key))
				return it;
			++it;
		}
		return ite;
	}

	iterator		upper_bound(key_type key)
	{
		iterator	it = this->begin();
		iterator	ite = this->end();
		while (it != ite)
		{
			if (compare_keys(key, (*it).first))
				return it;
			++it;
		}
		return ite;
	}

	const_iterator	upper_bound(key_type key) const
	{
		const_iterator	it = this->begin();
		const_iterator	ite = this->end();
		while (it != ite)
		{
			if (compare_keys(key, (*it).first))
				return it;
			++it;
		}
		return ite;
	}

	std::pair<iterator, bool>	insert(value_type new_value)
	{
		if (!root_ptr)
		{
			root_ptr = new node(new_value, NULL);
			root_ptr->left = &end_ptr;
			end_ptr.parent = root_ptr;
			_size++;
			return std::pair<iterator, bool>(iterator(root_ptr), true);
		}

		node* temp = root_ptr;
		node* temp_last = temp;

		while (temp && temp != &end_ptr)
		{
			if (new_value.first == temp->data.first)
				return std::pair<iterator, bool>(iterator(temp), false);
			if (compare_keys(new_value.first, temp->data.first))
				temp = temp->right;
			else
				temp = temp->left;
			if (temp && temp != &end_ptr)
				temp_last = temp;
		}

		node* new_node = new node(new_value, temp_last);
		if (temp_last->left == &end_ptr && compare_keys(temp_last->data.first, new_value.first))// new_value.first > temp_last->data.first)
		{
			temp_last->left = new_node;
			new_node->left = &end_ptr;
			end_ptr.parent = new_node;
		}
		else
			compare_keys(temp_last->data.first, new_value.first) ? temp_last->left = new_node : temp_last->right = new_node;
		_size++;
		return std::pair<iterator,bool>(iterator(new_node), true);
	};

	iterator	insert(iterator pos, const value_type & val)
	{
		iterator ite = this->end();
		node *tmp = pos._node;
		if (pos != ite && tmp->left == &end_ptr && comp(tmp->data.first, val.first))
		{
			node *new_node = new node(val, tmp);
			tmp->left = new_node;
			new_node->left = &end_ptr;
			++_size;
			return iterator(new_node);
		}
		std::pair<iterator, bool> res = this->insert(val);
		return res.first;
	}

	value & operator[] (const key_type& key)
	{
		iterator key_pos = find(key);
		iterator ite = end();

		if (key_pos != ite)
			return (*key_pos).second;
		std::pair<const key_type, value> new_val(key, 0);
		iterator itres = insert(ite, new_val);
		return (*itres).second;
	};

	void		clear()
	{
		iterator	it = this->begin();
		iterator	ite = this->end();
		while (it != ite)
		{
			remove((*it).first);
			it = this->begin();
		}
		root_ptr = NULL;
	}

	inline void	swap(bst& x)
	{
		node* temp_root = x.get_root();
		node* temp_prev = x.get_prev();
		node* temp_end = x.get_end();

		x.set_root(root_ptr);
		temp_end->parent = end_ptr.parent;
		if (end_ptr.parent)
			end_ptr.parent->left = temp_end;

		root_ptr = temp_root;
		if (temp_prev)
			temp_prev->left = &end_ptr;
		end_ptr.parent = temp_prev;

		_size = x.set_size(_size);
	}

	size_type	remove(key_type const & rem_key)
	{
		iterator	to_rem = this->find(rem_key);
		iterator	i_e = this->end();
		if (to_rem != i_e)
		{
			node*	rem_node = to_rem._node;
			if (rem_node->right && rem_node->left)
			{
				node* temp = rem_node->min(rem_node->left);
				temp->right = rem_node->right;
				rem_node->right->parent = temp;
				rem_node->right = NULL;
			}
			node*	temp_ass = (rem_node->right ? rem_node->right : rem_node->left);
			if (rem_node->parent)
			{
				if (rem_node->is_right_child())
					rem_node->parent->right = temp_ass;
				else
					rem_node->parent->left = temp_ass;
				if (temp_ass)
					temp_ass->parent = rem_node->parent;
			}
			else
			{
				root_ptr = temp_ass;
				if (temp_ass)
					temp_ass->parent = NULL;
			}
			_size -= 1;
			delete rem_node;
			return 1;
		}
		return 0;
	}

private:
	inline size_type	set_size(size_type new_size)
	{
		size_type temp_size = _size;
		_size = new_size;
		return temp_size;
	}
	inline node*	get_root(){ return root_ptr; }
	inline node*	get_prev(){ return end_ptr.parent; }
	inline node*	get_end(){ return &end_ptr; }
	inline void		set_root(node* root){ root_ptr = root; }
	inline void		set_prev(node* prev){ end_ptr.parent = prev; }
};
}
