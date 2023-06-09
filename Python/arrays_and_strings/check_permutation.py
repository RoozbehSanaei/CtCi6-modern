import unittest
from calculate_test_times import calculate_test_times


def check_permutation_by_sort(str1, str2):
    return sorted(str1) == sorted(str2)


class Test(unittest.TestCase):
    # str1, str2, is_permutation
    test_cases = {
        ("dog", "god"): True,
        ("abcd", "bacd"): True,
        ("3563476", "7334566"): True,
        ("wef34f", "wffe34"): True,
        ("dogx", "godz"): False,
        ("abcd", "d2cba"): False,
        ("2354", "1234"): False,
        ("dcw4f", "dcw5f"): False,
        ("DOG", "dog"): False,
        ("dog ", "dog"): False,
        ("aaab", "bbba"): False,
    }



    testable_functions = [
        check_permutation_by_sort    ]

    def test_urlify(self):
        for urlify in self.testable_functions:
            for args, expected in self.test_cases.items():
                assert urlify(*args) == expected, f"Failed {urlify.__name__} for: {[*args]}"


    
if __name__ == "__main__":
    unittest.main()