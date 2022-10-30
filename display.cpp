#include <iostream>

using std::cout;
using std::endl;

void display( int sudoku[][9] ){
	for( int i = 0; i < 9 ; i++ ){
		for( int j = 0; j < 9; j++ ){
			if( sudoku[i][j] == 0 ){
				cout << "_" << " ";
			} else{
				cout << sudoku[i][j] << " ";
			}
		}
		cout << endl;
	}
}
