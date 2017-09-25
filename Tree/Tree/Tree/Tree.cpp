// Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AvlTree.h"
#include "BinarySearchTree.h"


int main()
{
	BinarySearchTree Tree;

	for (int i = 0; i < 100; i++)
	{
		Tree.insert(rand() % 10 + 1);
	}
	Tree.printTree();

	Tree.pre_order();
    return 0;
}

