import unittest
from test import *

def check_permutation_by_sort(s1, s2):
    if len(s1) != len(s2):
        return False
    return all(c1 == c2 for c1, c2 in zip(sorted(s1), sorted(s2)))


class Test(unittest.TestCase):
    # str1, str2, is_permutation
    test_cases = (
        ("dog", "god", True),
        ("abcd", "bacd", True),
        ("3563476", "7334566", True),
        ("wef34f", "wffe34", True),
        ("dogx", "godz", False),
        ("abcd", "d2cba", False),
        ("2354", "1234", False),
        ("dcw4f", "dcw5f", False),
        ("DOG", "dog", False),
        ("dog ", "dog", False),
        ("aaab", "bbba", False),
    )

    testable_functions = [
        check_permutation_by_sort    ]

    def test(self):
        calculate_time(self.test_cases,self.testable_functions)


    
if __name__ == "__main__":
    unittest.main()