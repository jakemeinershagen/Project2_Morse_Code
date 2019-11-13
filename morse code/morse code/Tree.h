#pragma once
using namespace std;

struct node {
	char val;
	struct node* left;
	struct node* right;
};

class Tree {
public:
	struct node root;

	void BuildTree();
};