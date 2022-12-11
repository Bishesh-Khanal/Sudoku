//PROGRAM TO CHECK WHETHER THE SUDOKU HAS BEEN COMPLETED OR NOT AND IF NOT; GIVE THE POSITIONS OF THE ERRORS
#include <iostream>

using std::cout;
using std::endl;	

void checkSudoku( int sudoku[][9], int pos[][9],  bool isTranspose ){
	cout << endl;
	int i, j, k;
	int pla[9];
	
	for( i = 0; i < 9; i++){
		for( j = 0; j < 9; j++ ){
			pla[j] = 0;
		}

		for( j = 0; j < 9; j++ ){
			pos[sudoku[i][j] - 1][pla[sudoku[i][j] - 1]] = j;
			pla[sudoku[i][j] - 1]++;
		}

		for( j = 0; j < 9; j++ ){
			if( pla[j] > 1 ){
				if( !isTranspose ){
					cout << "Same element in row : "<< i + 1 <<" ; column : ";
				} else{
					cout << "Same element in column : "<< i + 1 <<" ; row : "; 
				}
				for( k = 0; k < pla[j]; k++ ){
					cout << pos[j][k] + 1 << " ";
				}
				cout << endl;
			}
		}
	}
}
