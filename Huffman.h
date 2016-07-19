#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "binaryTree.h"

using namespace std;

class Huffman
{
	BinaryTree bt; 
	unordered_map<char, int> mapLetterOccurence; 
	unordered_map<char, string> mapLetterCode; 
	string codedWord; 
public:
	Huffman();
	string encode(string);
	string decode(string = "");
	double calculateCompression(string = "");
	string convertCodeIntoDecimalNumbers(string = "");
private:
	unordered_map<char,int>& makeMapFromString(string); 
	list<BinaryTree> makeListFromMap();
	list<BinaryTree>::iterator findMinInList(list<BinaryTree>&);
	BinaryTree& makeTreeFromWord(string); 
	unordered_map<char, string>& makeTableWithLettersCodes(string, Node*);
	string codeToLetter(string);
	string codeToWord(string);
	string conversion(string);
	double calculate(string);
	string stringToNumber(string);
};

#endif