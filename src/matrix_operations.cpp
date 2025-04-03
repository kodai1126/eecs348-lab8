#include "matrix_operations.h" // include the custom header
#include <iostream> // include required library
#include <fstream> // include required library
#include <iomanip> // include required library

// function to read matrix from file
bool readMatrixFromFile(const std::string &filename, int &N, 
                        std::vector<std::vector<int>> &matrixA, 
                        std::vector<std::vector<int>> &matrixB) {
    std::ifstream file(filename); // open the file
    if (!file) return false; // return false if file opening fails
    
    file >> N; // read the matrix size N
    matrixA.resize(N, std::vector<int>(N)); // Resize the matrixA
    matrixB.resize(N, std::vector<int>(N)); // Resize the matrixB

    // Read value from matrix A
    for (int i = 0; i < N; ++i) // column
        for (int j = 0; j < N; ++j) // row
            file >> matrixA[i][j];

    // read value from matrix B
    for (int i = 0; i < N; ++i) // column 
        for (int j = 0; j < N; ++j) // row
            file >> matrixB[i][j];

    return true;
}

// function to pring a matrix
void printMatrix(const std::vector<std::vector<int>> &matrix) {
    for (const auto &row : matrix) { // row
        for (int val : row) // each element in row
            std::cout << std::setw(4) << val;
        std::cout << std::endl;
    }
}

// function to add two matrices
std::vector<std::vector<int>> addMatrices(const std::vector<std::vector<int>> &A, 
                                          const std::vector<std::vector<int>> &B) {
    int N = A.size(); //get matrix size
    std::vector<std::vector<int>> result(N, std::vector<int>(N));

    // perform element-wise addition
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i][j] = A[i][j] + B[i][j];

    return result;
}

//function to multiply matrices
std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>> &A, 
                                               const std::vector<std::vector<int>> &B) {
    int N = A.size(); // variable to store the size
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));
    
    // do multiplication
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                result[i][j] += A[i][k] * B[k][j];

    return result;
}

// function of sum of diagonals
int sumDiagonals(const std::vector<std::vector<int>> &matrix) {
    int N = matrix.size(), sum = 0;

    // add the diagonals number
    for (int i = 0; i < N; ++i) {
        sum += matrix[i][i];              
        if (i != N - i - 1)               
            sum += matrix[i][N - i - 1];  
    }

    return sum;
}

//function of swapping rows
void swapRows(std::vector<std::vector<int>> &matrix, int row1, int row2) {
    if (row1 >= 0 && row1 < matrix.size() && row2 >= 0 && row2 < matrix.size())
        std::swap(matrix[row1], matrix[row2]); //swap
}

// function of swapping columns
void swapColumns(std::vector<std::vector<int>> &matrix, int col1, int col2) {
    int N = matrix.size();
    if (col1 >= 0 && col1 < N && col2 >= 0 && col2 < N) {
        for (int i = 0; i < N; ++i)
            std::swap(matrix[i][col1], matrix[i][col2]); // swap
    }
}

// function of updaing matrix
void updateMatrix(std::vector<std::vector<int>> &matrix, int row, int col, int newValue) {
    if (row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size())
        matrix[row][col] = newValue; // change to new values
}
