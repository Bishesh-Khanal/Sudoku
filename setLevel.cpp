#include <iostream>

using std::cout;
using std::cin;

char setLevel(){
	char level;
	cout << "Set the level of difficulty( 'E' for Easy, 'M' for Medium, 'H' for Hard ): ";
	cin >> level;
	return level;
}
