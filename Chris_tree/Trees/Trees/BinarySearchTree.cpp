#include "BinarySearchTree.h"
#include <queue>

BinarySearchTree::BinarySearchTree() : root{ nullptr }
{
}


BinarySearchTree::BinarySearchTree(const BinarySearchTree & rhs) : root{ nullptr }
{
	root = clone(rhs.root);
}


BinarySearchTree::BinarySearchTree(BinarySearchTree && rhs) : root{ rhs.root }
{
	rhs.root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	makeEmpty();
}

const int & BinarySearchTree::findMin() const
{
	if (isEmpty())
		return -1;
	return findMin(root)->element;
}


const int & BinarySearchTree::findMax() const
{
	if (isEmpty())
		return -1;
	return findMax(root)->element;
}

bool BinarySearchTree::contains(const int & x) const
{
	return contains(x, root);
}

bool BinarySearchTree::isEmpty() const
{
	return root == nullptr;
}

void BinarySearchTree::printTree() const
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	else
		printTree(root);
}

void BinarySearchTree::makeEmpty()
{
	makeEmpty(root);
}


void BinarySearchTree::insert(const int & x)
{
	insert(x, root);
}

void BinarySearchTree::insert(int && x)
{
	insert(std::move(x), root);
}

void BinarySearchTree::remove(const int & x)
{
	remove(x, root);
}

void BinarySearchTree::pre_order()
{
	if (isEmpty())
		cout << "empty tree" << endl;
	else
		pre_order(root);
}

void BinarySearchTree::in_order()
{
	if (isEmpty())
		cout << "empty tree" << endl;
	else
		in_order(root);
}

void BinarySearchTree::post_order()
{
	if (isEmpty())
		cout << "empty tree" << endl;
	else
		post_order(root);
}

void BinarySearchTree::level_order()
{
	if (isEmpty())
		cout << "empty tree" << endl;
	else
		level_order(root);
}

int BinarySearchTree::nodes()
{
	if (isEmpty())
	{
		cout << "empty tree" << endl;
		return 0;
	}
	else
		return nodes(root);
}

int BinarySearchTree::leaves()
{
	if (isEmpty())
		cout << "empty tree" << endl;
	else
		return leaves(root);
}

int BinarySearchTree::fullnodes()
{
	if (isEmpty())
		cout << "empty tree" << endl;
	else
		return fullnodes(root);
}

int BinarySearchTree::int_pathlenght()
{
	if (isEmpty())
		cout << "empty tree" << endl;
	return int_pathlenght(root,0);
}

void BinarySearchTree::pre_order(BinaryNode * t)
{
	if (t != nullptr)
	{
		cout << t->element << endl;
		pre_order(t->left);
		pre_order(t->right);
	}
}

void BinarySearchTree::in_order(BinaryNode * t)
{
	if (t != nullptr)
	{
		in_order(t->left);
		cout << t->element << endl;
		in_order(t->right);
	}
}

void BinarySearchTree::post_order(BinaryNode * t)
{
	if (t != nullptr)
	{
		post_order(t->left);
		post_order(t->right);
		cout << t->element << endl;
	}
}

void BinarySearchTree::level_order(BinaryNode * t)
{
	queue<BinaryNode*> queue;
	BinaryNode *root = t;
	queue.push(root);
	while (!queue.empty())
	{
		if (queue.front()->left != nullptr)
			queue.push(queue.front()->left);
		if (queue.front()->right != nullptr)
			queue.push(queue.front()->right);
		cout << queue.front()->element << endl;
		queue.pop();
	}


}

int BinarySearchTree::nodes(BinaryNode * t)
{
	int numbers = 0;
	if (t == nullptr)
		return 0;

	numbers += nodes(t->left);
	numbers += nodes(t->right);
	return numbers+1;
}

int BinarySearchTree::leaves(BinaryNode * t)
{
	int count = 0;
	if (t == nullptr)
		return 0;

	if (t->left == nullptr && t->right == nullptr)
		return 1;

	count += leaves(t->left);
	count += leaves(t->right);

	return count;
}

int BinarySearchTree::fullnodes(BinaryNode * t)
{
	int count = 0;

	if (t == nullptr)
		return 0;

	count += fullnodes(t->left);
	count += fullnodes(t->right);

	if (t->left != nullptr && t->right != nullptr)
		return count + 1;
	return count;


}

int BinarySearchTree::int_pathlenght(BinaryNode * t, int value)
{
	if (t == nullptr)
		return 0;

	return value + int_pathlenght(t->left, value + 1) + int_pathlenght(t->right, value + 1);
}

void BinarySearchTree::insert(const int & x, BinaryNode * & t)
{
	if (t == nullptr)
		t = new BinaryNode{ x, nullptr, nullptr };
	else if (x < t->element)
		insert(x, t->left);
	else if (t->element < x)
		insert(x, t->right);
	else
		;  // Duplicate; do nothing
}


void BinarySearchTree::insert(int && x, BinaryNode * & t)
{
	if (t == nullptr)
		t = new BinaryNode{ std::move(x), nullptr, nullptr };
	else if (x < t->element)
		insert(std::move(x), t->left);
	else if (t->element < x)
		insert(std::move(x), t->right);
	else
		;  // Duplicate; do nothing
}

void BinarySearchTree::remove(const int & x, BinaryNode * & t)
{
	if (t == nullptr)
		return;   // Item not found; do nothing
	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != nullptr && t->right != nullptr) // Two children
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		BinaryNode *oldNode = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
	}
}

BinaryNode * BinarySearchTree::findMin(BinaryNode *t) const
{
	if (t == nullptr)
		return nullptr;
	if (t->left == nullptr)
		return t;
	return findMin(t->left);
}

BinaryNode * BinarySearchTree::findMax(BinaryNode *t) const
{
	if (t != nullptr)
		while (t->right != nullptr)
			t = t->right;
	return t;
}

bool BinarySearchTree::contains(const int & x, BinaryNode *t) const
{
	if (t == nullptr)
		return false;
	else if (x < t->element)
		return contains(x, t->left);
	else if (t->element < x)
		return contains(x, t->right);
	else
		return true;    // Match
}

void BinarySearchTree::makeEmpty(BinaryNode * & t)
{
	if (t != nullptr)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}


void BinarySearchTree::printTree(BinaryNode *t) const
{
	if (t != nullptr)
	{
		printTree(t->left);
		cout << t->element << endl;
		printTree(t->right);
	}
}

BinaryNode * BinarySearchTree::clone(BinaryNode *t) const
{
	if (t == nullptr)
		return nullptr;
	else
		return new BinaryNode{ t->element, clone(t->left), clone(t->right) };
}