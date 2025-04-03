#ifndef MATRIX_OPERATIONS_H // prevent multiple inclusions of the header
#define MATRIX_OPERATIONS_H

#include <vector> // include required library
#include <string> // include required library

// function to read matrix data from a file
bool readMatrixFromFile(const std::string &filename, int &N, 
                        std::vector<std::vector<int>> &matrixA, 
                        std::vector<std::vector<int>> &matrixB);

// function of printing matrix                        
void printMatrix(const std::vector<std::vector<int>> &matrix);

// function to add
std::vector<std::vector<int>> addMatrices(const std::vector<std::vector<int>> &A, 
                                          const std::vector<std::vector<int>> &B);
// function of multiplication
std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>> &A, 
                                               const std::vector<std::vector<int>> &B);
// function of calculating the sum of Diagonals
int sumDiagonals(const std::vector<std::vector<int>> &matrix);

// function to swap rows
void swapRows(std::vector<std::vector<int>> &matrix, int row1, int row2);

// function to swap columns
void swapColumns(std::vector<std::vector<int>> &matrix, int col1, int col2);

// function to update matrix
void updateMatrix(std::vector<std::vector<int>> &matrix, int row, int col, int newValue);

#endif
