import unittest
from collections import defaultdict
from calculate_test_times import calculate_test_times


def is_unique_chars_pythonic(string):
    return len(set(string)) == len(string)

class Test(unittest.TestCase):
    # str1, str2, is_permutation
    test_cases = {
        "abcd": True,
        "s4fad": True,
        "": True,
        "23ds2": False,
        "hb 627jh=j ()": False,
        "".join([chr(val) for val in range(128)]): True,  # unique 128 chars
        "".join([chr(val // 2) for val in range(129)]): False,  # non-unique 129 chars
    }
    testable_functions = [
        is_unique_chars_pythonic    ]

    def test_urlify(self):
        for urlify in self.testable_functions:
            for args, expected in self.test_cases.items():
                assert urlify(args) == expected, f"Failed {urlify.__name__} for: {[*args]}"





    
if __name__ == "__main__":
    unittest.main()