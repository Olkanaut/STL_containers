#pragma once

#include <iostream>

template<typename T>
struct Node
{
	struct Node	*_next;
	struct Node	*_prev;
	explicit Node(const T & elem) : _elem(elem) {}
	Node() {}
	T			_elem;
};
