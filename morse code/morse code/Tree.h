#pragma once
#include <string>
using namespace std;

struct node {
	char val;
	node* left = nullptr;
	node* right = nullptr;
};

class Tree {
public:
	struct node root;

	void BuildTree();

	string Decode(string code);
};