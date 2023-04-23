
#include <iostream>

/**
 * @brief Sets all elements in any row or column that contains a zero to zero.
 *
 * @param matrix A two-dimensional integer array.
 * @param M The number of rows in the matrix.
 * @param N The number of columns in the matrix.
 */
void nullifyMatrix(int **matrix, int M, int N) {
    bool firstRow = false; // Flag to indicate if the first row should be nullified.

    // Step 1: Check if the first row contains any zeros.
    for (int i = 0; i < N; ++i) {
        if (matrix[0][i] == 0) {
            firstRow = true;
            break;
        }
    }

    // Step 2: Check each row (except the first) for zeros and update the first row and the row itself accordingly.
    for (int i = 1; i < M; ++i) {
        bool nullifyThisRow = false;
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0; // Update the first row to indicate that this column should be nullified.
                nullifyThisRow = true; // Mark this row for nullification.
            }
        }
        if (nullifyThisRow) {
            nullifyRow(matrix, N, i); // Nullify this row.
        }
    }

    // Step 3: Nullify columns based on the updated first row.
    for (int j = 0; j < N; ++j) {
        if (matrix[0][j] == 0) {
            nullifyCol(matrix, M, j); // Nullify this column.
        }
    }

    // Step 4: Nullify the first row if it contained any zeros.
    if (firstRow) {
        nullifyRow(matrix, N, 0); // Nullify the first row.
    }
}

/**
 * @brief Sets all elements in a row to zero.
 *
 * @param matrix A two-dimensional integer array.
 * @param N The number of columns in the matrix.
 * @param row The row index to nullify.
 */
void nullifyRow(int **matrix, int N, int row) {
    for (int j = 0; j < N; ++j) {
        matrix[row][j] = 0; // Set each element in the row to zero.
    }
}

/**
 * @brief Sets all elements in a column to zero.
 *
 * @param matrix A two-dimensional integer array.
 * @param M The number of rows in the matrix.
 * @param col The column index to nullify.
 */
void nullifyCol(int **matrix, int M, int col) {
    for (int i = 0; i < M; ++i) {
        matrix[i][col] = 0; // Set each element in the column to zero.
    }
}


/**
 * @brief Prints the contents of a 2D matrix to the console.
 *
 * This function takes a 2D matrix represented by a pointer to a pointer of integers and
 * prints its contents to the console. The matrix dimensions (number of rows and columns)
 * are also passed as arguments to the function.
 *
 * @param matrix A pointer to a pointer of integers representing the matrix.
 * @param M The number of rows in the matrix.
 * @param N The number of columns in the matrix.
 */
void printMatrix(int **matrix, int M, int N) {
    // Loop over each row in the matrix
    for (int i = 0; i < M; ++i) {
        // Loop over each column in the matrix
        for (int j = 0; j < N; ++j) {
            // Print the current element of the matrix followed by two spaces
            std::cout << matrix[i][j] << "  ";
        }
        // Print a newline character after each row is printed
        std::cout << std::endl;
    }
    // Print an additional newline character after the matrix is printed
    std::cout << std::endl;
}


#include <iostream>

// function to print the contents of a matrix
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// function to set all elements of a matrix to zero
void nullifyMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = 0;
        }
    }
}

int main() {
    int M, N;

    // prompt user to enter number of rows and columns
    std::cout << "Enter number of rows:";
    std::cin >> M;
    std::cout << "Enter number of cols:";
    std::cin >> N;

    // create a dynamically allocated 2D array of integers
    int** matrix = new int*[M];
    for (int i = 0; i < M; ++i) {
        matrix[i] = new int[N];
    }

    // prompt user to input elements of matrix
    std::cout << "Provide M x N matrix \n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // print original matrix
    std::cout << "Matrix Before:\n";
    printMatrix(matrix, M, N);

    // set all elements in matrix to zero
    nullifyMatrix(matrix, M, N);

    // print modified matrix
    std::cout << "Matrix After:\n";
    printMatrix(matrix, M, N);

    // free dynamically allocated memory
    for (int i = 0; i < M; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
