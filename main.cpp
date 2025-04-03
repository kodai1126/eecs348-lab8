#include <iostream> // include required library
#include <fstream> // include required library
#include "matrix_operations.h" // include custom header

// main function
int main() {
    std::string filename; // variable to store file name
    std::cout << "Enter the input file name: "; // ask user to input file name
    std::cin >> filename; // read user input

    std::vector<std::vector<int>> matrixA, matrixB; //declare matrixA and matrixB
    int N; // variable to store the size of matrix
    
    // call function. if successfully reading file, no error, else error
    if (!readMatrixFromFile(filename, N, matrixA, matrixB)) {
        std::cerr << "Error reading file!" << std::endl; // error message
        return 1;
    }

    std::cout << "Matrix A:\n"; // print matrixA
    printMatrix(matrixA);
    std::cout << "Matrix B:\n"; // print matrixB
    printMatrix(matrixB);

    std::cout << "Matrix A + Matrix B:\n"; // addition
    printMatrix(addMatrices(matrixA, matrixB)); // matrix addition

    std::cout << "Matrix A * Matrix B:\n"; //multiplication
    printMatrix(multiplyMatrices(matrixA, matrixB)); // matrix multiplication

    std::cout << "Sum of diagonals in Matrix A: " << sumDiagonals(matrixA) << std::endl; // calculate the sum of the diagonals

    int row1, row2; // variable to store tow indices for swapping
    std::cout << "Enter two rows to swap (0-based index): "; // ask user to input  two rows to swap
    std::cin >> row1 >> row2; // store the input
    swapRows(matrixA, row1, row2); // swap rows
    printMatrix(matrixA); // print updated matrix

    int col1, col2; // variables to store column indices for swapping
    std::cout << "Enter two columns to swap (0-based index): "; // ask user to input two columns to swap
    std::cin >> col1 >> col2; // store the input
    swapColumns(matrixA, col1, col2); // update matrix
    printMatrix(matrixA); // print matrix

    int row, col, newValue; // Variables for updating a matrix
    std::cout << "Enter row, column, and new value to update: "; // ask user to input row, column, and new value
    std::cin >> row >> col >> newValue; // store the inputs
    updateMatrix(matrixA, row, col, newValue); // update the matrix
    printMatrix(matrixA); //print the matrix

    return 0; //return
}
