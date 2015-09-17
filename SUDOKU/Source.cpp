#include "sudoku.h"

int main()
{
	int tableSudoku[MAXK][MAXK];
	int k=0;

	
	int i, j;
	int i1=0, j1=0;

	InputMatrixSudoku(k, tableSudoku);
	
	int n = k*k;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			if (tableSudoku[i][j] == 0)
			{
				recusionSudoku(k,tableSudoku, i, j);
			}

	}

}

