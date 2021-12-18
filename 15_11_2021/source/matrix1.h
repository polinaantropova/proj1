#pragma once
void printArray(int** A, int row, int column);
void fillarrRandom(int** A, int row, int column);
int** createArray(int row, int column);
void deleteArray(int** A, int row, int column);
void initArrayOnlyConst(int** A, int row, int column, int yr_const);
int** eMatrix(int** A, int row, int column);
int** transMatrix(int** A, int row, int column);
int** return180Array(int** A, int row, int column);
int** productMatrix(int** A, int row, int column, int number);
int** CreateProductMatrix(int** A, int row, int column, int number);
int** sumMatrix(int** A, int** B, int row, int column);
int** multMatrix(int** A, int row1, int column1, int** B, int row2, int column2);
int** swapRows(int** A, int row, int column, int rowFirst, int rowSec);
void swapColumns(int** A, int row, int column, int colFirst, int colSec);
int& getElement(int** A, int yourRow, int yourColumn);