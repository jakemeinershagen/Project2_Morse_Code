#include "Tree.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


//. will be right _ will  be left

void Tree::BuildTree()
{
	root.val = '#';
	ifstream infile;
	infile.open("morse.txt");
	if (infile.fail()) {
		cout << "Could not open input file";
	}

	string line;
	while (!infile.eof()) {
		infile >> line;
		char letter = line[0];
		string code = line.substr(1);
		node* currentNode = &root;

		for (int i = 0; i < code.size(); i++) {
			if (code[i] == '_') {
				//if there is no node create one
				if (currentNode->right == nullptr) {
					currentNode->right = new node();
					currentNode = currentNode->right;
					currentNode->val = '-';
				}
				else {
					currentNode = currentNode->right;
				}
			}
			else if(code[i] == '.') {
				//if there is no node create one
				if (currentNode->left == nullptr) {
					currentNode->left = new node();
					currentNode = currentNode->left;
					currentNode->val = '-';
				}
				else {
					currentNode = currentNode->left;
				}
			}
			if (i == code.size() - 1) {
				currentNode->val = letter;
			}
		}
	}

	//cout << "Tree Built" << endl;
	infile.close();
}

string Tree::Decode(string code)
{
	node* currentNode = &root;
	string result = "";
	for (int i = 0; i < code.size(); i++) {
		if (code[i] == '.') {
			currentNode = currentNode->left;
		}
		else if (code[i] == '_') {
			currentNode = currentNode->right;
		}
		else if (code[i] == ' ') {
			result += currentNode->val;
			currentNode = &root;
		}
	}
	result += currentNode->val;
	return result;
}

