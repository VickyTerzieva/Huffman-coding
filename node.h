#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

struct Element 
{
	int count;
	char letter;
	Element(int = 0, char = 0); 
};

struct Node
{
	Element element;
	Node* rightTree;
	Node* leftTree;
	Node(Element = Element(), Node* _rightTree = NULL, Node* _leftTree = NULL);
	bool isLeaf(); 
};

#endif