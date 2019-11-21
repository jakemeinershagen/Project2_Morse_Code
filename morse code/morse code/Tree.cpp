#include "Tree.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


//. will be right _ will  be left

void Tree::BuildTree()
{
	//set root node value to an arbitrary value
	root.val = '#';

	//open file of codes
	ifstream infile;
	infile.open("morse.txt");
	if (infile.fail()) {
		cout << "Could not open input file";
	}

	string line;
	//loop through all of the letter-code pairs
	while (!infile.eof()) {
		//take codes line by line
		infile >> line;
		//split them
		char letter = line[0];
		string code = line.substr(1);

		//start at the root
		node* currentNode = &root;

		for (int i = 0; i < code.size(); i++) {
			if (code[i] == '_') {
				//if there is no node create one and move to it
				if (currentNode->right == nullptr) {
					currentNode->right = new node();
					currentNode = currentNode->right;
					currentNode->val = '-';
				}
				//if there is a node move to it
				else {
					currentNode = currentNode->right;
				}
			}
			else if(code[i] == '.') {
				//if there is no node create one and move to it
				if (currentNode->left == nullptr) {
					currentNode->left = new node();
					currentNode = currentNode->left;
					currentNode->val = '-';
				}
				//if there is a node move to it
				else {
					currentNode = currentNode->left;
				}
			}
			//if you have moved through the whole code put the letter in that spots value
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

