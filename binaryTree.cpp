#include <iostream>
#include <cstring>
#include <string>
#include <unordered_map>
#include "binaryTree.h"

using namespace std;

BinaryTree :: BinaryTree()
{
	root = NULL;
}

BinaryTree :: BinaryTree(Element _element)
{
	root = new Node(_element);
	root->leftTree = NULL;
	root->rightTree = NULL;
}

BinaryTree :: BinaryTree(BinaryTree const& binaryTree)
{
	copy(root, binaryTree.root);
}

BinaryTree& BinaryTree :: operator = (BinaryTree const& binaryTree)
{
	if(this != &binaryTree)
	{
		destroy(root);
		copy(root, binaryTree.root);
	}
	return *this;
}

BinaryTree :: ~BinaryTree()
{
	destroy(root);
}

void BinaryTree :: copy(Node*& node1, Node* const node2)
{
	node1 = NULL;
	if(node2)
	{
		node1 = new Node;
		node1->element = node2->element;
		copy(node1->leftTree, node2->leftTree);
		copy(node1->rightTree, node2->rightTree);
	}
}

void BinaryTree :: destroy(Node* node)
{
	if (node != NULL)
	{
			destroy(node->leftTree);
			destroy(node->rightTree);
			delete node;
			node = NULL;
	}
}

void BinaryTree :: create(int _count, char _letter, BinaryTree const& leftTree, BinaryTree const& rightTree)
{
	if(root)
	{
		destroy(root);
	}
	Element element(_count, _letter);
	root = new Node;
	root->element = element;
	copy(root->rightTree, rightTree.root);
	copy(root->leftTree, leftTree.root);
}

Node* BinaryTree :: getRoot() const
{
	return root;
}

int BinaryTree :: rootValue() const
{
	return root->element.count;
}

void BinaryTree :: setRoot(Element el)
{
	root->element = el;
}

bool BinaryTree :: emptyTree() const
{
	return root == NULL;
}

bool BinaryTree :: isLeaf() const
{
	return !(emptyTree()) && root->leftTree == NULL && root->rightTree == NULL;
}

ostream& operator << (ostream& os, BinaryTree const& binaryTree)
{
	binaryTree.print(os, binaryTree.getRoot());
	return os;
}

ostream& BinaryTree :: print(ostream& os, const Node* node) const
{
	if(node)
	{
		os << "(" ;
		os << node->element.count << ",";
		print(os, node->leftTree);
		os << ",";
		print(os, node->rightTree);
		os << ")";
	}
	else 
	{
		os << " "; 
	}
	return os;
}


