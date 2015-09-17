#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <fstream>

const int MAXK = 100;
void InputMatrixSudoku(int &k, int tableSudoku[MAXK][MAXK]);
void OutputMatrixSudoku(int k, int tableSudoku[MAXK][MAXK]);
bool recusionSudoku(int k, int tableSudoku[MAXK][MAXK], int i, int j);