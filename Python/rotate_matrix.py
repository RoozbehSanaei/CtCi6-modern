# O(NxN)
import unittest
from copy import deepcopy

def rotate_matrix(matrix):
    """
    Rotates a square matrix 90 degrees clockwise in-place.
    """
    n = len(matrix)  # get length of matrix (number of rows)
    for i in range(n // 2):  # iterate over upper-left quadrant of matrix
        for j in range(i, n - i - 1):
            # swap four elements in matrix, moving them in a clockwise direction
            matrix[i][j], matrix[j][n-i-1], matrix[n-i-1][n-j-1], matrix[n-j-1][i] = (
                matrix[n-j-1][i], matrix[i][j], matrix[j][n-i-1], matrix[n-i-1][n-j-1])
    return matrix  # return modified matrix

def rotate_matrix_double_swap(matrix):
    n = len(matrix)
    
    # Step 1: Transpose the matrix by swapping elements diagonally
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Step 2: Flip the matrix horizontally by swapping elements in each row
    for row in matrix:
        for j in range(n//2):
            ''' 
            ~j is equivalent to -j-1. It represents the index of the second
            element to be swapped, counting from the end of the list instead of 
            the beginning. For example, if j is 2, then ~j is -3.
            '''
            row[j], row[~j] = row[~j], row[j]
            
    # Return the rotated matrix
    return matrix


def rotate_matrix_pythonic(matrix):
    """rotates a matrix 90 degrees clockwise"""

    # Create a new matrix with reversed rows and columns
    # by using a nested list comprehension
    # The outer loop runs for each column of the matrix
    # The inner loop runs for each row of the matrix
    # and takes the elements of the corresponding column
    # in reverse order to create a new row
    new_matrix = [[matrix[j][i] for j in range(len(matrix)-1, -1, -1)] 
                  for i in range(len(matrix))]
    
    # Return the new matrix
    return new_matrix


def rotate_matrix_pythonic_alternate(matrix):
        """rotates a matrix 90 degrees clockwise"""

        # Using zip and the unpacking operator (*) to transpose the matrix
        # and create tuples containing each row of the original matrix.
        # The tuples will later be turned into reversed rows.
        # Example: [[1, 2], [3, 4]] -> [(1, 3), (2, 4)]
        rows = zip(*matrix)

        # Using a list comprehension to create a new list of reversed rows.
        # For each tuple in the 'rows' object, the reversed function is applied
        # to create a new tuple with the order of elements reversed.
        # The resulting tuple is converted back to a list using the list function.
        # Example: (1, 3) -> [3, 1]
        reversed_rows = [list(reversed(row)) for row in rows]

        # The reversed rows are returned as the rotated matrix.
        return reversed_rows



class Test(unittest.TestCase):

    test_cases = [
        ([[1, 2, 3], [4, 5, 6], [7, 8, 9]], [[7, 4, 1], [8, 5, 2], [9, 6, 3]]),
        (
            [
                [1, 2, 3, 4, 5],
                [6, 7, 8, 9, 10],
                [11, 12, 13, 14, 15],
                [16, 17, 18, 19, 20],
                [21, 22, 23, 24, 25],
            ],
            [
                [21, 16, 11, 6, 1],
                [22, 17, 12, 7, 2],
                [23, 18, 13, 8, 3],
                [24, 19, 14, 9, 4],
                [25, 20, 15, 10, 5],
            ],
        ),
    ]
    testable_functions = [
        rotate_matrix_pythonic,
        rotate_matrix,
        rotate_matrix_pythonic_alternate,
        rotate_matrix_double_swap,
    ]

    def test_rotate_matrix(self):
        for f in self.testable_functions:
            for [test_matrix, expected] in self.test_cases:
                test_matrix = deepcopy(test_matrix)
                assert f(test_matrix) == expected


if __name__ == "__main__":
    unittest.main() 