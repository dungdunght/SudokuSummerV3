/*!
* Искусственный интеллект для обобщенной игры «Судоку»
*/

#include "sudoku.h"

int main()
{
	int tableSudoku[MAXK][MAXK];  //массив сохраняет головоломку
	int k=0;  //размер головоломки

	
	int i, j;
	int i1=0, j1=0;

	InputMatrixSudoku(k, tableSudoku);   //вводить головоломку
	
	int n = k*k;

	bool checkSudoku=false;  //флаг омечает успеть ли наитй решение для игры "Судоку"
	
	//Найти незаполненную клетку чтобы начинать рекурсию
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			if (tableSudoku[i][j] == 0)
			{
				checkSudoku=recusionSudoku(k,tableSudoku, i, j);
			}

	}

	//Выводить сообщение о неправилной головоломке 
	if (!checkSudoku)
		OuputErrorSudoku(k);

}

