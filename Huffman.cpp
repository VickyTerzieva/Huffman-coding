#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <sstream>
#include <cmath>
#include "Huffman.h"
#include "binaryTree.h"

using namespace std;

Huffman :: Huffman() : bt(), mapLetterCode(), mapLetterOccurence(), codedWord() {}

unordered_map<char,int>& Huffman :: makeMapFromString(string word) 
{
	for(int i = 0; i < word.size(); i++)
	{
		if(mapLetterOccurence[word[i]])
		{
			mapLetterOccurence[word[i]]++;
		}
		else
		{
			mapLetterOccurence[word[i]] = 1;
		}
	}
	return mapLetterOccurence;
}

list<BinaryTree> Huffman :: makeListFromMap()  
{
	list<BinaryTree> l;
	unordered_map<char, int>::iterator it;
	for(it = mapLetterOccurence.begin(); it != mapLetterOccurence.end(); it++)
	{
		Element el(it->second, it->first);
		BinaryTree temp(el);
		l.push_back(temp);
	}
	return l;
}

list<BinaryTree>::iterator Huffman :: findMinInList(list<BinaryTree>& listOfTrees) 
{
	list<BinaryTree>::iterator it, it2 = listOfTrees.begin();
	int min = it2->rootValue();
	for(it = listOfTrees.begin(); it != listOfTrees.end(); it++)
	{
		if(it->rootValue() < min)
		{
			it2 = it;
			min = it->rootValue();
		}
	}
	return it2;
}

BinaryTree& Huffman :: makeTreeFromWord(string word) 
{
	makeMapFromString(word);
	list<BinaryTree> l = makeListFromMap();
	while(l.size() > 1) 
	{
		BinaryTree bt1, bt2, b3;
		bt1 = *findMinInList(l);
		l.erase(findMinInList(l));
		bt2 = *findMinInList(l);
		l.erase(findMinInList(l));
		b3.create(bt1.rootValue()+bt2.rootValue(), '\0', bt1, bt2); 
		l.push_back(b3);
	}
	if(l.size() > 0)
	{
		bt = l.front();
	}
	return bt;
}
	
unordered_map<char, string>& Huffman :: makeTableWithLettersCodes(string code, Node* node) 
{
	if(node == NULL)
	{
		return mapLetterCode;
	}
	if (node->isLeaf())
	{
		if(code.compare("") == 0) 
		{
			code = "0";
			Element el(node->element.count, node->element.letter);
			bt.setRoot(el);
		}
		mapLetterCode[node->element.letter] = code;
		cout << "Letter: " << node->element.letter << ", occurences: " << node->element.count <<  ", code: " << code << endl;
	}
	else
	{
		makeTableWithLettersCodes(code + "0", node->leftTree);
		makeTableWithLettersCodes(code + "1", node->rightTree);
	}
	if(code.size() > 0)
	{
		code.pop_back();
	}
	return mapLetterCode;
}

string Huffman :: encode(string word)
{
	makeTreeFromWord(word);
	makeTableWithLettersCodes(codedWord, bt.getRoot());
	cout << endl;
	for(int i = 0; i < word.size(); i++)
	{
		codedWord = codedWord + mapLetterCode[word[i]];
	}
	return codedWord;
}

string Huffman :: codeToLetter(string code) 
{
	for(unordered_map<char, string>::iterator it = mapLetterCode.begin(); it != mapLetterCode.end(); it++)
	{
		if(!it->second.compare(code))
		{
			stringstream s;
			string s1;
			s << it->first;
			s >> s1;
			if(it->first == ' ')
			{
				s1 = " ";
			}
			return s1; 
			break;
		}
	}
	return "Invalid string!";
}

string Huffman :: codeToWord(string code)
{
	string word = "", tempCode = "";
	Node* it = bt.getRoot();
	if(code.size() == 0  || bt.getRoot() == NULL)
	{
		return "Nothing has been encoded!";
	} 
	if(bt.isLeaf()) 
	{ 
		while(code.size() > 0)
		{
			tempCode += code.front();
			word += codeToLetter(tempCode);
			tempCode.clear();
			code.erase(0,1);
		}
		if(word.find("Invalid string!") != '\0') 
		{
			return "Invalid string!";
		}
		return word;
	}
	while(code.size() > 0)
	{
		if(it->isLeaf()) 
		{
			word += codeToLetter(tempCode);
			tempCode.clear();
			it = bt.getRoot(); 
		}
		else if(code.front() == '0') 
		{
			tempCode += code.front(); 
			it = it->leftTree;
			code.erase(0, 1);
		}
		else 
		{
			tempCode += code.front(); 
			it = it->rightTree;
			code.erase(0, 1);
		}
	}
	string result = codeToLetter(tempCode);
	if(result.compare("Invalid string!") == 0) 
	{
		word = result; 
	}
	else
	{
		word += result;
	}
	return word;
}

string Huffman :: decode(string code)
{
	string word;
	if(code.size() > 0)
	{
		word = codeToWord(code);
	}
	else
	{
		word = codeToWord(codedWord);
	}
	return word;
}

double Huffman :: calculate(string code)
{
	string word = decode(code);
	if(word.compare("Invalid string!") == 0 || word.compare("Nothing has been encoded!") == 0 || code.size() == 0)
	{
		cout << "No compression has been made!" << endl;
		return 0;
	}
	return code.size()*100.0 / (word.size()*8);
}

double Huffman :: calculateCompression(string code)
{
	double compression;
	if(code.size() == 0)
	{
		compression = calculate(codedWord);
	}
	else
	{
		compression = calculate(code);
	}
	return compression;
}

string Huffman :: convertCodeIntoDecimalNumbers(string code)
{
	string result;
	if(code.size() > 0)
	{
		result = conversion(code);
	}
	else
	{
		result = conversion(codedWord);
	}
	return result;
}

string Huffman :: conversion(string code)
{
	string numbers = ""; 
	string temp = "";
	if(code.size() == 0 || decode(code).compare("Invalid string!") == 0 || decode(code).compare("Nothing has been encoded!") == 0)
	{
		return "Nothing has been encoded!";
	}
	while(code.size() > 0)
	{
		temp += code.front();
		code.erase(0,1);
		if(temp.size() == 8)
		{
			numbers += stringToNumber(temp);
			numbers += " ";
			temp.clear();
		}
	}
	if(temp.size() > 0)
	{
		numbers += stringToNumber(temp); 
	}
	return numbers;
}

string Huffman :: stringToNumber(string binaryNumber)
{
	string s;
	int number = 0;
	for(int i = 0; i < binaryNumber.size(); i++)
	{
		if(binaryNumber[binaryNumber.size() - (i + 1)] == '1')
		{
			number += pow(2.0, i); 
		}
	}
	stringstream str;
	str << number;
	str >> s;
	return s;
}