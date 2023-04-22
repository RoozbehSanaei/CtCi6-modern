# O(MxN)
import unittest
from copy import deepcopy

def zero_matrix(matrix):
    zero_rows = {i for i, row in enumerate(matrix) if 0 in row}
    zero_cols = {i for i, col in enumerate(zip(*matrix)) if 0 in col}
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
        for f in self.testable_functions:
            for [test_matrix, expected] in self.test_cases:
                test_matrix = deepcopy(test_matrix)
                assert f(test_matrix) == expected


if __name__ == "__main__":
    unittest.main()