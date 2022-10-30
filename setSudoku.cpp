#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void setSudoku( int sudoku[][9], int pos[][9], char level ){
	int i, j, k, l, l1, l2;
	int countFilled;

	int testPositionFilled;
	int* positionFilled;

	int numberFilled; 

	srand( time( 0 ) );

	for( i = 0; i < 9; i++ ){
		for( j = 0; j < 9; j++ ){
			sudoku[i][j] = 0;
		}
	}

	for( i = 0; i < 9; i++ ){
		switch( level ){
			case 'E':
				countFilled = 0 + rand() % 7;
			break;
			case 'M':
				countFilled = 0 + rand() % 5;
			break;
			case 'H':
				countFilled = 0 + rand() % 4; 
			break;
		}
		positionFilled = new int[countFilled];
		j = 0;
		while( j < countFilled ){
			setPosition:
			testPositionFilled = 0 + rand() % 9;
			for( k = 0; k < j; k++ ){
				if( testPositionFilled == positionFilled[k] ){
					goto setPosition;
				}
			}
			pos[i][j] = testPositionFilled;
			positionFilled[j] = testPositionFilled;
			j++;
		}
		j = 0;
		while( j < countFilled ){
			setNumber:
			numberFilled = 1 + rand() % 9;
			for( k = 0; k < 9; k++ ){
				if( numberFilled == sudoku[i][k] ){
					goto setNumber;
				}
			}
			for( k = 0; k < 9; k++ ){
				if( numberFilled == sudoku[k][positionFilled[j]] ){
					goto setNumber;
				}
			}
			switch( positionFilled[j] ){
				case 0: case 3: case 6:
					l1 = positionFilled[j];
					l2 = positionFilled[j] + 2;
				break;
				case 1: case 4: case 7:
					l1 = positionFilled[j] - 1;
					l2 = positionFilled[j] + 1;
				break;
				case 2: case 5: case 8:
					l1 = positionFilled[j] - 2;
					l2 = positionFilled[j];
				break;
			}
			if( i < 3 ){
				for( k = 0; k < 3; k++ ){
					for( l = l1; l <= l2; l++ ){
						if( numberFilled == sudoku[k][l] ){
							goto setNumber;
						}
					}
				}
			} else if( i > 5 ){
				for( k = 6; k < 9; k++ ){
					for( l = l1; l <= l2; l++ ){
						if( numberFilled == sudoku[k][l] ){
							goto setNumber;
						}
					}
				}
			} else{
				for( k = 3; k < 6; k++ ){
					for( l = l1; l <= l2; l++ ){
						if( numberFilled == sudoku[k][l] ){
							goto setNumber;
						}
					}
				}
			}
			sudoku[i][positionFilled[j]] = numberFilled;
			j++;
		}
		delete[]positionFilled;
	}
	positionFilled = NULL;
}
