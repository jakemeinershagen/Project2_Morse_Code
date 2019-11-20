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

	cout << t.Decode(".___ ._ _._ .") << endl;
	cout << t.Decode(".... . ._.. ._.. ___") << endl;
	cout << t.Decode("__ ___ ._. ... . _._. ___ _.. .") << endl;
}
