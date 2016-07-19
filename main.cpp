#include <iostream>
#include <string>
#include <unordered_map>
#include "node.h"
#include "binaryTree.h"
#include "Huffman.h"

using namespace std;

int main()
{
	string word;
	cout << "Input the string you would like to encode: " << endl;
	getline(cin, word);
	cout << endl;
	Huffman h, h1;
	cout << "Word encoded: " << h.encode(word) << endl;
	cout << "Word decoded: " << h.decode() << endl;
	cout << "Compressed string is " << h.calculateCompression() << "% of the original one." << endl;
	cout << "Word encoded -> decimal number : " << h.convertCodeIntoDecimalNumbers() << endl;
	cout << "**********" << endl;
	string word2 = "000000001";
	cout << word2 << " -> " << h.decode(word2) << endl;
	cout << "Compressed string is " << h.calculateCompression(word2) << "% of the original one." << endl;
	cout << "Word encoded -> decimal number : " << h.convertCodeIntoDecimalNumbers(word2) << endl;
	cout << "**********" << endl;
	word2 = "0101001011";
	cout << word2 << " -> " << h.decode(word2) << endl;
	cout << "Compressed string is " << h.calculateCompression(word2) << "% of the original one." << endl;
	cout << "Word encoded -> decimal number : " << h.convertCodeIntoDecimalNumbers(word2) << endl;
	cout << "**********" << endl;
	cout << h1.encode("") << endl;
	cout << "Compressed string is " << h1.calculateCompression() << "% of the original one." << endl;
	cout << "Word encoded -> decimal number : " << h1.convertCodeIntoDecimalNumbers() << endl;
	return 0;
}