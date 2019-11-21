/*
Jacob Meinershagen
10/31/19
Morse Code Encoder / Decoder
*/

#include <iostream>
#include "Tree.h"
#include <map>
using namespace std;

void encode(string word) {
	map< char, string> c2d = {
		{' a',"._"},{'b',"_..."},{'c',"_._."},{'d',"_.."},{'e',"."},{'f',".._."},{'g',"__."},{'h',"...."},
	{'i',".."},{'j',".___"},{'k', "_._"},{'l',"._.."},{'m',"__"},{'n',"_."},{'o',"___"},{'p',".__."},{'q',"__._"},{'r',"._."},
	{'s',"..."},{'t',"_"},{'u',".._"},{'v',"..._"},{'w',".__"},{'x',"_.._"},{'y',"_.__"},{'z',"__.."}

	};



	for (int i = 0; i < word.length(); i++) {
		cout << c2d.find(word[i])->second << "  ";
	}
	cout << endl;
}

int main()
{
	Tree t;
	t.BuildTree();

	cout << t.Decode(".___ ._ _._ .") << endl;
	cout << t.Decode(".... . ._.. ._.. ___") << endl;
	cout << t.Decode("__ ___ ._. ... . _._. ___ _.. .") << endl;
}
