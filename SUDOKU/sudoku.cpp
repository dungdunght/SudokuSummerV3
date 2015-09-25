#include "sudoku.h"

using namespace std;

/*!
* Вводить головоломку из файла input.txt
* \param[out] k - размер головоломку
* \param[out] tableSudoku[MAXK][MAXK] - массив сохнраняет головоломку
*/
void InputMatrixSudoku(int &k, int tableSudoku[MAXK][MAXK])
{
	ifstream fileSudoku;
	fileSudoku.open("input.txt"); 
	fileSudoku >> k;   //вводить размер головоломки

	int n = k*k;   
	//вводить полную головоломку
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			fileSudoku >> tableSudoku[i][j];
	fileSudoku.close();
}

/*!
* Проверить правильно ли головоломке "Судоку"
* \param[out] k - размер головоломку
* \param[out] tableSudoku[MAXK][MAXK] - массив сохнраняет головоломку
*/


bool checkInputSudoku(int k,int tableSudoku[MAXK][MAXK],int &i_false,int &j_false)
{
	bool checkNumber[10];
	int n = k*k;
	for (int i = 1; i <= n; i++)
	{
		for (int j1 = 1; j1 < 10; j1++) checkNumber[j1] = true;
		for (int j = 1; j <= n; j++)
		{
			if (tableSudoku[i][j] != 0)
			{
				if (!checkNumber[tableSudoku[i][j]])
				{
					i_false = i;
					j_false = j;
					return 0;
				}
				checkNumber[tableSudoku[i][j]] = false;
			}
		}
	}


	for (int j = 1; j <= n; j++)
	{
		for (int i1 = 1; i1 < 10; i1++) checkNumber[i1] = true;
		for (int i = 1; i <= n; i++)
		{
			if (tableSudoku[i][j] != 0)
			{
				if (!checkNumber[tableSudoku[i][j]])
				{
					i_false = i;
					j_false = j;
					return 0;
				}
				checkNumber[tableSudoku[i][j]] = false;
			}
		}
	}

	for (int i = 1; i <= n-k+1; i = i + 3)
	{
		for (int j = 1; j <= n-k+1; j = j + 3)
			for (int i1 = 1; i1 < 10; i1++) checkNumber[i1] = true;
			for (int i1 = i; i1 <= i + k - 1; i1++)
				for (int j1 = j; j1 <= j + k - 1;j1++)
				{

}

/*!
* Выводить головоломку на файл output.txt
* \param[in] k - размер головоломку
* \param[in] tableSudoku[MAXK][MAXK] - массив сохнраняет головоломку
*/
void OutputMatrixSudoku(int k, int tableSudoku[MAXK][MAXK])
{
	ofstream fileSudoku;
	fileSudoku.open("ouput.txt");

	int n = k*k;

	//выводить головоломку с заполненными цифрами
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			fileSudoku << tableSudoku[i][j] << " ";
		fileSudoku << endl;
	}
	fileSudoku.close();

}

/*!
* Выводить сообщение о неправилном входе данных на файл output.txt
* \param[in] i_false,j_false - первая позиция где положил неправильно число
*
*/

/*!
* Выводить сообщение о нерешающей головоломке на файл output.txt
* \param[in] k - размер головоломку
* 
*/
void OuputErrorSudoku(int k)
{
	ofstream fileSudoku;
	fileSudoku.open("ouput.txt");

	//выводить просто 1 если размер головоломки только 1 
	if (k == 1)
	{
		fileSudoku << "1";
	}
	else
	{
		//выводить сообщение если головоломке неправильно
	}

	fileSudoku.close();
}


/*!
* Оброботать рекурсию для того чтобы заполнить головоломку
* \param[in] k - размер головоломку
* \param[in] tableSudoku[MAXK][MAXK] - массив сохнраняет головоломку
* \param[in] i,j - текущая позиция у незаполненной клетки, которой надо рассматривать
* \return true - головоломка решила
* \return false -головоломка не решила
*/
bool recusionSudoku(int k, int tableSudoku[MAXK][MAXK], int i, int j)
{
	int i1, j1;
	int s;

	int n = k*k;

	bool checkNumber = true;  //флаг омечает можно ли выбиранная цифра соответственно с правилом игры

	//проверить по каждому значению от 1 до k*k в незаполнненой клетке  
	for (s = 1; s <= n; s++)
	{
		checkNumber = true;

		//проверить соответственно ли правилы игры по горизонту
		for (j1 = 1; j1 <= n; j1++)
		{
			if (tableSudoku[i][j1] == s)checkNumber = false;

		}
		//проверить соответственно ли правилы игры по вертикалу
		for (i1 = 1; i1 <= n && checkNumber; i1++)
		{
			if (tableSudoku[i1][j] == s) checkNumber = false;
		}


		if (checkNumber)
		{
			//проверить соответственно ли правилы игры по малому квадрату k×k 
			bool checkNumberSmallSquare = true;

			if (i % k == 0) i1 = i - k + 1;
			else
				i1 = (i / k) * k + 1;
			if (j % k == 0) j1 = j - k + 1;
			else
				j1 = (j / k) * k + 1;

			for (int i2 = i1; i2 <= i1 + k - 1 && checkNumberSmallSquare; i2++)
				for (int j2 = j1; j2 <= j1 + k - 1 && checkNumberSmallSquare; j2++)
					if (tableSudoku[i2][j2] == s)
						checkNumberSmallSquare = false;



			//если выбиранная цифра соответственно с правилом игры
			if (checkNumberSmallSquare)
			{
				bool checkNone = true; //флаг отмечает дошла до последней ли клетки рекурсии 

				tableSudoku[i][j] = s;  //поставить выбиранная цифра в клетку
				i1 = i; j1 = j;

				//найти другой клетку, которой надо рассматривать 
				while (i1 <= n&&checkNone)
				{
					while (j1 <= n&&checkNone)
					{
						if (tableSudoku[i1][j1] == 0)
						{
							checkNone = false;
							if (recusionSudoku(k, tableSudoku, i1, j1)) return true;  //если нашел, то продолжать рекурсию, начинал с этой клеткой
						}
						j1++;
					}
					j1 = 1;
					i1++;
				}


				//если дошла до последней клетки рекурсии, то выводить в файл, закончить рекурсию
				if (checkNone)

				{
					OutputMatrixSudoku(k, tableSudoku);
					return true;  
				} 
				tableSudoku[i][j] = 0;  //вернуть начальное значение для того чтобы продолжать выбирать цифры 
			}
		}
	}

	return false; 
}