#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree Tree;
	Tree.insert(66);
	Tree.insert(47);
	Tree.insert(22);
	Tree.insert(56);
	Tree.insert(87);
	Tree.insert(90);
	Tree.insert(71);

	cout << "Pre order traversal:" << endl << "_______________________________" << endl;
	Tree.pre_order();
	cout << "In order traversal:" << endl << "_______________________________" << endl;
	Tree.in_order();
	cout << "post order traversal:" << endl << "_______________________________" << endl;
	Tree.post_order();
	cout << "Level order traversal:" << endl << "_______________________________" << endl;
	Tree.level_order();
	cout << "Numbers of nodes" << endl << "_______________________________" << endl;
	cout << Tree.nodes() << endl;
	cout << "Numbers of leaves" << endl << "_______________________________" << endl;
	cout << Tree.leaves() << endl;
	cout << "Numbers of fullnodes" << endl << "_______________________________" << endl;
	cout << Tree.fullnodes() << endl;
	cout << "internal path lenght" << endl << "_______________________________" << endl;
	cout << Tree.int_pathlenght() << endl;
	return 0;
}