#include <iostream>
#include "library.h"

using namespace std;

int main(){
	int sudoku[9][9];
	int pos[9][9];

	char level = setLevel();
	
	switch( level ){
		case 'E': case 'M': case 'H':
			setSudoku( sudoku, pos, level );
			display( sudoku );
			takeSudoku( sudoku, pos );
			display( sudoku );
			checkSudoku( sudoku, pos, false );
			transpose( sudoku );
			checkSudoku( sudoku, pos, true );
			transpose( sudoku );
			display( sudoku );
		break;
		default:
			cout << "Invalid difficulty level" << endl;
		break;
	}

	cout << endl;

	return 0;
}
