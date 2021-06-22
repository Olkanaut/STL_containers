#include <iostream>
#include <map>
#include <iomanip>
#include "tree.h"

// int	main()
// {
// 	std::map<int, int> map;
// 	std::pair<int, int> pair(2,3);
// 	map.insert(pair);
// 	std::cout << map[2] << std::endl;
// 	std::cout << map[567] << std::endl;

// }

int main()
{
	Tree<int> intTree;
	int a;
	std::cout<<"10 numbers:" << std::endl;
	for(int i=0;i<10;i++)
	{
		// std::cin >> a;
		intTree.insert_node(i);
	}
	// std::cout << "inorder_walk:" << std::endl;
	// intTree.inorder_walk(intTree.get_root());
	std::cout << "Minimum is: " << (intTree.find_min(intTree.get_root()))->get_data() << std::endl;
	std::cout << "Maximum is: " << (intTree.find_max(intTree.get_root()))->get_data() << std::endl;
	std::cout << "Enter node value U want to delete:";
	std::cin >> a;
	intTree.delete_node(intTree.find_node(intTree.get_root(),a));
	std::cout << "Now inorder_walk:" << std::endl;
	intTree.inorder_walk(intTree.get_root());

}
