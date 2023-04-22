# O(MxN)
import unittest
from copy import deepcopy

def zero_matrix(matrix):
    """
    Given an input matrix, create a new matrix where any row or column containing a zero in the input matrix is set to all zeros in the output matrix.

    Parameters:
    matrix (list of list of int): The input matrix.

    Returns:
    list of list of int: The output matrix with any row or column containing a zero in the input matrix set to all zeros.
    """
    # Create a set of row indices containing at least one zero in the input matrix
    zero_rows = {i for i, row in enumerate(matrix) if 0 in row}
    # Create a set of column indices containing at least one zero in the input matrix
    # When used with the * operator, zip(*matrix) "unzips" the matrix by transposing it.
    # It takes each element of the matrix as a separate argument, effectively passing 
    # the columns of the matrix as separate iterables to zip. The resulting iterator
    # returns tuples of the corresponding elements from each of the input iterables, 
    # effectively returning the rows of the transposed matrix.
    zero_cols = {i for i, col in enumerate(zip(*matrix)) if 0 in col}
    # Create a new matrix where each element is set to zero if its row or column index is in the zero_rows or zero_cols sets
    # Otherwise, the element is kept the same as in the original matrix
    return [[0 if i in zero_rows or j in zero_cols else val for j, val in enumerate(row)] for i, row in enumerate(matrix)]

class Test(unittest.TestCase):

    test_cases = [
        (
            [
                [1, 2, 3, 4, 0],
                [6, 0, 8, 9, 10],
                [11, 12, 13, 14, 15],
                [16, 0, 18, 19, 20],
                [21, 22, 23, 24, 25],
            ],
            [
                [0, 0, 0, 0, 0],
                [0, 0, 0, 0, 0],
                [11, 0, 13, 14, 0],
                [0, 0, 0, 0, 0],
                [21, 0, 23, 24, 0],
            ],
        )
    ]
    testable_functions = [zero_matrix]

    def test_zero_matrix(self):
        for testable_function in self.testable_functions:
            for [test_matrix, expected] in self.test_cases:
                test_matrix = deepcopy(test_matrix)
                assert testable_function(test_matrix) == expected, f"Failed {testable_function.__name__} for: {[test_matrix]}"


if __name__ == "__main__":
    unittest.main()