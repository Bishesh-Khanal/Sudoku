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
			switch( sudoku[i][j] ){
				case 1:
					pos[0][pla[0]] = j;
					pla[0]++;
				break;
				case 2:
					pos[1][pla[1]] = j;
					pla[1]++;
				break;
				case 3:
					pos[2][pla[2]] = j;
					pla[2]++;
				break;
				case 4:
					pos[3][pla[3]] = j;
					pla[3]++;
				break;
				case 5:
					pos[4][pla[4]] = j;
					pla[4]++;
				break;
				case 6:
					pos[5][pla[5]] = j;
					pla[5]++;
				break;
				case 7:
					pos[6][pla[6]] = j;
					pla[6]++;
				break;
				case 8:
					pos[7][pla[7]] = j;
					pla[7]++;
				break;
				case 9:
					pos[8][pla[8]] = j;
					pla[8]++;
				break;
			}
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
