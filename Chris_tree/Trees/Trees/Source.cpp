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
	cout << "post order traversal:" << endl << "_______________________________" << endl;
	Tree.level_order();

	return 0;
}