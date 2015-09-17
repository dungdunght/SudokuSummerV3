#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;
void InputMatrixSudoku(int &n, int a[100][100]);
void OutputMatrixSudoku(int n, int a[100][100]);
bool recusionSudoku(int a[100][100], int i, int j);

int main()
{
	int a[100][100];
	int n=0;

	int i, j;
	int i1=0, j1=0;
	InputMatrixSudoku(n, a);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			if (a[i][j] == 0)
			{
				recusionSudoku(a, i, j);
			}

	}


	//OutputMatrixSudoku(n, a);
}

void InputMatrixSudoku(int &n, int a[100][100])
{
	ifstream fileSudoku;
	fileSudoku.open("input.txt");
	fileSudoku >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			fileSudoku >> a[i][j];
	fileSudoku.close(); 
}
void OutputMatrixSudoku(int n, int a[100][100])
{
	ofstream fileSudoku;
	fileSudoku.open("ouput.txt");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			fileSudoku << a[i][j]<<" ";
		fileSudoku << endl;
	}
	fileSudoku.close();

}
bool recusionSudoku(int a[100][100], int i, int j)
{
	int i1, j1;
	int k;


	bool checkNumber = true;
	
	for (k = 1; k <= 9; k++)
	{
		checkNumber = true;
		for (j1 = 1; j1 <= 9; j1++)
		{
			if (a[i][j1] == k) checkNumber = false;

		}
		for (i1 = 1; i1 <= 9 && checkNumber; i1++)
		{
			if (a[i1][j] == k) checkNumber = false;
		}


		if (checkNumber)
		{
			bool checkNumberSmallSquare = true;

			if (i % 3 == 0) i1 = i - 2;
			else
				i1 = (i / 3) * 3 + 1;
			if (j % 3 == 0) j1 = j - 2;
			else
				j1 = (j / 3) * 3 + 1;
			
			for (int i2 = i1; i2 <= i1+2&&checkNumberSmallSquare; i2++)
				for (int j2 = j1; j2 <= j1+2&&checkNumberSmallSquare; j2++)
							if (a[i2][j2] == k)
								checkNumberSmallSquare = false;


			//for (i1 = i - 2; i1 <= i&&checkNumberSmallSquare; i1++)
			//	for (j1 = j - 2; j1 <= j&&checkNumberSmallSquare; j1++)
			//		if (i1 > 0 && j1 > 0)
			//			if (i1 != i&&j1 != j)
			//				if (a[i1][j1] == k)
			//					checkNumberSmallSquare = false;

			
			if (checkNumberSmallSquare)
			{
				bool checkNone = true;

				a[i][j] = k;
				i1 = i; j1 = j;
				while (i1 <= 9&&checkNone)
				{
					while (j1 <= 9&&checkNone)
					{
						if (a[i1][j1] == 0)
						{
							checkNone = false;
							if (recusionSudoku(a, i1, j1)) return true;
						}
						j1++;
					}
					j1 = 1;
					i1++; 
				}
				

				//for (i1 = i; i1 <= 9&&checkNone; i1++)
				//	for (j1 = j; j1 <= 9&&checkNone; j1++)
				//	{
				//		if (a[i1][j1] == 0)
				//		{
				//			checkNone = false;
				//			if (recusionSudoku(a, i1, j1)) return true;
				//		}
				//	}
				if (checkNone)

				{
					cout << "ascasc";
					OutputMatrixSudoku(9, a);
					return true;
				}
				a[i][j] = 0;
			}
		}	
	}

	return false;
}