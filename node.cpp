#include <iostream>
#include "node.h"

using namespace std;

Element :: Element(int _count, char _letter) 
{
	count = _count;
	letter = _letter;
}

Node :: Node(Element _element, Node* _rightTree, Node* _leftTree)
{
		element = _element;
		rightTree = _rightTree;
		leftTree = _leftTree;
}

bool Node :: isLeaf()
{
	return rightTree == NULL && leftTree == NULL;
}