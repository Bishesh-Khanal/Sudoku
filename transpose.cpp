void transpose( int sudoku[][9] ){
	for( int i = 0; i < 9 ; i++ ){
		for( int j = i; j < 9; j++ ){
			int temp = sudoku[i][j];
			sudoku[i][j] = sudoku[j][i];
			sudoku[j][i] = temp;
		}
	}
}

