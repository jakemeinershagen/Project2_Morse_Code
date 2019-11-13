#include "Tree.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


void Tree::BuildTree()
{
	root.val = '#';
	ifstream infile;
	infile.open("morse.txt");
	if (infile.fail()) {
		cout << "Could not open input file";
	}

	string line;
	infile >> line;
	cout << line;
	infile >> line;
	cout << line;


	infile.close();
}
