#include<iostream>
#include <algorithm>
#include <vector>


/**
 * @brief Rotate an N x N matrix clockwise by 90 degrees.
 *
 * This function takes a double pointer and an integer N as input and rotates an N x N matrix clockwise by 90 degrees.
 *
 * @param matrix A double pointer to the matrix to rotate.
 * @param N An integer specifying the size of the matrix.
 */
void rotate1(int **matrix, int N) {
    // Transpose matrix
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each row
    for (int i = 0; i < N; ++i) {
        std::reverse(matrix[i], matrix[i] + N);
    }
}


/**
 * @brief Print an N x N matrix to the console.
 *
 * This function takes a double pointer and an integer N as input and prints an N x N matrix to the console.
 *
 * @param matrix A double pointer to the matrix to print.
 * @param N An integer specifying the size of the matrix.
 */
void printMatrix(int **matrix, int N) {
    // Loop over each row of the matrix
    for (int i = 0; i < N; ++i) {
        // Loop over each column of the matrix
        for (int j = 0; j < N; ++j) {
            // Print the current element followed by a space
            std::cout << matrix[i][j] << " ";
        }
        // Move to the next line after printing all elements of a row
        std::cout << std::endl;
    }
}




/**
 * @brief Print an N x N matrix to the console.
 *
 * This function takes a double pointer and an integer N as input and prints an N x N matrix to the console.
 *
 * @param matrix A double pointer to the matrix to print.
 * @param N An integer specifying the size of the matrix.
 */
void printMatrix(int **matrix, int N) {
    // Loop over each row of the matrix
    for (int i = 0; i < N; i++) {
        // Loop over each column of the matrix
        for (int j = 0; j < N; j++) {
            // Print the current element followed by a space
            std::cout << matrix[i][j] << " ";
        }
        // Move to the next line after printing all elements of a row
        std::cout << std::endl;
    }
}


int main() {
    int N;
    std::cout << "Enter N for NxN matrix: ";
    std::cin >> N;

    // dynamically allocate memory for the matrix
    int **matrix = new int*[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }

    // read in the elements of the matrix from standard input
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> matrix[i][j];
        }
    }

    // rotate the matrix by 90 degrees clockwise and print the result
    std::cout << "Rotated matrix by 90 (clockwise):\n";
    rotate1(matrix, N);
    printMatrix(matrix, N);

    // free memory allocated for the matrix
    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
