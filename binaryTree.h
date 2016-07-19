#ifndef BINARYTREE2_H
#define BINARYTREE2_H

#include "node.h"
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class BinaryTree
{
	Node* root;
public:
	BinaryTree();
	BinaryTree(Element);
	BinaryTree(BinaryTree const&);
	BinaryTree& operator = (BinaryTree const&);
	~BinaryTree();
	void create(int, char, BinaryTree const&, BinaryTree const&);
	Node* getRoot() const; 
	int rootValue() const; 
	void setRoot(Element); 
	bool emptyTree() const;
	bool isLeaf() const;
	friend ostream& operator << (ostream&, BinaryTree const&);
private:
	void copy(Node*&, Node* const);
	void destroy(Node*);
	ostream& print(ostream&, const Node*) const;
};
#endif