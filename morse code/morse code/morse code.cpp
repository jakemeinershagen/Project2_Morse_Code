/*
Jacob Meinershagen
10/31/19
Morse Code Encoder / Decoder
*/

#include <iostream>
#include "Tree.h"
using namespace std;


int main()
{
	Tree t;
	t.BuildTree();
	cout << t.root.val;

}
