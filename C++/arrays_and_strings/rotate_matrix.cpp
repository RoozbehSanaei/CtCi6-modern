/*
 * Cracking the coding interview edition 6
 * Problem 1.7 Rotate a matrix by 90' clockwise ( or anticlockwise).
 * Solution : I have done it two ways.
 * Approach 1: Take transpose of matrix and then reverse the rows for clockwise 90' rotation.
 * 			   Obviously if we reverse the columns we will get anticlockwise 90' rotation.
 * Approach 2: As mentioned in the book, rotating invididual elements layer by layer.
 * 			   I have solved it perform anticlockwise 90' rotation, it can be done similarly for clockwise rotatation.
 */
#include<iostream>
#include <algorithm>
#include <vector>


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


// This function prints the contents of a 2D matrix in tabular format
// The matrix is of size N x N, where N is the input parameter
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

#include <iostream>

// function to rotate the matrix by 90 degrees clockwise
void rotate1(int **matrix, int N) {
    // TODO: implementation of matrix rotation
}

// function to print the matrix
void printMatrix(int **matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
#include <iostream>

// function to rotate the matrix by 90 degrees clockwise
void rotate1(int **matrix, int N) {
    // TODO: implementation of matrix rotation
}

// function to print the matrix
void printMatrix(int **matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[i][j] << " ";
        }
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
