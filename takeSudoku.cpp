#include <iostream>
#include "library.h"

using std::cout;
using std::endl;
using std::cin;

void takeSudoku( int sudoku[][9], int pos[][9] ){
	int row, column;
	int i, j;
	bool allFilled;
	int size;
	int number;
	char choice;
	do{
		takeNumber:
		allFilled = true;
		cout << "Enter which row and which column you want to place new element in: ";
		cin >> row >> column;
		size = sizeof( pos[row - 1] ) / sizeof( pos[row - 1][column - 1] );
		j = 0;
		while( j < size ){
			if( column - 1 == pos[row - 1][j] ){
				cout << "You cannot change this element!" << endl;
				goto takeNumber;
			}
			j++;
		}
		cout << "Enter the element for row " << row << " and column " << column << " : ";
		cin >> number;
		if( number >= 1 && number <= 9){
			sudoku[row - 1][column - 1] = number;
		} else{
			cout << "Invalid element has been entered!" << endl;
			goto takeNumber; 
		}
		for( i = 0; i < 9; i++ ){
			for( j = 0; j < 9; j++ ){
				if( sudoku[i][j] == 0 ){
					allFilled = false;
					goto end;
				}
			}
		}
		end:
		cout << "Do you want to display( 'Y' for Yes and 'N' for No ): ";
		cin >> choice;
		if( choice == 'Y' ){
			display( sudoku );
		}
	} while( !allFilled );
}
