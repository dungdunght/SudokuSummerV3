#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;
const int MAXK=100;
void InputMatrixSudoku(int &k, int tableSudoku[MAXK][MAXK]);
void OutputMatrixSudoku(int k, int tableSudoku[MAXK][MAXK]);
bool recusionSudoku(int k, int tableSudoku[MAXK][MAXK], int i, int j);



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

void InputMatrixSudoku(int &k, int tableSudoku[MAXK][MAXK])
{
	ifstream fileSudoku;
	fileSudoku.open("input.txt");
	fileSudoku >> k;

	int n=k*k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			fileSudoku >> tableSudoku[i][j];
	fileSudoku.close(); 
}
void OutputMatrixSudoku(int k, int tableSudoku[MAXK][MAXK])
{
	ofstream fileSudoku;
	fileSudoku.open("ouput.txt");

	int n = k*k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			fileSudoku << tableSudoku[i][j] << " ";
		fileSudoku << endl;
	}
	fileSudoku.close();

}
bool recusionSudoku(int k, int tableSudoku[MAXK][MAXK], int i, int j)
{
	int i1, j1;
	int s;

	int n = k*k;

	bool checkNumber = true;
	
	for (s = 1; s <= n; s++)
	{
		checkNumber = true;
		for (j1 = 1; j1 <= n; j1++)
		{
			if (tableSudoku[i][j1] == s)checkNumber = false;

		}
		for (i1 = 1; i1 <= n && checkNumber; i1++)
		{
			if (tableSudoku[i1][j] == s) checkNumber = false;
		}


		if (checkNumber)
		{
			bool checkNumberSmallSquare = true;

			if (i % k == 0) i1 = i - k+1;
			else
				i1 = (i / k) * k + 1;
			if (j % k == 0) j1 = j - k+1;
			else
				j1 = (j / k) * k + 1;
			
			for (int i2 = i1; i2 <= i1+k-1&&checkNumberSmallSquare; i2++)
				for (int j2 = j1; j2 <= j1+k-1&&checkNumberSmallSquare; j2++)
					if (tableSudoku[i2][j2] == s)
								checkNumberSmallSquare = false;


		
			
			if (checkNumberSmallSquare)
			{
				bool checkNone = true;

				tableSudoku[i][j] = s;
				i1 = i; j1 = j;
				while (i1 <= n&&checkNone)
				{
					while (j1 <= n&&checkNone)
					{
						if (tableSudoku[i1][j1] == 0)
						{
							checkNone = false;
							if (recusionSudoku(k,tableSudoku, i1, j1)) return true;
						}
						j1++;
					}
					j1 = 1;
					i1++; 
				}
				


				if (checkNone)

				{
					cout << "ascasc";
					OutputMatrixSudoku(k, tableSudoku);
					return true;
				}
				tableSudoku[i][j] = 0;
			}
		}	
	}

	return false;
}