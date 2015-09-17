#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <fstream>

const int MAXK = 100; //Максимальный размер головоломки

/*!
* Вводить головоломку из файла input.txt
* \param[out] k - размер головоломку
* \param[out] tableSudoku[MAXK][MAXK] - массив сохнраняет головоломку
*/
void InputMatrixSudoku(int &k, int tableSudoku[MAXK][MAXK]);

/*!
* Выводить головоломку на файл output.txt
* \param[in] k - размер головоломку
* \param[in] tableSudoku[MAXK][MAXK] - массив сохнраняет головоломку
*/
void OutputMatrixSudoku(int k, int tableSudoku[MAXK][MAXK]);


/*!
* Выводить сообщение о неправильной головоломке на файл output.txt
* \param[in] k - размер головоломку
* \param[in] tableSudoku[MAXK][MAXK] - массив сохнраняет головоломку
*/
void OuputErrorSudoku(int k);


/*!
* Оброботать рекурсию для того чтобы заполнить головоломку
* \param[in] k - размер головоломку
* \param[in] tableSudoku[MAXK][MAXK] - массив сохнраняет головоломку
* \param[in] i,j - текущая позиция у незаполненной клетки, которой надо рассматривать
* \return true - головоломка решила 
* \return false -головоломка не решила
*/
bool recusionSudoku(int k, int tableSudoku[MAXK][MAXK], int i, int j);